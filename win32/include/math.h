/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _MATH_H_
#Defina _MATH_H_

#Se __GNUC__ >= 3
#Diretiva GCC system_header
#FimSe

#Inclua <_mingw.h>

Estrutura exception;

#Diretiva pack(push,_CRT_PACKING)

#Defina _DOMAIN 1
#Defina _SING 2
#Defina _OVERFLOW 3
#Defina _UNDERFLOW 4
#Defina _TLOSS 5
#Defina _PLOSS 6

#SenãoDefinido __STRICT_ANSI__
#SenãoDefinido	NO_OLDNAMES
#Defina DOMAIN _DOMAIN
#Defina SING _SING
#Defina OVERFLOW _OVERFLOW
#Defina UNDERFLOW _UNDERFLOW
#Defina TLOSS _TLOSS
#Defina PLOSS _PLOSS
#FimSe
#FimSe

#SenãoDefinido __STRICT_ANSI__
#Defina M_E 2.71828182845904523536
#Defina M_LOG2E 1.44269504088896340736
#Defina M_LOG10E 0.434294481903251827651
#Defina M_LN2 0.693147180559945309417
#Defina M_LN10 2.30258509299404568402
#Defina M_PI 3.14159265358979323846
#Defina M_PI_2 1.57079632679489661923
#Defina M_PI_4 0.785398163397448309616
#Defina M_1_PI 0.318309886183790671538
#Defina M_2_PI 0.636619772367581343076
#Defina M_2_SQRTPI 1.12837916709551257390
#Defina M_SQRT2 1.41421356237309504880
#Defina M_SQRT1_2 0.707106781186547524401
#FimSe

#SenãoDefinido __STRICT_ANSI__
/* See also Real.h  */
#SenãoDefinido __MINGW_FPCLASS_DEFINED
#Defina __MINGW_FPCLASS_DEFINED 1
#Defina	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#Defina	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#Defina	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#Defina	_FPCLASS_NN	0x0008	/* Negative Normal */
#Defina	_FPCLASS_ND	0x0010	/* Negative Denormal */
#Defina	_FPCLASS_NZ	0x0020	/* Negative Zero */
#Defina	_FPCLASS_PZ	0x0040	/* Positive Zero */
#Defina	_FPCLASS_PD	0x0080	/* Positive Denormal */
#Defina	_FPCLASS_PN	0x0100	/* Positive Normal */
#Defina	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#FimSe
#FimSe

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido _EXCEPTION_DEFINED
#Defina _EXCEPTION_DEFINED
  Estrutura _exception {
    Inteiro type;
    Caractere *name;
    Duplo arg1;
    Duplo arg2;
    Duplo retval;
  };
#FimSe

#SenãoDefinido _COMPLEX_DEFINED
#Defina _COMPLEX_DEFINED
  Estrutura _complex {
    Duplo x,y;
  };
#FimSe

#Defina EDOM 33
#Defina ERANGE 34

#SenãoDefinido _HUGE
#SeDefinido _MSVCRT_
  Externo Duplo *_HUGE;
#Senão
  Externo Duplo *_imp___HUGE;
#Defina _HUGE	(*_imp___HUGE)
#FimSe
#FimSe

#Defina HUGE_VAL _HUGE

#SenãoDefinido _CRT_ABS_DEFINED
#Defina _CRT_ABS_DEFINED
  Inteiro __cdecl abs(Inteiro _X);
  Longo __cdecl labs(Longo _X);
#FimSe
  Duplo __cdecl acos(Duplo _X);
  Duplo __cdecl asin(Duplo _X);
  Duplo __cdecl atan(Duplo _X);
  Duplo __cdecl atan2(Duplo _Y,Duplo _X);
#SenãoDefinido _SIGN_DEFINED
#Defina _SIGN_DEFINED
  _CRTIMP Duplo __cdecl _copysign (Duplo _Number,Duplo _Sign);
  _CRTIMP Duplo __cdecl _chgsign (Duplo _X);
