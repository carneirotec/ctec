/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_WCTYPE
#Defina _INC_WCTYPE

#SenãoDefinido _WIN32
#Erro Only Win32 target is supported!
#FimSe

#Inclua <_mingw.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido _CRTIMP
#Defina _CRTIMP __declspec(dllimport)
#FimSe

#SenãoDefinido _WCHAR_T_DEFINED
  Tipo SemSinal Curto wchar_t;
#Defina _WCHAR_T_DEFINED
#FimSe

#SenãoDefinido _WCTYPE_T_DEFINED
  Tipo SemSinal Curto wint_t;
  Tipo SemSinal Curto wctype_t;
#Defina _WCTYPE_T_DEFINED
#FimSe

#SenãoDefinido WEOF
#Defina WEOF (wint_t)(0xFFFF)
#FimSe

#SenãoDefinido _CRT_CTYPEDATA_DEFINED
#Defina _CRT_CTYPEDATA_DEFINED
#SenãoDefinido _CTYPE_DISABLE_MACROS

#SenãoDefinido __PCTYPE_FUNC
#Defina __PCTYPE_FUNC __pctype_func()
#SeDefinido _MSVCRT_
#Defina __pctype_func() (_pctype)
#Senão
#Defina __pctype_func() (*_imp___pctype)
#FimSe
#FimSe

#SenãoDefinido _pctype
#SeDefinido _MSVCRT_
  Externo SemSinal Curto *_pctype;
#Senão
  Externo SemSinal Curto **_imp___pctype;
#Defina _pctype (*_imp___pctype)
#FimSe
#FimSe

#FimSe
#FimSe

#SenãoDefinido _CRT_WCTYPEDATA_DEFINED
#Defina _CRT_WCTYPEDATA_DEFINED
#SenãoDefinido _CTYPE_DISABLE_MACROS
#SenãoDefinido _wctype
#SeDefinido _MSVCRT_
  Externo SemSinal Curto *_wctype;
#Senão
  Externo SemSinal Curto **_imp___wctype;
#Defina _wctype (*_imp___wctype)
#FimSe
#FimSe

#SenãoDefinido _pwctype
#SeDefinido _MSVCRT_
  Externo SemSinal Curto *_pwctype;
#Senão
  Externo SemSinal Curto **_imp___pwctype;
#Defina _pwctype (*_imp___pwctype)
#Defina __pwctype_func() (*_imp___pwctype)
#FimSe
#FimSe
#FimSe
#FimSe

#Defina _UPPER 0x1
#Defina _LOWER 0x2
#Defina _DIGIT 0x4
#Defina _SPACE 0x8

#Defina _PUNCT 0x10
#Defina _CONTROL 0x20
#Defina _BLANK 0x40
#Defina _HEX 0x80

#Defina _LEADBYTE 0x8000
#Defina _ALPHA (0x0100|_UPPER|_LOWER)

#SenãoDefinido _WCTYPE_DEFINED
#Defina _WCTYPE_DEFINED

  Inteiro __cdecl iswalpha(wint_t);
  Inteiro __cdecl iswupper(wint_t);
  Inteiro __cdecl iswlower(wint_t);
  Inteiro __cdecl iswdigit(wint_t);
  Inteiro __cdecl iswxdigit(wint_t);
  Inteiro __cdecl iswspace(wint_t);
  Inteiro __cdecl iswpunct(wint_t);
  Inteiro __cdecl iswalnum(wint_t);
  Inteiro __cdecl iswprint(wint_t);
  Inteiro __cdecl iswgraph(wint_t);
  Inteiro __cdecl iswcntrl(wint_t);
  Inteiro __cdecl iswascii(wint_t);
  Inteiro __cdecl isleadbyte(Inteiro);
  wint_t __cdecl towupper(wint_t);
  wint_t __cdecl towlower(wint_t);
  Inteiro __cdecl iswctype(wint_t,wctype_t);
  _CRTIMP Inteiro __cdecl __iswcsymf(wint_t);
  _CRTIMP Inteiro __cdecl __iswcsym(wint_t);
  Inteiro __cdecl is_wctype(wint_t,wctype_t);
#Se (Definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !Definido (NO_OLDNAMES)
Inteiro __cdecl isblank(Inteiro _C);
#FimSe
#FimSe

#SenãoDefinido _WCTYPE_INLINE_DEFINED
#Defina _WCTYPE_INLINE_DEFINED
#SenãoDefinido __cplusplus
#Defina iswalpha(_c) (iswctype(_c,_ALPHA))
#Defina iswupper(_c) (iswctype(_c,_UPPER))
#Defina iswlower(_c) (iswctype(_c,_LOWER))
#Defina iswdigit(_c) (iswctype(_c,_DIGIT))
#Defina iswxdigit(_c) (iswctype(_c,_HEX))
#Defina iswspace(_c) (iswctype(_c,_SPACE))
#Defina iswpunct(_c) (iswctype(_c,_PUNCT))
#Defina iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#Defina iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#Defina iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#Defina iswcntrl(_c) (iswctype(_c,_CONTROL))
#Defina iswascii(_c) ((SemSinal)(_c) < 0x80)
#Defina isleadbyte(c) (__pctype_func()[(SemSinal Caractere)(c)] & _LEADBYTE)
#Senão
  __CRT_INLINE Inteiro __cdecl iswalpha(wint_t _C) {Retorno (iswctype(_C,_ALPHA)); }
  __CRT_INLINE Inteiro __cdecl iswupper(wint_t _C) {Retorno (iswctype(_C,_UPPER)); }
  __CRT_INLINE Inteiro __cdecl iswlower(wint_t _C) {Retorno (iswctype(_C,_LOWER)); }
  __CRT_INLINE Inteiro __cdecl iswdigit(wint_t _C) {Retorno (iswctype(_C,_DIGIT)); }
  __CRT_INLINE Inteiro __cdecl iswxdigit(wint_t _C) {Retorno (iswctype(_C,_HEX)); }
  __CRT_INLINE Inteiro __cdecl iswspace(wint_t _C) {Retorno (iswctype(_C,_SPACE)); }
  __CRT_INLINE Inteiro __cdecl iswpunct(wint_t _C) {Retorno (iswctype(_C,_PUNCT)); }
  __CRT_INLINE Inteiro __cdecl iswalnum(wint_t _C) {Retorno (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE Inteiro __cdecl iswprint(wint_t _C) {Retorno (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE Inteiro __cdecl iswgraph(wint_t _C) {Retorno (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE Inteiro __cdecl iswcntrl(wint_t _C) {Retorno (iswctype(_C,_CONTROL)); }
  __CRT_INLINE Inteiro __cdecl iswascii(wint_t _C) {Retorno ((SemSinal)(_C) < 0x80); }
  __CRT_INLINE Inteiro __cdecl isleadbyte(Inteiro _C) {Retorno (__pctype_func()[(SemSinal Caractere)(_C)] & _LEADBYTE); }
#FimSe
#FimSe

  Tipo wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(Constante Caractere *);
  wctype_t __cdecl wctype(Constante Caractere *);

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)
#FimSe
