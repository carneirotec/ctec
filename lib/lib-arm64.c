/*
 *  CTEC runtime library Para arm64.
 *
 *  Copyright (c) 2015 Edmund Grimley Evans
 *
 * Copying and distribution of this file, with or without modification,
 * are permitted in any medium without royalty provided the copyright
 * notice and this notice are preserved.  This file is offered as-is,
 * without any warranty.
 */

#SeDefinido __TINYC__
Tipo ComSinal Caractere int8_t;
Tipo SemSinal Caractere uint8_t;
Tipo Curto int16_t;
Tipo SemSinal Curto uint16_t;
Tipo Inteiro int32_t;
Tipo SemSinal uint32_t;
Tipo Longo Longo int64_t;
Tipo SemSinal Longo Longo uint64_t;
Vazio *memcpy(Vazio*,Vazio*,__SIZE_TYPE__);
#Senão
#Inclua <stdint.h>
#Inclua <string.h>
#FimSe

Vazio __clear_cache(Vazio *beg, Vazio *end)
{
    __arm64_clear_cache(beg, end);
}

Tipo Estrutura {
    uint64_t x0, x1;
} u128_t;

Estático Longo Duplo f3_zero(Inteiro sgn)
{
    Longo Duplo f;
    u128_t x = { 0, (uint64_t)sgn << 63 };
    memcpy(&f, &x, 16);
    Retorno f;
}

Estático Longo Duplo f3_infinity(Inteiro sgn)
{
    Longo Duplo f;
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    memcpy(&f, &x, 16);
    Retorno f;
}

Estático Longo Duplo f3_NaN(Vazio)
{
    Longo Duplo f;
#Se 0
    // ARM's Padrão NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#Senão
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#FimSe
    memcpy(&f, &x, 16);
    Retorno f;
}