#FimSe
  Duplo __cdecl cos(Duplo _X);
  Duplo __cdecl cosh(Duplo _X);
  Duplo __cdecl exp(Duplo _X);
  Duplo __cdecl expm1(Duplo _X);
  Duplo __cdecl fabs(Duplo _X);
  Duplo __cdecl fmod(Duplo _X,Duplo _Y);
  Duplo __cdecl log(Duplo _X);
  Duplo __cdecl log10(Duplo _X);
  Duplo __cdecl pow(Duplo _X,Duplo _Y);
  Duplo __cdecl sin(Duplo _X);
  Duplo __cdecl sinh(Duplo _X);
  Duplo __cdecl tan(Duplo _X);
  Duplo __cdecl tanh(Duplo _X);
  Duplo __cdecl sqrt(Duplo _X);
#SenãoDefinido _CRT_ATOF_DEFINED
#Defina _CRT_ATOF_DEFINED
  Duplo __cdecl atof(Constante Caractere *_String);
  Duplo __cdecl _atof_l(Constante Caractere *_String,_locale_t _Locale);
#FimSe

  _CRTIMP Duplo __cdecl _cabs(Estrutura _complex _ComplexA);
  Duplo __cdecl ceil(Duplo _X);
  Duplo __cdecl floor(Duplo _X);
  Duplo __cdecl frexp(Duplo _X,Inteiro *_Y);
  Duplo __cdecl _hypot(Duplo _X,Duplo _Y);
  _CRTIMP Duplo __cdecl _j0(Duplo _X);
  _CRTIMP Duplo __cdecl _j1(Duplo _X);
  _CRTIMP Duplo __cdecl _jn(Inteiro _X,Duplo _Y);
  Duplo __cdecl ldexp(Duplo _X,Inteiro _Y);
#SenãoDefinido _CRT_MATHERR_DEFINED
#Defina _CRT_MATHERR_DEFINED
  Inteiro __cdecl _matherr(Estrutura _exception *_Except);
#FimSe
  Duplo __cdecl modf(Duplo _X,Duplo *_Y);
  _CRTIMP Duplo __cdecl _y0(Duplo _X);
  _CRTIMP Duplo __cdecl _y1(Duplo _X);
  _CRTIMP Duplo __cdecl _yn(Inteiro _X,Duplo _Y);

#Se(Definido(_X86_) && !Definido(__x86_64))
  _CRTIMP Inteiro __cdecl _set_SSE2_enable(Inteiro _Flag);
  /* from libmingwex */
  Real __cdecl _hypotf(Real _X,Real _Y);
#FimSe

  Real frexpf(Real _X,Inteiro *_Y);
  Real __cdecl ldexpf(Real _X,Inteiro _Y);
  Longo Duplo __cdecl ldexpl(Longo Duplo _X,Inteiro _Y);
  Real __cdecl acosf(Real _X);
  Real __cdecl asinf(Real _X);
   Real __cdecl atanf(Real _X);
   Real __cdecl atan2f(Real _X,Real _Y);
   Real __cdecl cosf(Real _X);
   Real __cdecl sinf(Real _X);
   Real __cdecl tanf(Real _X);
   Real __cdecl coshf(Real _X);
   Real __cdecl sinhf(Real _X);
   Real __cdecl tanhf(Real _X);
   Real __cdecl expf(Real _X);
   Real __cdecl expm1f(Real _X);
   Real __cdecl logf(Real _X);
   Real __cdecl log10f(Real _X);
   Real __cdecl modff(Real _X,Real *_Y);
   Real __cdecl powf(Real _X,Real _Y);
   Real __cdecl sqrtf(Real _X);
   Real __cdecl ceilf(Real _X);
   Real __cdecl floorf(Real _X);
  Real __cdecl fmodf(Real _X,Real _Y);
   Real __cdecl _hypotf(Real _X,Real _Y);
  Real __cdecl fabsf(Real _X);
