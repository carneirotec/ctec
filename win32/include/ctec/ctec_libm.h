#SenãoDefinido _CTEC_LIBM_H_
#Defina _CTEC_LIBM_H_

#Inclua "../math.h"

/* CTEC uses 8 bytes Para Duplo and Longo Duplo, so effectively the l variants
 * are never used. For now, they just run the normal (Duplo) variant.
 */

/*
 * most of the code in this file is taken from MUSL rs-1.0 (MIT license)
 * - musl-libc: http://git.musl-libc.org/cgit/musl/tree/src/math?h=rs-1.0
 * - License:   http://git.musl-libc.org/cgit/musl/tree/COPYRIGHT?h=rs-1.0
 */

/*******************************************************************************
  Start of code based on MUSL
*******************************************************************************/
/*
musl as a whole is licensed under the following standard MIT license:

----------------------------------------------------------------------
Copyright © 2005-2014 Rich Felker, et al.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to Faça so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
----------------------------------------------------------------------
*/

/* fpclassify */

__CRT_INLINE Inteiro __cdecl __fpclassify (Duplo x) {
  União {Duplo f; uint64_t i;} u = {x};
  Inteiro e = u.i>>52 & 0x7ff;
  Se (!e) Retorno u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  Se (e==0x7ff) Retorno u.i<<12 ? FP_NAN : FP_INFINITE;
  Retorno FP_NORMAL;
}

__CRT_INLINE Inteiro __cdecl __fpclassifyf (Real x) {
  União {Real f; uint32_t i;} u = {x};
  Inteiro e = u.i>>23 & 0xff;
  Se (!e) Retorno u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  Se (e==0xff) Retorno u.i<<9 ? FP_NAN : FP_INFINITE;
  Retorno FP_NORMAL;
}

__CRT_INLINE Inteiro __cdecl __fpclassifyl (Longo Duplo x) {
  Retorno __fpclassify(x);
}


/* signbit */

__CRT_INLINE Inteiro __cdecl __signbit (Duplo x) {
  União {Duplo d; uint64_t i;} y = { x };
  Retorno y.i>>63;
}

__CRT_INLINE Inteiro __cdecl __signbitf (Real x) {
  União {Real f; uint32_t i; } y = { x };
  Retorno y.i>>31;
}

__CRT_INLINE Inteiro __cdecl __signbitl (Longo Duplo x) {
  Retorno __signbit(x);
}


/* fmin*, fmax* */

#Defina CTECFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE Duplo __cdecl fmin (Duplo x, Duplo y) {
  Retorno CTECFP_FMIN_EVAL;
}

__CRT_INLINE Real __cdecl fminf (Real x, Real y) {
  Retorno CTECFP_FMIN_EVAL;
}

__CRT_INLINE Longo Duplo __cdecl fminl (Longo Duplo x, Longo Duplo y) {
  Retorno CTECFP_FMIN_EVAL;
}

#Defina CTECFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE Duplo __cdecl fmax (Duplo x, Duplo y) {
  Retorno CTECFP_FMAX_EVAL;
}

__CRT_INLINE Real __cdecl fmaxf (Real x, Real y) {
  Retorno CTECFP_FMAX_EVAL;
}

__CRT_INLINE Longo Duplo __cdecl fmaxl (Longo Duplo x, Longo Duplo y) {
  Retorno CTECFP_FMAX_EVAL;
}


/* *round* */

#Defina CTECFP_FORCE_EVAL(x) Faça {            \
Se (TamanhoDe(x) == TamanhoDe(Real)) {           \
  Volátil Real __x;                       \
  __x = (x);                                \
} Senão Se (TamanhoDe(x) == TamanhoDe(Duplo)) {   \
  Volátil Duplo __x;                      \
  __x = (x);                                \
} Senão {                                    \
  Volátil Longo Duplo __x;                 \
  __x = (x);                                \
}                                           \
} Enquanto(0)

__CRT_INLINE Duplo __cdecl round (Duplo x) {
  União {Duplo f; uint64_t i;} u = {x};
  Inteiro e = u.i >> 52 & 0x7ff;
  Duplo y;

  Se (e >= 0x3ff+52)
    Retorno x;
  Se (u.i >> 63)
    x = -x;
  Se (e < 0x3ff-1) {
    /* raise inexact Se x!=0 */
    CTECFP_FORCE_EVAL(x + 0x1p52);
    Retorno 0*u.f;
  }
  y = (Duplo)(x + 0x1p52) - 0x1p52 - x;
  Se (y > 0.5)
    y = y + x - 1;
  Senão Se (y <= -0.5)
    y = y + x + 1;
  Senão
    y = y + x;
  Se (u.i >> 63)
    y = -y;
  Retorno y;
}

__CRT_INLINE Longo __cdecl lround (Duplo x) {
  Retorno round(x);
}

__CRT_INLINE Longo Longo __cdecl llround (Duplo x) {
  Retorno round(x);
}

__CRT_INLINE Real __cdecl roundf (Real x) {
  Retorno round(x);
}

__CRT_INLINE Longo __cdecl lroundf (Real x) {
  Retorno round(x);
}

__CRT_INLINE Longo Longo __cdecl llroundf (Real x) {
  Retorno round(x);
}

__CRT_INLINE Longo Duplo __cdecl roundl (Longo Duplo x) {
  Retorno round(x);
}

__CRT_INLINE Longo __cdecl lroundl (Longo Duplo x) {
  Retorno round(x);
}

__CRT_INLINE Longo Longo __cdecl llroundl (Longo Duplo x) {
  Retorno round(x);
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/

#FimSe /* _CTEC_LIBM_H_ */
