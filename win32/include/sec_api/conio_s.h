/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#SenãoDefinido _INC_CONIO_S
#Defina _INC_CONIO_S

#Inclua <conio.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  _CRTIMP errno_t __cdecl _cgets_s(Caractere *_Buffer,size_t _Size,size_t *_SizeRead);
  _CRTIMP Inteiro __cdecl _cprintf_s(Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _cscanf_s(Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _cscanf_s_l(Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcprintf_s(Constante Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _cprintf_s_l(Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcprintf_s_l(Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);

#SenãoDefinido _WCONIO_DEFINED_S
#Defina _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t _SizeInWords,size_t *_SizeRead);
  _CRTIMP Inteiro __cdecl _cwprintf_s(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _cwscanf_s(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _cwscanf_s_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcwprintf_s(Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _cwprintf_s_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcwprintf_s_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#FimSe
#FimSe