#Se !Definido(__ia64__)
   /* from libmingwex */
   Real __cdecl _copysignf (Real _Number,Real _Sign);
   Real __cdecl _chgsignf (Real _X);
   Real __cdecl _logbf(Real _X);
   Real __cdecl _nextafterf(Real _X,Real _Y);
   Inteiro __cdecl _finitef(Real _X);
   Inteiro __cdecl _isnanf(Real _X);
   Inteiro __cdecl _fpclassf(Real _X);
#FimSe

#SenãoDefinido __cplusplus
  __CRT_INLINE Longo Duplo __cdecl fabsl (Longo Duplo x)
  {
    Longo Duplo res;
    Montador ("fabs;" : "=t" (res) : "0" (x));
    Retorno res;
  }
#Defina _hypotl(x,y) ((Longo Duplo)_hypot((Duplo)(x),(Duplo)(y)))
#Defina _matherrl _matherr
  __CRT_INLINE Longo Duplo _chgsignl(Longo Duplo _Number) { Retorno _chgsign((Duplo)(_Number)); }
  __CRT_INLINE Longo Duplo _copysignl(Longo Duplo _Number,Longo Duplo _Sign) { Retorno _copysign((Duplo)(_Number),(Duplo)(_Sign)); }
  __CRT_INLINE Real frexpf(Real _X,Inteiro *_Y) { Retorno ((Real)frexp((Duplo)_X,_Y)); }

#Se !Definido (__ia64__)
  __CRT_INLINE Real __cdecl fabsf (Real x)
  {
    Real res;
    Montador ("fabs;" : "=t" (res) : "0" (x));
    Retorno res;
  }

  __CRT_INLINE Real __cdecl ldexpf (Real x, Inteiro expn) { Retorno (Real) ldexp (x, expn); }
#FimSe
#Senão
  // cplusplus
  __CRT_INLINE Longo Duplo __cdecl fabsl (Longo Duplo x)
  {
    Longo Duplo res;
    Montador ("fabs;" : "=t" (res) : "0" (x));
    Retorno res;
  }
  __CRT_INLINE Longo Duplo modfl(Longo Duplo _X,Longo Duplo *_Y) {
    Duplo _Di,_Df = modf((Duplo)_X,&_Di);
    *_Y = (Longo Duplo)_Di;
    Retorno (_Df);
  }
  __CRT_INLINE Longo Duplo _chgsignl(Longo Duplo _Number) { Retorno _chgsign(static_cast<Duplo>(_Number)); }
  __CRT_INLINE Longo Duplo _copysignl(Longo Duplo _Number,Longo Duplo _Sign) { Retorno _copysign(static_cast<Duplo>(_Number),static_cast<Duplo>(_Sign)); }
  __CRT_INLINE Real frexpf(Real _X,Inteiro *_Y) { Retorno ((Real)frexp((Duplo)_X,_Y)); }
#SenãoDefinido __ia64__
  __CRT_INLINE Real __cdecl fabsf (Real x)
  {
    Real res;
    Montador ("fabs;" : "=t" (res) : "0" (x));
    Retorno res;
  }
  __CRT_INLINE Real __cdecl ldexpf (Real x, Inteiro expn) { Retorno (Real) ldexp (x, expn); }
