/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_LOCALE
#Defina _INC_LOCALE

#Inclua <_mingw.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#Defina LC_ALL 0
#Defina LC_COLLATE 1
#Defina LC_CTYPE 2
#Defina LC_MONETARY 3
#Defina LC_NUMERIC 4
#Defina LC_TIME 5

#Defina LC_MIN LC_ALL
#Defina LC_MAX LC_TIME

#SenãoDefinido _LCONV_DEFINED
#Defina _LCONV_DEFINED
  Estrutura lconv {
    Caractere *decimal_point;
    Caractere *thousands_sep;
    Caractere *grouping;
    Caractere *int_curr_symbol;
    Caractere *currency_symbol;
    Caractere *mon_decimal_point;
    Caractere *mon_thousands_sep;
    Caractere *mon_grouping;
    Caractere *positive_sign;
    Caractere *negative_sign;
    Caractere int_frac_digits;
    Caractere frac_digits;
    Caractere p_cs_precedes;
    Caractere p_sep_by_space;
    Caractere n_cs_precedes;
    Caractere n_sep_by_space;
    Caractere p_sign_posn;
    Caractere n_sign_posn;
  };
#FimSe

#SenãoDefinido _CONFIG_LOCALE_SWT
#Defina _CONFIG_LOCALE_SWT

#Defina _ENABLE_PER_THREAD_LOCALE 0x1
#Defina _DISABLE_PER_THREAD_LOCALE 0x2
#Defina _ENABLE_PER_THREAD_LOCALE_GLOBAL 0x10
#Defina _DISABLE_PER_THREAD_LOCALE_GLOBAL 0x20
#Defina _ENABLE_PER_THREAD_LOCALE_NEW 0x100
#Defina _DISABLE_PER_THREAD_LOCALE_NEW 0x200

#FimSe

  Inteiro __cdecl _configthreadlocale(Inteiro _Flag);
  Caractere *__cdecl setlocale(Inteiro _Category,Constante Caractere *_Locale);
  _CRTIMP Estrutura lconv *__cdecl localeconv(Vazio);
  _locale_t __cdecl _get_current_locale(Vazio);
  _locale_t __cdecl _create_locale(Inteiro _Category,Constante Caractere *_Locale);
  Vazio __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(Vazio);
  _locale_t __cdecl __create_locale(Inteiro _Category,Constante Caractere *_Locale);
  Vazio __cdecl __free_locale(_locale_t _Locale);

#SenãoDefinido _WLOCALE_DEFINED
#Defina _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(Inteiro _Category,Constante wchar_t *_Locale);
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)
#FimSe
