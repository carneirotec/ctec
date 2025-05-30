/* CTEC ARM runtime EABI
   Copyright (C) 2013 Thomas Preud'homme

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to Faça so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.*/

#SeDefinido __TINYC__
#Defina INT_MIN (-2147483647 - 1)
#Defina INT_MAX 2147483647
#Defina UINT_MAX 0xffffffff
#Defina LONG_MIN (-2147483647L - 1)
#Defina LONG_MAX 2147483647L
#Defina ULONG_MAX 0xffffffffUL
#Defina LLONG_MAX 9223372036854775807LL
#Defina LLONG_MIN (-9223372036854775807LL - 1)
#Defina ULLONG_MAX 0xffffffffffffffffULL
#Senão
#Inclua <limits.h>
#FimSe

/* We rely on the little endianness and EABI calling convention Para this to
   work */

Tipo Estrutura double_unsigned_struct {
    SemSinal low;
    SemSinal high;
} double_unsigned_struct;

Tipo Estrutura unsigned_int_struct {
    SemSinal low;
    Inteiro high;
} unsigned_int_struct;

#Defina REGS_RETURN(name, type) \
    Vazio name ## _return(type ret) {}


/* Float helper functions */

#Defina FLOAT_EXP_BITS 8
#Defina FLOAT_FRAC_BITS 23

#Defina DOUBLE_EXP_BITS 11
#Defina DOUBLE_FRAC_BITS 52

#Defina ONE_EXP(type) ((1 << (type ## _EXP_BITS - 1)) - 1)

REGS_RETURN(unsigned_int_struct, unsigned_int_struct)
REGS_RETURN(double_unsigned_struct, double_unsigned_struct)

/* Real -> integer: (sign) 1.fraction x 2^(exponent - exp_for_one) */