#SenãoDefinido __x86_64
  __CRT_INLINE Real acosf(Real _X) { Retorno ((Real)acos((Duplo)_X)); }
  __CRT_INLINE Real asinf(Real _X) { Retorno ((Real)asin((Duplo)_X)); }
  __CRT_INLINE Real atanf(Real _X) { Retorno ((Real)atan((Duplo)_X)); }
  __CRT_INLINE Real atan2f(Real _X,Real _Y) { Retorno ((Real)atan2((Duplo)_X,(Duplo)_Y)); }
  __CRT_INLINE Real ceilf(Real _X) { Retorno ((Real)ceil((Duplo)_X)); }
  __CRT_INLINE Real cosf(Real _X) { Retorno ((Real)cos((Duplo)_X)); }
  __CRT_INLINE Real coshf(Real _X) { Retorno ((Real)cosh((Duplo)_X)); }
  __CRT_INLINE Real expf(Real _X) { Retorno ((Real)exp((Duplo)_X)); }
  __CRT_INLINE Real floorf(Real _X) { Retorno ((Real)floor((Duplo)_X)); }
  __CRT_INLINE Real fmodf(Real _X,Real _Y) { Retorno ((Real)fmod((Duplo)_X,(Duplo)_Y)); }
  __CRT_INLINE Real logf(Real _X) { Retorno ((Real)log((Duplo)_X)); }
  __CRT_INLINE Real log10f(Real _X) { Retorno ((Real)log10((Duplo)_X)); }
  __CRT_INLINE Real modff(Real _X,Real *_Y) {
    Duplo _Di,_Df = modf((Duplo)_X,&_Di);
    *_Y = (Real)_Di;
    Retorno ((Real)_Df);
  }
  __CRT_INLINE Real powf(Real _X,Real _Y) { Retorno ((Real)pow((Duplo)_X,(Duplo)_Y)); }
  __CRT_INLINE Real sinf(Real _X) { Retorno ((Real)sin((Duplo)_X)); }
  __CRT_INLINE Real sinhf(Real _X) { Retorno ((Real)sinh((Duplo)_X)); }
  __CRT_INLINE Real sqrtf(Real _X) { Retorno ((Real)sqrt((Duplo)_X)); }
  __CRT_INLINE Real tanf(Real _X) { Retorno ((Real)tan((Duplo)_X)); }
  __CRT_INLINE Real tanhf(Real _X) { Retorno ((Real)tanh((Duplo)_X)); }
#FimSe
#FimSe
#FimSe

#SenãoDefinido	NO_OLDNAMES
#Defina matherr _matherr

#Defina HUGE	_HUGE
  /*	Duplo __cdecl cabs(Estrutura _complex _X); */
  Duplo __cdecl hypot(Duplo _X,Duplo _Y);
  _CRTIMP Duplo __cdecl j0(Duplo _X);
  _CRTIMP Duplo __cdecl j1(Duplo _X);
  _CRTIMP Duplo __cdecl jn(Inteiro _X,Duplo _Y);
  _CRTIMP Duplo __cdecl y0(Duplo _X);
  _CRTIMP Duplo __cdecl y1(Duplo _X);
  _CRTIMP Duplo __cdecl yn(Inteiro _X,Duplo _Y);
#FimSe

#SenãoDefinido __NO_ISOCEXT
#Se (Definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !Definido __STRICT_ANSI__ || Definido __GLIBCPP__

#Defina NAN (0.0F/0.0F)
#Defina HUGE_VALF (1.0F/0.0F)
#Defina HUGE_VALL (1.0L/0.0L)
#Defina INFINITY (1.0F/0.0F)


#Defina FP_NAN		0x0100
#Defina FP_NORMAL	0x0400
#Defina FP_INFINITE	(FP_NAN | FP_NORMAL)
#Defina FP_ZERO		0x4000
#Defina FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE Real or Duplo, because we want to ensure truncation
  to semantic type before classification. 
  (A normal Longo Duplo value might become subnormal when 
  converted to Duplo, and zero when converted to Real.)
  */

  Externo Inteiro __cdecl __fpclassifyf (Real);
  Externo Inteiro __cdecl __fpclassify (Duplo);
  Externo Inteiro __cdecl __fpclassifyl (Longo Duplo);

/* Implemented at ctec/ctec_libm.h */
#Defina fpclassify(x) (TamanhoDe (x) == TamanhoDe (Real) ? __fpclassifyf (x)	  \
  : TamanhoDe (x) == TamanhoDe (Duplo) ? __fpclassify (x) \
  : __fpclassifyl (x))

  /* 7.12.3.2 */
#Defina isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#Defina isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#Defina isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#Defina isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  Externo Inteiro __cdecl __signbitf (Real);
  Externo Inteiro __cdecl __signbit (Duplo);
  Externo Inteiro __cdecl __signbitl (Longo Duplo);