Estático Inteiro fp3_convert_NaN(Longo Duplo *f, Inteiro sgn, u128_t mnt)
{
    u128_t x = { mnt.x0,
                 mnt.x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    memcpy(f, &x, 16);
    Retorno 1;
}

Estático Inteiro fp3_detect_NaNs(Longo Duplo *f,
                           Inteiro a_sgn, Inteiro a_exp, u128_t a,
                           Inteiro b_sgn, Inteiro b_exp, u128_t b)
{
    // Detect signalling NaNs:
    Se (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        Retorno fp3_convert_NaN(f, a_sgn, a);
    Se (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        Retorno fp3_convert_NaN(f, b_sgn, b);

    // Detect quiet NaNs:
    Se (a_exp == 32767 && (a.x0 | a.x1 << 16))
        Retorno fp3_convert_NaN(f, a_sgn, a);
    Se (b_exp == 32767 && (b.x0 | b.x1 << 16))
        Retorno fp3_convert_NaN(f, b_sgn, b);

    Retorno 0;
}

Estático Vazio f3_unpack(Inteiro *sgn, int32_t *exp, u128_t *mnt, Longo Duplo f)
{
    u128_t x;
    memcpy(&x, &f, 16);
    *sgn = x.x1 >> 63;
    *exp = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    Se (*exp)
        x.x1 |= (uint64_t)1 << 48;
    Senão
        *exp = 1;
    *mnt = x;
}

Estático u128_t f3_normalise(int32_t *exp, u128_t mnt)
{
    Inteiro sh;
    Se (!(mnt.x0 | mnt.x1))
        Retorno mnt;
    Se (!mnt.x1) {
        mnt.x1 = mnt.x0;
        mnt.x0 = 0;
        *exp -= 64;
    }
    Para (sh = 32; sh; sh >>= 1) {
        Se (!(mnt.x1 >> (64 - sh))) {
            mnt.x1 = mnt.x1 << sh | mnt.x0 >> (64 - sh);
            mnt.x0 = mnt.x0 << sh;
            *exp -= sh;
        }
    }
    Retorno mnt;
}

Estático u128_t f3_sticky_shift(int32_t sh, u128_t x)
{
  Se (sh >= 128) {
      x.x0 = !!(x.x0 | x.x1);
      x.x1 = 0;
      Retorno x;
  }
  Se (sh >= 64) {
      x.x0 = x.x1 | !!x.x0;
      x.x1 = 0;
      sh -= 64;
  }
  Se (sh > 0) {
      x.x0 = x.x0 >> sh | x.x1 << (64 - sh) | !!(x.x0 << (64 - sh));
      x.x1 = x.x1 >> sh;
  }
  Retorno x;
}

Estático Longo Duplo f3_round(Inteiro sgn, int32_t exp, u128_t x)
{
    Longo Duplo f;
    Inteiro Erro;

    Se (exp > 0) {
        x = f3_sticky_shift(13, x);
    }
    Senão {
        x = f3_sticky_shift(14 - exp, x);
        exp = 0;
    }

    Erro = x.x0 & 3;
    x.x0 = x.x0 >> 2 | x.x1 << 62;
    x.x1 = x.x1 >> 2;

    Se (Erro == 3 || ((Erro == 2) & (x.x0 & 1))) {
        Se (!++x.x0) {
            ++x.x1;
            Se (x.x1 == (uint64_t)1 << 48)
                exp = 1;
            Senão Se (x.x1 == (uint64_t)1 << 49) {
                ++exp;
                x.x0 = x.x0 >> 1 | x.x1 << 63;
                x.x1 = x.x1 >> 1;
            }
        }
    }

    Se (exp >= 32767)
        Retorno f3_infinity(sgn);

    x.x1 = x.x1 << 16 >> 16 | (uint64_t)exp << 48 | (uint64_t)sgn << 63;
    memcpy(&f, &x, 16);
    Retorno f;
}

Estático Longo Duplo f3_add(Longo Duplo fa, Longo Duplo fb, Inteiro neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    Inteiro a_sgn, b_sgn, x_sgn;
    Longo Duplo fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    Se (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        Retorno fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    Se (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        Retorno f3_NaN();
    Se (a_exp == 32767)
        Retorno f3_infinity(a_sgn);
    Se (b_exp == 32767)
        Retorno f3_infinity(b_sgn);
    Se (!(a.x0 | a.x1 | b.x0 | b.x1))
        Retorno f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    Se (a_exp <= b_exp) {
        a = f3_sticky_shift(b_exp - a_exp, a);
        a_exp = b_exp;
    }
    Senão {
        b = f3_sticky_shift(a_exp - b_exp, b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    Se (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    Senão {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        Se (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    Se (!(x.x0 | x.x1))
        Retorno f3_zero(0);

    x = f3_normalise(&x_exp, x);

    Retorno f3_round(x_sgn, x_exp + 12, x);
}

Longo Duplo __addtf3(Longo Duplo a, Longo Duplo b)
{
    Retorno f3_add(a, b, 0);
}

Longo Duplo __subtf3(Longo Duplo a, Longo Duplo b)
{
    Retorno f3_add(a, b, 1);
}

Longo Duplo __multf3(Longo Duplo fa, Longo Duplo fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    Inteiro a_sgn, b_sgn, x_sgn;
    Longo Duplo fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    Se (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        Retorno fx;

    // Handle infinities and zeroes:
    Se ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        Retorno f3_NaN();
    Se (a_exp == 32767 || b_exp == 32767)
        Retorno f3_infinity(a_sgn ^ b_sgn);
    Se (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        Retorno f3_zero(a_sgn ^ b_sgn);

    a = f3_normalise(&a_exp, a);
    b = f3_normalise(&b_exp, b);

    x_sgn = a_sgn ^ b_sgn;
    x_exp = a_exp + b_exp - 16352;

    {
        // Convert to base (1 << 30), discarding bottom 6 bits, which are zero,
        // so there are (32, 30, 30, 30) bits in (a3, a2, a1, a0):
        uint64_t a0 = a.x0 << 28 >> 34;
        uint64_t b0 = b.x0 << 28 >> 34;
        uint64_t a1 = a.x0 >> 36 | a.x1 << 62 >> 34;
        uint64_t b1 = b.x0 >> 36 | b.x1 << 62 >> 34;
        uint64_t a2 = a.x1 << 32 >> 34;
        uint64_t b2 = b.x1 << 32 >> 34;
        uint64_t a3 = a.x1 >> 32;
        uint64_t b3 = b.x1 >> 32;
        // Use 16 small multiplications and additions that Faça not overflow:
        uint64_t x0 = a0 * b0;
        uint64_t x1 = (x0 >> 30) + a0 * b1 + a1 * b0;
        uint64_t x2 = (x1 >> 30) + a0 * b2 + a1 * b1 + a2 * b0;
        uint64_t x3 = (x2 >> 30) + a0 * b3 + a1 * b2 + a2 * b1 + a3 * b0;
        uint64_t x4 = (x3 >> 30) + a1 * b3 + a2 * b2 + a3 * b1;
        uint64_t x5 = (x4 >> 30) + a2 * b3 + a3 * b2;
        uint64_t x6 = (x5 >> 30) + a3 * b3;
        // We now have (64, 30, 30, ...) bits in (x6, x5, x4, ...).
        // Take the top 128 bits, setting bottom bit Se any lower bits were set:
        uint64_t y0 = (x5 << 34 | x4 << 34 >> 30 | x3 << 34 >> 60 |
                       !!(x3 << 38 | (x2 | x1 | x0) << 34));
        uint64_t y1 = x6;
        // Top bit may be zero. Renormalise:
        Se (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    Retorno f3_round(x_sgn, x_exp, x);
}

Longo Duplo __divtf3(Longo Duplo fa, Longo Duplo fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    Inteiro a_sgn, b_sgn, x_sgn, i;
    Longo Duplo fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    Se (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        Retorno fx;

    // Handle infinities and zeroes:
    Se ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        Retorno f3_NaN();
    Se (a_exp == 32767 || !(b.x0 | b.x1))
        Retorno f3_infinity(a_sgn ^ b_sgn);
    Se (!(a.x0 | a.x1) || b_exp == 32767)
        Retorno f3_zero(a_sgn ^ b_sgn);

    a = f3_normalise(&a_exp, a);
    b = f3_normalise(&b_exp, b);

    x_sgn = a_sgn ^ b_sgn;
    x_exp = a_exp - b_exp + 16395;

    a.x0 = a.x0 >> 1 | a.x1 << 63;
    a.x1 = a.x1 >> 1;
    b.x0 = b.x0 >> 1 | b.x1 << 63;
    b.x1 = b.x1 >> 1;
    x.x0 = 0;
    x.x1 = 0;
    Para (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        Se (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    x = f3_normalise(&x_exp, x);

    Retorno f3_round(x_sgn, x_exp, x);
}

Longo Duplo __extendsftf2(Real f)
{
    Longo Duplo fx;
    u128_t x;
    uint32_t a;
    uint64_t aa;
    memcpy(&a, &f, 4);
    aa = a;
    x.x0 = 0;
    Se (!(a << 1))
        x.x1 = aa << 32;
    Senão Se (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    Senão
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    memcpy(&fx, &x, 16);
    Retorno fx;
}

Longo Duplo __extenddftf2(Duplo f)
{
    Longo Duplo fx;
    u128_t x;
    uint64_t a;
    memcpy(&a, &f, 8);
    x.x0 = a << 60;
    Se (!(a << 1))
        x.x1 = a;
    Senão Se (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    Senão
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    memcpy(&fx, &x, 16);
    Retorno fx;
}

Real __trunctfsf2(Longo Duplo f)
{
    u128_t mnt;
    int32_t exp;
    Inteiro sgn;
    uint32_t x;
    Real fx;

    f3_unpack(&sgn, &exp, &mnt, f);

    Se (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    Senão Se (exp > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    Senão Se (exp < 16233)
        x = (uint32_t)sgn << 31;
    Senão {
        exp -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        Se (exp < 0) {
            x = x >> -exp | !!(x << (32 + exp));
            exp = 0;
        }
        Se ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (exp << 23)) | (uint32_t)sgn << 31;
    }
    memcpy(&fx, &x, 4);
    Retorno fx;
}

Duplo __trunctfdf2(Longo Duplo f)
{
    u128_t mnt;
    int32_t exp;
    Inteiro sgn;
    uint64_t x;
    Duplo fx;

    f3_unpack(&sgn, &exp, &mnt, f);

    Se (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    Senão Se (exp > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    Senão Se (exp < 15308)
        x = (uint64_t)sgn << 63;
    Senão {
        exp -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        Se (exp < 0) {
            x = x >> -exp | !!(x << (64 + exp));
            exp = 0;
        }
        Se ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)exp << 52)) | (uint64_t)sgn << 63;
    }
    memcpy(&fx, &x, 8);
    Retorno fx;
}

int32_t __fixtfsi(Longo Duplo fa)
{
    u128_t a;
    int32_t a_exp;
    Inteiro a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    Se (a_exp < 16369)
        Retorno 0;
    Se (a_exp > 16413)
        Retorno a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    Retorno a_sgn ? -x : x;
}

int64_t __fixtfdi(Longo Duplo fa)
{
    u128_t a;
    int32_t a_exp;
    Inteiro a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    Se (a_exp < 16383)
        Retorno 0;
    Se (a_exp > 16445)
        Retorno a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    Retorno a_sgn ? -x : x;
}

uint32_t __fixunstfsi(Longo Duplo fa)
{
    u128_t a;
    int32_t a_exp;
    Inteiro a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    Se (a_sgn || a_exp < 16369)
        Retorno 0;
    Se (a_exp > 16414)
        Retorno -1;
    Retorno a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(Longo Duplo fa)
{
    u128_t a;
    int32_t a_exp;
    Inteiro a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    Se (a_sgn || a_exp < 16383)
        Retorno 0;
    Se (a_exp > 16446)
        Retorno -1;
    Retorno (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

Longo Duplo __floatsitf(int32_t a)
{
    Inteiro sgn = 0;
    Inteiro exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    Longo Duplo f;
    Inteiro i;
    Se (a) {
        Se (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        Para (i = 16; i; i >>= 1)
            Se (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)exp << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    memcpy(&f, &x, 16);
    Retorno f;
}

Longo Duplo __floatditf(int64_t a)
{
    Inteiro sgn = 0;
    Inteiro exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    Longo Duplo f;
    Inteiro i;
    Se (a) {
        Se (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        Para (i = 32; i; i >>= 1)
            Se (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    memcpy(&f, &x, 16);
    Retorno f;
}

Longo Duplo __floatunsitf(uint32_t a)
{
    Inteiro exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    Longo Duplo f;
    Inteiro i;
    Se (a) {
        Para (i = 16; i; i >>= 1)
            Se (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = (uint64_t)exp << 48 | (uint64_t)(mnt << 1) << 16;
    }
    memcpy(&f, &x, 16);
    Retorno f;
}

Longo Duplo __floatunditf(uint64_t a)
{
    Inteiro exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    Longo Duplo f;
    Inteiro i;
    Se (a) {
        Para (i = 32; i; i >>= 1)
            Se (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    memcpy(&f, &x, 16);
    Retorno f;
}

Estático Inteiro f3_cmp(Longo Duplo fa, Longo Duplo fb)
{
    u128_t a, b;
    memcpy(&a, &fa, 16);
    memcpy(&b, &fb, 16);
    Retorno (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (Inteiro)(b.x1 >> 63) - (Inteiro)(a.x1 >> 63) :
            a.x1 < b.x1 ? (Inteiro)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (Inteiro)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (Inteiro)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (Inteiro)(a.x1 >> 63 << 1) : 0);
}

Inteiro __eqtf2(Longo Duplo a, Longo Duplo b)
{
    Retorno !!f3_cmp(a, b);
}

Inteiro __netf2(Longo Duplo a, Longo Duplo b)
{
    Retorno !!f3_cmp(a, b);
}

Inteiro __lttf2(Longo Duplo a, Longo Duplo b)
{
    Retorno f3_cmp(a, b);
}

Inteiro __letf2(Longo Duplo a, Longo Duplo b)
{
    Retorno f3_cmp(a, b);
}

Inteiro __gttf2(Longo Duplo a, Longo Duplo b)
{
    Retorno -f3_cmp(b, a);
}

Inteiro __getf2(Longo Duplo a, Longo Duplo b)
{
    Retorno -f3_cmp(b, a);
}