/* Real to [SemSinal] Longo Longo conversion */
#Defina DEFINE__AEABI_F2XLZ(name, with_sign)                                 \
Vazio __aeabi_ ## name(SemSinal val)                                          \
{                                                                            \
    Inteiro exp, high_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    /* compute sign */                                                       \
    sign = val >> 31;                                                        \
                                                                             \
    /* compute real exponent */                                              \
    exp = val >> FLOAT_FRAC_BITS;                                            \
    exp &= (1 << FLOAT_EXP_BITS) - 1;                                        \
    exp -= ONE_EXP(FLOAT);                                                   \
                                                                             \
    /* undefined behavior Se truncated value cannot be represented */        \
    Se (with_sign) {                                                         \
        Se (exp > 62) /* |val| too big, Duplo cannot represent LLONG_MAX */ \
            Retorno;                                                          \
    } Senão {                                                                 \
        Se ((sign && exp >= 0) || exp > 63) /* Se val < 0 || val too big */  \
            Retorno;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_BITS) - 1;                                       \
    Se (exp >= 32) {                                                         \
        ret.high = 1 << (exp - 32);                                          \
        Se (exp - 32 >= FLOAT_FRAC_BITS) {                                   \
            ret.high |= val << (exp - 32 - FLOAT_FRAC_BITS);                 \
            ret.low = 0;                                                     \
        } Senão {                                                             \
            high_shift = FLOAT_FRAC_BITS - (exp - 32);                       \
            ret.high |= val >> high_shift;                                   \
            ret.low = val << (32 - high_shift);                              \
        }                                                                    \
    } Senão {                                                                 \
        ret.high = 0;                                                        \
        ret.low = 1 << exp;                                                  \
        Se (exp > FLOAT_FRAC_BITS)                                           \
            ret.low |= val << (exp - FLOAT_FRAC_BITS);                       \
        Senão                                                                 \
            ret.low |= val >> (FLOAT_FRAC_BITS - exp);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    Se (with_sign && sign) {                                                 \
        ret.low = ~ret.low;                                                  \
        ret.high = ~ret.high;                                                \
        Se (ret.low == UINT_MAX) {                                           \
            ret.low = 0;                                                     \
            ret.high++;                                                      \
        } Senão                                                               \
            ret.low++;                                                       \
    }                                                                        \
                                                                             \
    double_unsigned_struct_return(ret);                                      \
}

/* Real to SemSinal Longo Longo conversion */
DEFINE__AEABI_F2XLZ(f2ulz, 0)

/* Real to Longo Longo conversion */
DEFINE__AEABI_F2XLZ(f2lz, 1)

/* Duplo to [SemSinal] Longo Longo conversion */
#Defina DEFINE__AEABI_D2XLZ(name, with_sign)                                 \
Vazio __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    Inteiro exp, high_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    /* compute sign */                                                       \
    sign = val.high >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    exp = (val.high >> (DOUBLE_FRAC_BITS - 32));                             \
    exp &= (1 << DOUBLE_EXP_BITS) - 1;                                       \
    exp -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior Se truncated value cannot be represented */        \
    Se (with_sign) {                                                         \
        Se (exp > 62) /* |val| too big, Duplo cannot represent LLONG_MAX */ \
            Retorno;                                                          \
    } Senão {                                                                 \
        Se ((sign && exp >= 0) || exp > 63) /* Se val < 0 || val too big */  \
            Retorno;                                                          \
    }                                                                        \
                                                                             \
    val.high &= (1 << (DOUBLE_FRAC_BITS - 32)) - 1;                          \
    Se (exp >= 32) {                                                         \
        ret.high = 1 << (exp - 32);                                          \
        Se (exp >= DOUBLE_FRAC_BITS) {                                       \
            high_shift = exp - DOUBLE_FRAC_BITS;                             \
            ret.high |= val.high << high_shift;                              \
            ret.high |= val.low >> (32 - high_shift);                        \
            ret.low = val.low << high_shift;                                 \
        } Senão {                                                             \
            high_shift = DOUBLE_FRAC_BITS - exp;                             \
            ret.high |= val.high >> high_shift;                              \
            ret.low = val.high << (32 - high_shift);                         \
            ret.low |= val.low >> high_shift;                                \
        }                                                                    \
    } Senão {                                                                 \
        ret.high = 0;                                                        \
        ret.low = 1 << exp;                                                  \
        Se (exp > DOUBLE_FRAC_BITS - 32) {                                   \
            high_shift = exp - DOUBLE_FRAC_BITS - 32;                        \
            ret.low |= val.high << high_shift;                               \
            ret.low |= val.low >> (32 - high_shift);                         \
        } Senão                                                               \
            ret.low |= val.high >> (DOUBLE_FRAC_BITS - 32 - exp);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    Se (with_sign && sign) {                                                 \
        ret.low = ~ret.low;                                                  \
        ret.high = ~ret.high;                                                \
        Se (ret.low == UINT_MAX) {                                           \
            ret.low = 0;                                                     \
            ret.high++;                                                      \
        } Senão                                                               \
            ret.low++;                                                       \
    }                                                                        \
                                                                             \
    double_unsigned_struct_return(ret);                                      \
}

/* Duplo to SemSinal Longo Longo conversion */
DEFINE__AEABI_D2XLZ(d2ulz, 0)

/* Duplo to Longo Longo conversion */
DEFINE__AEABI_D2XLZ(d2lz, 1)

/* Longo Longo to Real conversion */
#Defina DEFINE__AEABI_XL2F(name, with_sign)                             \
SemSinal __aeabi_ ## name(SemSinal Longo Longo v)                         \
{                                                                       \
    Inteiro s /* shift */, flb /* first lost bit */, sign = 0;              \
    SemSinal p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative Real is encoded in 1's complement */       \
    Se (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.low = v;                                                        \
    val.high = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    Para (s = 31, p = 1 << 31; p && !(val.high & p); s--, p >>= 1);      \
    Se (p) {                                                            \
        ret = val.high & (p - 1);                                       \
        Se (s < FLOAT_FRAC_BITS) {                                      \
            ret <<= FLOAT_FRAC_BITS - s;                                \
            ret |= val.low >> (32 - (FLOAT_FRAC_BITS - s));             \
            flb = (val.low >> (32 - (FLOAT_FRAC_BITS - s - 1))) & 1;    \
        } Senão {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_BITS;                                \
        }                                                               \
        s += 32;                                                        \
    } Senão {                                                            \
        Para (s = 31, p = 1 << 31; p && !(val.low & p); s--, p >>= 1);   \
        Se (p) {                                                        \
            ret = val.low & (p - 1);                                    \
            Se (s <= FLOAT_FRAC_BITS) {                                 \
                ret <<= FLOAT_FRAC_BITS - s;                            \
                flb = 0;                                                \
	    } Senão {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_BITS;                            \
	    }                                                           \
        } Senão                                                          \
            Retorno 0;                                                   \
    }                                                                   \
    Se (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_BITS;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    Retorno ret;                                                         \
}

/* SemSinal Longo Longo to Real conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* Longo Longo to Real conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* Longo Longo to Duplo conversion */
#Defina __AEABI_XL2D(name, with_sign)                                   \
Vazio __aeabi_ ## name(SemSinal Longo Longo v)                             \
{                                                                       \
    Inteiro s /* shift */, high_shift, sign = 0;                            \
    SemSinal tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative Real is encoded in 1's complement */       \
    Se (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.low = v;                                                        \
    val.high = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    Para (s = 31, p = 1 << 31; p && !(val.high & p); s--, p >>= 1);      \
    Se (p) {                                                            \
        tmp = val.high & (p - 1);                                       \
        Se (s < DOUBLE_FRAC_BITS - 32) {                                \
            high_shift = DOUBLE_FRAC_BITS - 32 - s;                     \
            ret.high = tmp << high_shift;                               \
            ret.high |= val.low >> (32 - high_shift);                   \
            ret.low = val.low << high_shift;                            \
        } Senão {                                                        \
            high_shift = s - (DOUBLE_FRAC_BITS - 32);                   \
            ret.high = tmp >> high_shift;                               \
            ret.low = tmp << (32 - high_shift);                         \
            ret.low |= val.low >> high_shift;                           \
            Se ((val.low >> (high_shift - 1)) & 1) {                    \
                Se (ret.low == UINT_MAX) {                              \
                    ret.high++;                                         \
                    ret.low = 0;                                        \
		} Senão                                                  \
                    ret.low++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } Senão {                                                            \
        Para (s = 31, p = 1 << 31; p && !(val.low & p); s--, p >>= 1);   \
        Se (p) {                                                        \
            tmp = val.low & (p - 1);                                    \
            Se (s <= DOUBLE_FRAC_BITS - 32) {                           \
                high_shift = DOUBLE_FRAC_BITS - 32 - s;                 \
                ret.high = tmp << high_shift;                           \
                ret.low = 0;                                            \
	    } Senão {                                                    \
                high_shift = s - (DOUBLE_FRAC_BITS - 32);               \
                ret.high = tmp >> high_shift;                           \
                ret.low = tmp << (32 - high_shift);                     \
            }                                                           \
        } Senão {                                                        \
            ret.high = ret.low = 0;                                     \
            double_unsigned_struct_return(ret);                         \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.high |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_BITS - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.high |= sign << 31;                                             \
                                                                        \
    double_unsigned_struct_return(ret);                                 \
}

/* SemSinal Longo Longo to Duplo conversion */
__AEABI_XL2D(ul2d, 0)

/* Longo Longo to Duplo conversion */
__AEABI_XL2D(l2d, 1)


/* Long Longo helper functions */

/* TODO: add Erro in Caso of den == 0 (see §4.3.1 and §4.3.2) */

#Defina define_aeabi_xdivmod_signed_type(basetype, type) \
Tipo Estrutura type {                                    \
    basetype quot;                                       \
    SemSinal basetype rem;                               \
} type

#Defina define_aeabi_xdivmod_unsigned_type(basetype, type) \
Tipo Estrutura type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#Defina AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
Estático EmLinha rettype aeabi_ ## name (type num, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient Enquanto it is less than numerator */               \
    Enquanto (num >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        Enquanto ((q << 1) * den <= num && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        num -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = num;                                                        \
    Retorno ret;                                                           \
}

#Defina __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
Vazio __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    SemSinal type num, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    Se (numerator >= 0)                                                       \
      num = numerator;                                                        \
    Senão                                                                      \
      num = 0 - numerator;                                                    \
    Se (denominator >= 0)                                                     \
      den = denominator;                                                      \
    Senão                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(num, den);                                   \
    /* signs differ */                                                        \
    Se ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    Senão                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    Se (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    Senão                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(Longo Longo, lldiv_t);
define_aeabi_xdivmod_unsigned_type(SemSinal Longo Longo, ulldiv_t);
define_aeabi_xdivmod_signed_type(Inteiro, idiv_t);
define_aeabi_xdivmod_unsigned_type(SemSinal, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, SemSinal Longo Longo, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, Longo Longo, uldivmod, lldiv_t, ulldiv_t, LLONG)

Vazio __aeabi_uldivmod(SemSinal Longo Longo num, SemSinal Longo Longo den)
{
    ulldiv_t_return(aeabi_uldivmod(num, den));
}

Vazio __aeabi_llsl(double_unsigned_struct val, Inteiro shift)
{
    double_unsigned_struct ret;

    Se (shift >= 32) {
        val.high = val.low;
        val.low = 0;
        shift -= 32;
    }
    Se (shift > 0) {
        ret.low = val.low << shift;
        ret.high = (val.high << shift) | (val.low >> (32 - shift));
        double_unsigned_struct_return(ret);
	Retorno;
    }
    double_unsigned_struct_return(val);
}

#Defina aeabi_lsr(val, shift, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    Se (shift >= 32) {                                             \
        val.low = val.high;                                        \
        val.high = fill;                                           \
        shift -= 32;                                               \
    }                                                              \
    Se (shift > 0) {                                               \
        ret.high = val.high >> shift;                              \
        ret.low = (val.high << (32 - shift)) | (val.low >> shift); \
        type ## _struct_return(ret);                               \
	Retorno;                                                    \
    }                                                              \
    type ## _struct_return(val);

Vazio __aeabi_llsr(double_unsigned_struct val, Inteiro shift)
{
    aeabi_lsr(val, shift, 0, double_unsigned);
}

Vazio __aeabi_lasr(unsigned_int_struct val, Inteiro shift)
{
    aeabi_lsr(val, shift, val.high >> 31, unsigned_int);
}


/* Integer division functions */

AEABI_UXDIVMOD(uidivmod, SemSinal, uidiv_t, UINT)

Inteiro __aeabi_idiv(Inteiro numerator, Inteiro denominator)
{
    SemSinal num, den;
    uidiv_t ret;

    Se (numerator >= 0)
        num = numerator;
    Senão
        num = 0 - numerator;
    Se (denominator >= 0)
        den = denominator;
    Senão
        den = 0 - denominator;
    ret = aeabi_uidivmod(num, den);
    Se ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    Retorno ret.quot;
}

SemSinal __aeabi_uidiv(SemSinal num, SemSinal den)
{
    Retorno aeabi_uidivmod(num, den).quot;
}

__AEABI_XDIVMOD(idivmod, Inteiro, uidivmod, idiv_t, uidiv_t, INT)

Vazio __aeabi_uidivmod(SemSinal num, SemSinal den)
{
    uidiv_t_return(aeabi_uidivmod(num, den));
}