/* Implemented at ctec/ctec_libm.h */
#Defina signbit(x) (TamanhoDe (x) == TamanhoDe (Real) ? __signbitf (x)	\
  : TamanhoDe (x) == TamanhoDe (Duplo) ? __signbit (x)	\
  : __signbitl (x))

  Externo Duplo __cdecl exp2(Duplo);
  Externo Real __cdecl exp2f(Real);
  Externo Longo Duplo __cdecl exp2l(Longo Duplo);

#Defina FP_ILOGB0 ((Inteiro)0x80000000)
#Defina FP_ILOGBNAN ((Inteiro)0x80000000)
  Externo Inteiro __cdecl ilogb (Duplo);
  Externo Inteiro __cdecl ilogbf (Real);
  Externo Inteiro __cdecl ilogbl (Longo Duplo);

  Externo Duplo __cdecl log1p(Duplo);
  Externo Real __cdecl log1pf(Real);
  Externo Longo Duplo __cdecl log1pl(Longo Duplo);

  Externo Duplo __cdecl log2 (Duplo);
  Externo Real __cdecl log2f (Real);
  Externo Longo Duplo __cdecl log2l (Longo Duplo);

  Externo Duplo __cdecl logb (Duplo);
  Externo Real __cdecl logbf (Real);
  Externo Longo Duplo __cdecl logbl (Longo Duplo);

  __CRT_INLINE Duplo __cdecl logb (Duplo x)
  {
    Duplo res;
    Montador ("fxtract\n\t"
      "fstp	%%st" : "=t" (res) : "0" (x));
    Retorno res;
  }

  __CRT_INLINE Real __cdecl logbf (Real x)
  {
    Real res;
    Montador ("fxtract\n\t"
      "fstp	%%st" : "=t" (res) : "0" (x));
    Retorno res;
  }

  __CRT_INLINE Longo Duplo __cdecl logbl (Longo Duplo x)
  {
    Longo Duplo res;
    Montador ("fxtract\n\t"
      "fstp	%%st" : "=t" (res) : "0" (x));
    Retorno res;
  }

  Externo Longo Duplo __cdecl modfl (Longo Duplo, Longo Duplo*);

  /* 7.12.6.13 */
  Externo Duplo __cdecl scalbn (Duplo, Inteiro);
  Externo Real __cdecl scalbnf (Real, Inteiro);
  Externo Longo Duplo __cdecl scalbnl (Longo Duplo, Inteiro);

  Externo Duplo __cdecl scalbln (Duplo, Longo);
  Externo Real __cdecl scalblnf (Real, Longo);
  Externo Longo Duplo __cdecl scalblnl (Longo Duplo, Longo);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  Externo Duplo __cdecl cbrt (Duplo);
  Externo Real __cdecl cbrtf (Real);
  Externo Longo Duplo __cdecl cbrtl (Longo Duplo);

  __CRT_INLINE Real __cdecl hypotf (Real x, Real y)
  { Retorno (Real) hypot (x, y);}
  Externo Longo Duplo __cdecl hypotl (Longo Duplo, Longo Duplo);

  Externo Longo Duplo __cdecl powl (Longo Duplo, Longo Duplo);
  Externo Longo Duplo __cdecl expl(Longo Duplo);
  Externo Longo Duplo __cdecl expm1l(Longo Duplo);
  Externo Longo Duplo __cdecl coshl(Longo Duplo);
  Externo Longo Duplo __cdecl fabsl (Longo Duplo);
  Externo Longo Duplo __cdecl acosl(Longo Duplo);
  Externo Longo Duplo __cdecl asinl(Longo Duplo);
  Externo Longo Duplo __cdecl atanl(Longo Duplo);
  Externo Longo Duplo __cdecl atan2l(Longo Duplo,Longo Duplo);
  Externo Longo Duplo __cdecl sinhl(Longo Duplo);
  Externo Longo Duplo __cdecl tanhl(Longo Duplo);

  /* 7.12.8.1 The erf functions  */
  Externo Duplo __cdecl erf (Duplo);
  Externo Real __cdecl erff (Real);
  /* TODO
  Externo Longo Duplo __cdecl erfl (Longo Duplo);
  */ 

  /* 7.12.8.2 The erfc functions  */
  Externo Duplo __cdecl erfc (Duplo);
  Externo Real __cdecl erfcf (Real);
  /* TODO
  Externo Longo Duplo __cdecl erfcl (Longo Duplo);
  */ 

  /* 7.12.8.3 The lgamma functions */
  Externo Duplo __cdecl lgamma (Duplo);
  Externo Real __cdecl lgammaf (Real);
  Externo Longo Duplo __cdecl lgammal (Longo Duplo);

  /* 7.12.8.4 The tgamma functions */
  Externo Duplo __cdecl tgamma (Duplo);
  Externo Real __cdecl tgammaf (Real);
  Externo Longo Duplo __cdecl tgammal (Longo Duplo);

  Externo Longo Duplo __cdecl ceill (Longo Duplo);
  Externo Longo Duplo __cdecl floorl (Longo Duplo);
  Externo Longo Duplo __cdecl frexpl(Longo Duplo,Inteiro *);
  Externo Longo Duplo __cdecl log10l(Longo Duplo);
  Externo Longo Duplo __cdecl logl(Longo Duplo);
  Externo Longo Duplo __cdecl cosl(Longo Duplo);
  Externo Longo Duplo __cdecl sinl(Longo Duplo);
  Externo Longo Duplo __cdecl tanl(Longo Duplo);
  Externo Longo Duplo sqrtl(Longo Duplo);

  /* 7.12.9.3 */
  Externo Duplo __cdecl nearbyint ( Duplo);
  Externo Real __cdecl nearbyintf (Real);
  Externo Longo Duplo __cdecl nearbyintl (Longo Duplo);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  __CRT_INLINE Duplo __cdecl rint (Duplo x)
  {
    Duplo retval;
    Montador (
      "fldl    %1\n"
      "frndint   \n"
      "fstl    %0\n" : "=m" (retval) : "m" (x));
    Retorno retval;
  }

  __CRT_INLINE Real __cdecl rintf (Real x)
  {
    Real retval;
    Montador (
      "flds    %1\n"
      "frndint   \n"
      "fsts    %0\n" : "=m" (retval) : "m" (x));
    Retorno retval;
  }

  __CRT_INLINE Longo Duplo __cdecl rintl (Longo Duplo x)
  {
    Longo Duplo retval;
    Montador (
      "fldt    %1\n"
      "frndint   \n"
      "fstt    %0\n" : "=m" (retval) : "m" (x));
    Retorno retval;
  }

  /* 7.12.9.5 */
  __CRT_INLINE Longo __cdecl lrint (Duplo x) 
  {
    Longo retval;  
    Montador Volátil                         \
      ("fldl   %1\n"                             \
       "fistpl %0"  : "=m" (retval) : "m" (x));  \
      Retorno retval;
  }

  __CRT_INLINE Longo __cdecl lrintf (Real x) 
  {
    Longo retval;
    Montador Volátil                         \
      ("flds   %1\n"                             \
       "fistpl %0"  : "=m" (retval) : "m" (x));  \
      Retorno retval;
  }

  __CRT_INLINE Longo __cdecl lrintl (Longo Duplo x) 
  {
    Longo retval;
    Montador Volátil                         \
      ("fldt   %1\n"                             \
       "fistpl %0"  : "=m" (retval) : "m" (x));  \
      Retorno retval;
  }

  __CRT_INLINE Longo Longo __cdecl llrint (Duplo x) 
  {
    Longo Longo retval;
    Montador Volátil                         \
      ("fldl    %1\n"                            \
       "fistpll %0"  : "=m" (retval) : "m" (x)); \
      Retorno retval;
  }

  __CRT_INLINE Longo Longo __cdecl llrintf (Real x) 
  {
    Longo Longo retval;
    Montador Volátil                         \
      ("flds   %1\n"                             \
       "fistpll %0"  : "=m" (retval) : "m" (x)); \
      Retorno retval;
  }

  __CRT_INLINE Longo Longo __cdecl llrintl (Longo Duplo x) 
  {
    Longo Longo retval;
    Montador Volátil                         \
      ("fldt    %1\n"                            \
       "fistpll %0"  : "=m" (retval) : "m" (x)); \
      Retorno retval;
  }

  #Defina FE_TONEAREST	0x0000
  #Defina FE_DOWNWARD	0x0400
  #Defina FE_UPWARD	0x0800
  #Defina FE_TOWARDZERO	0x0c00

  __CRT_INLINE Duplo trunc (Duplo _x)
  {
    Duplo retval;
    SemSinal Curto saved_cw;
    SemSinal Curto tmp_cw;
    Montador ("fnstcw %0;" : "=m" (saved_cw)); /* save FPU control word */
    tmp_cw = (saved_cw & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO))
	    | FE_TOWARDZERO;
    Montador ("fldcw %0;" : : "m" (tmp_cw));
    Montador ("fldl  %1;"
             "frndint;"
             "fstl  %0;" : "=m" (retval)  : "m" (_x)); /* round towards zero */
    Montador ("fldcw %0;" : : "m" (saved_cw) ); /* restore saved control word */
    Retorno retval;
  }

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  Externo Duplo __cdecl round (Duplo);
  Externo Real __cdecl roundf (Real);
  Externo Longo Duplo __cdecl roundl (Longo Duplo);

  /* 7.12.9.7  */
  Externo Longo __cdecl lround (Duplo);
  Externo Longo __cdecl lroundf (Real);
  Externo Longo __cdecl lroundl (Longo Duplo);

  Externo Longo Longo __cdecl llround (Duplo);
  Externo Longo Longo __cdecl llroundf (Real);
  Externo Longo Longo __cdecl llroundl (Longo Duplo);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  Externo Duplo __cdecl trunc (Duplo);
  Externo Real __cdecl truncf (Real);
  Externo Longo Duplo __cdecl truncl (Longo Duplo);

  Externo Longo Duplo __cdecl fmodl (Longo Duplo, Longo Duplo);

  /* 7.12.10.2 */ 
  Externo Duplo __cdecl remainder (Duplo, Duplo);
  Externo Real __cdecl remainderf (Real, Real);
  Externo Longo Duplo __cdecl remainderl (Longo Duplo, Longo Duplo);

  /* 7.12.10.3 */
  Externo Duplo __cdecl remquo(Duplo, Duplo, Inteiro *);
  Externo Real __cdecl remquof(Real, Real, Inteiro *);
  Externo Longo Duplo __cdecl remquol(Longo Duplo, Longo Duplo, Inteiro *);

  /* 7.12.11.1 */
  Externo Duplo __cdecl copysign (Duplo, Duplo); /* in libmoldname.a */
  Externo Real __cdecl copysignf (Real, Real);
  Externo Longo Duplo __cdecl copysignl (Longo Duplo, Longo Duplo);

  /* 7.12.11.2 Return a NaN */
  Externo Duplo __cdecl nan(Constante Caractere *tagp);
  Externo Real __cdecl nanf(Constante Caractere *tagp);
  Externo Longo Duplo __cdecl nanl(Constante Caractere *tagp);

