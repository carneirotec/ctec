/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_CTYPE
#Defina _INC_CTYPE

#Inclua <_mingw.h>

#SeDefinido __cplusplus
Externo "C" {
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
#Defina __pctype_func()	(_pctype)
#Senão
#Defina __pctype_func()	(*_imp___pctype)
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
#SeDefinido _MSVCRT_
#Defina __pwctype_func() (_pwctype)
#SenãoDefinido _pwctype
  Externo SemSinal Curto *_pwctype;
#FimSe
#Senão
#Defina __pwctype_func() (*_imp___pwctype)
#SenãoDefinido _pwctype
  Externo SemSinal Curto **_imp___pwctype;
#Defina _pwctype (*_imp___pwctype)
#FimSe
#FimSe
#FimSe
#FimSe

  /* CRT stuff */
#Se 1
  Externo Constante SemSinal Caractere __newclmap[];
  Externo Constante SemSinal Caractere __newcumap[];
  Externo pthreadlocinfo __ptlocinfo;
  Externo pthreadmbcinfo __ptmbcinfo;
  Externo Inteiro __globallocalestatus;
  Externo Inteiro __locale_changed;
  Externo Estrutura threadlocaleinfostruct __initiallocinfo;
  Externo _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(Vazio);
  pthreadmbcinfo __cdecl __updatetmbcinfo(Vazio);
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

#SenãoDefinido _CTYPE_DEFINED
#Defina _CTYPE_DEFINED

  _CRTIMP Inteiro __cdecl _isctype(Inteiro _C,Inteiro _Type);
  _CRTIMP Inteiro __cdecl _isctype_l(Inteiro _C,Inteiro _Type,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl isalpha(Inteiro _C);
  _CRTIMP Inteiro __cdecl _isalpha_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl isupper(Inteiro _C);
  _CRTIMP Inteiro __cdecl _isupper_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl islower(Inteiro _C);
  _CRTIMP Inteiro __cdecl _islower_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl isdigit(Inteiro _C);
  _CRTIMP Inteiro __cdecl _isdigit_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl isxdigit(Inteiro _C);
  _CRTIMP Inteiro __cdecl _isxdigit_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl isspace(Inteiro _C);
  _CRTIMP Inteiro __cdecl _isspace_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl ispunct(Inteiro _C);
  _CRTIMP Inteiro __cdecl _ispunct_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl isalnum(Inteiro _C);
  _CRTIMP Inteiro __cdecl _isalnum_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl isprint(Inteiro _C);
  _CRTIMP Inteiro __cdecl _isprint_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl isgraph(Inteiro _C);
  _CRTIMP Inteiro __cdecl _isgraph_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl iscntrl(Inteiro _C);
  _CRTIMP Inteiro __cdecl _iscntrl_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl toupper(Inteiro _C);
  _CRTIMP Inteiro __cdecl tolower(Inteiro _C);
  _CRTIMP Inteiro __cdecl _tolower(Inteiro _C);
  _CRTIMP Inteiro __cdecl _tolower_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _toupper(Inteiro _C);
  _CRTIMP Inteiro __cdecl _toupper_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl __isascii(Inteiro _C);
  _CRTIMP Inteiro __cdecl __toascii(Inteiro _C);
  _CRTIMP Inteiro __cdecl __iscsymf(Inteiro _C);
  _CRTIMP Inteiro __cdecl __iscsym(Inteiro _C);

#Se (Definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !Definido (NO_OLDNAMES)
Inteiro __cdecl isblank(Inteiro _C);
#FimSe
#FimSe

#SenãoDefinido _WCTYPE_DEFINED
#Defina _WCTYPE_DEFINED

  Inteiro __cdecl iswalpha(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswupper(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswlower(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswdigit(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswxdigit(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswspace(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswpunct(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswalnum(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswprint(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswgraph(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswcntrl(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswascii(wint_t _C);
  Inteiro __cdecl isleadbyte(Inteiro _C);
  _CRTIMP Inteiro __cdecl _isleadbyte_l(Inteiro _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP Inteiro __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl __iswcsymf(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl __iswcsym(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl is_wctype(wint_t _C,wctype_t _Type);

#Se (Definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !Definido (NO_OLDNAMES)
Inteiro __cdecl iswblank(wint_t _C);
#FimSe
#FimSe

#SenãoDefinido _CTYPE_DISABLE_MACROS

#SenãoDefinido MB_CUR_MAX
#Defina MB_CUR_MAX ___mb_cur_max_func()
#SenãoDefinido __mb_cur_max
#SeDefinido _MSVCRT_
  Externo Inteiro __mb_cur_max;
#Senão
#Defina __mb_cur_max	(*_imp____mb_cur_max)
  Externo Inteiro *_imp____mb_cur_max;
#FimSe
#FimSe
#SeDefinido _MSVCRT_
#Defina ___mb_cur_max_func() (__mb_cur_max)
#Senão
#Defina ___mb_cur_max_func() (*_imp____mb_cur_max)
#FimSe
#FimSe

#Defina __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#Defina _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#Defina _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=NULL && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
#Defina _isalpha_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA,_Locale)
#Defina _isupper_l(_Char,_Locale) _ischartype_l(_Char,_UPPER,_Locale)
#Defina _islower_l(_Char,_Locale) _ischartype_l(_Char,_LOWER,_Locale)
#Defina _isdigit_l(_Char,_Locale) _ischartype_l(_Char,_DIGIT,_Locale)
#Defina _isxdigit_l(_Char,_Locale) _ischartype_l(_Char,_HEX,_Locale)
#Defina _isspace_l(_Char,_Locale) _ischartype_l(_Char,_SPACE,_Locale)
#Defina _ispunct_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT,_Locale)
#Defina _isalnum_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA|_DIGIT,_Locale)
#Defina _isprint_l(_Char,_Locale) _ischartype_l(_Char,_BLANK|_PUNCT|_ALPHA|_DIGIT,_Locale)
#Defina _isgraph_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT|_ALPHA|_DIGIT,_Locale)
#Defina _iscntrl_l(_Char,_Locale) _ischartype_l(_Char,_CONTROL,_Locale)
#Defina _tolower(_Char) ((_Char)-'A'+'a')
#Defina _toupper(_Char) ((_Char)-'a'+'A')
#Defina __isascii(_Char) ((SemSinal)(_Char) < 0x80)
#Defina __toascii(_Char) ((_Char) & 0x7f)

#SenãoDefinido _WCTYPE_INLINE_DEFINED
#Defina _WCTYPE_INLINE_DEFINED

#Indefinido _CRT_WCTYPE_NOINLINE
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
#Defina _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#Defina _iswupper_l(_c,_p) (_iswctype_l(_c,_UPPER,_p))
#Defina _iswlower_l(_c,_p) (_iswctype_l(_c,_LOWER,_p))
#Defina _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#Defina _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#Defina _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#Defina _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#Defina _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#Defina _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#Defina _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#Defina _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#FimSe
#FimSe

#Defina __iscsymf(_c) (isalpha(_c) || ((_c)=='_'))
#Defina __iscsym(_c) (isalnum(_c) || ((_c)=='_'))
#Defina __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#Defina __iswcsym(_c) (iswalnum(_c) || ((_c)=='_'))
#Defina _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#Defina _iscsym_l(_c,_p) (_isalnum_l(_c,_p) || ((_c)=='_'))
#Defina _iswcsymf_l(_c,_p) (_iswalpha_l(_c,_p) || ((_c)=='_'))
#Defina _iswcsym_l(_c,_p) (_iswalnum_l(_c,_p) || ((_c)=='_'))
#FimSe

#SenãoDefinido	NO_OLDNAMES
#SenãoDefinido _CTYPE_DEFINED
  Inteiro __cdecl isascii(Inteiro _C);
  Inteiro __cdecl toascii(Inteiro _C);
  Inteiro __cdecl iscsymf(Inteiro _C);
  Inteiro __cdecl iscsym(Inteiro _C);
#Senão
#Defina isascii __isascii
#Defina toascii __toascii
#Defina iscsymf __iscsymf
#Defina iscsym __iscsym
#FimSe
#FimSe

#SeDefinido __cplusplus
}
#FimSe
#FimSe
