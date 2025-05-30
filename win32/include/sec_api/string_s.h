/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_STRING_S
#Defina _INC_STRING_S

#Inclua <string.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  _CRTIMP errno_t __cdecl _strset_s(Caractere *_Dst,size_t _DstSize,Inteiro _Value);
  _CRTIMP errno_t __cdecl _strerror_s(Caractere *_Buf,size_t _SizeInBytes,Constante Caractere *_ErrMsg);
  _CRTIMP errno_t __cdecl _strlwr_s(Caractere *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strlwr_s_l(Caractere *_Str,size_t _Size,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(Caractere *_Str,size_t _Size,Inteiro _Val,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _strupr_s(Caractere *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strupr_s_l(Caractere *_Str,size_t _Size,_locale_t _Locale);
#SenãoDefinido _WSTRING_S_DEFINED
#Defina _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,Constante wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t _SizeInWords,Inteiro _ErrNum);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t _SizeInWords,Constante wchar_t *_ErrMsg);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t _DstSizeInWords,wchar_t _Val,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t _SizeInWords,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t _SizeInWords);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t _SizeInWords,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#FimSe

#SeDefinido __cplusplus
}
#FimSe
#FimSe
#FimSe