#SenãoDefinido __STRICT_ANSI__
#Defina _nan() nan("")
#Defina _nanf() nanf("")
#Defina _nanl() nanl("")
#FimSe

  /* 7.12.11.3 */
  Externo Duplo __cdecl nextafter (Duplo, Duplo); /* in libmoldname.a */
  Externo Real __cdecl nextafterf (Real, Real);
  Externo Longo Duplo __cdecl nextafterl (Longo Duplo, Longo Duplo);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  Externo Duplo __cdecl fdim (Duplo x, Duplo y);
  Externo Real __cdecl fdimf (Real x, Real y);
  Externo Longo Duplo __cdecl fdiml (Longo Duplo x, Longo Duplo y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: Se one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  Externo Duplo __cdecl fmax  (Duplo, Duplo);
  Externo Real __cdecl fmaxf (Real, Real);
  Externo Longo Duplo __cdecl fmaxl (Longo Duplo, Longo Duplo);

  /* 7.12.12.3 */
  Externo Duplo __cdecl fmin (Duplo, Duplo);
  Externo Real __cdecl fminf (Real, Real);
  Externo Longo Duplo __cdecl fminl (Longo Duplo, Longo Duplo);

  /* 7.12.13.1 */
  /* Retorno x * y + z as a ternary op */ 
  Externo Duplo __cdecl fma (Duplo, Duplo, Duplo);
  Externo Real __cdecl fmaf (Real, Real, Real);
  Externo Longo Duplo __cdecl fmal (Longo Duplo, Longo Duplo, Longo Duplo);


#Se 0 // gr: duplicate, see below
  /* 7.12.14 */
  /* 
  *  With these functions, comparisons involving quiet NaNs set the FP
  *  condition code to "unordered".  The IEEE floating-point spec
  *  dictates that the result of floating-point comparisons should be
  *  false whenever a NaN is involved, with the exception of the != op, 
  *  which always returns true: yes, (NaN != NaN) is true).
  */

#Se __GNUC__ >= 3

#Defina isgreater(x, y) __builtin_isgreater(x, y)
#Defina isgreaterequal(x, y) __builtin_isgreaterequal(x, y)
#Defina isless(x, y) __builtin_isless(x, y)
#Defina islessequal(x, y) __builtin_islessequal(x, y)
#Defina islessgreater(x, y) __builtin_islessgreater(x, y)
#Defina isunordered(x, y) __builtin_isunordered(x, y)

#Senão
  /*  helper  */
  __CRT_INLINE Inteiro  __cdecl
    __fp_unordered_compare (Longo Duplo x, Longo Duplo y){
      SemSinal Curto retval;
      Montador ("fucom %%st(1);"
	"fnstsw;": "=a" (retval) : "t" (x), "u" (y));
      Retorno retval;
  }

#Defina isgreater(x, y) ((__fp_unordered_compare(x, y) \
  & 0x4500) == 0)
#Defina isless(x, y) ((__fp_unordered_compare (y, x) \
  & 0x4500) == 0)
#Defina isgreaterequal(x, y) ((__fp_unordered_compare (x, y) \
  & FP_INFINITE) == 0)
#Defina islessequal(x, y) ((__fp_unordered_compare(y, x) \
  & FP_INFINITE) == 0)
#Defina islessgreater(x, y) ((__fp_unordered_compare(x, y) \
  & FP_SUBNORMAL) == 0)
#Defina isunordered(x, y) ((__fp_unordered_compare(x, y) \
  & 0x4500) == 0x4500)

#FimSe
#FimSe //0


#FimSe /* __STDC_VERSION__ >= 199901L */
#FimSe /* __NO_ISOCEXT */

#SeDefinido __cplusplus
}
Externo "C++" {
  template<class _Ty> EmLinha _Ty _Pow_int(_Ty _X,Inteiro _Y) {
    SemSinal Inteiro _N;
    Se(_Y >= 0) _N = (SemSinal Inteiro)_Y;
    Senão _N = (SemSinal Inteiro)(-_Y);
    Para(_Ty _Z = _Ty(1);;_X *= _X) {
      Se((_N & 1)!=0) _Z *= _X;
      Se((_N >>= 1)==0) Retorno (_Y < 0 ? _Ty(1) / _Z : _Z); 
    }
  }
}
#FimSe

#Diretiva pack(pop)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (EmLinha __fpclassify*, __signbit* and variants) */
#Inclua "ctec/ctec_libm.h"

#FimSe /* End _MATH_H_ */

