/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_STRING
#Defina _INC_STRING

#Inclua <_mingw.h>

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido _NLSCMP_DEFINED
#Defina _NLSCMP_DEFINED
#Defina _NLSCMPERROR 2147483647
#FimSe

#SenãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#Defina _WConst_return _CONST_RETURN

#SenãoDefinido _CRT_MEMORY_DEFINED
#Defina _CRT_MEMORY_DEFINED
  _CRTIMP Vazio *__cdecl _memccpy(Vazio *_Dst,Constante Vazio *_Src,Inteiro _Val,size_t _MaxCount);
  _CONST_RETURN Vazio *__cdecl memchr(Constante Vazio *_Buf ,Inteiro _Val,size_t _MaxCount);
  _CRTIMP Inteiro __cdecl _memicmp(Constante Vazio *_Buf1,Constante Vazio *_Buf2,size_t _Size);
  _CRTIMP Inteiro __cdecl _memicmp_l(Constante Vazio *_Buf1,Constante Vazio *_Buf2,size_t _Size,_locale_t _Locale);
  Inteiro __cdecl memcmp(Constante Vazio *_Buf1,Constante Vazio *_Buf2,size_t _Size);
  Vazio *__cdecl memcpy(Vazio *_Dst,Constante Vazio *_Src,size_t _Size);
  Vazio *__cdecl memset(Vazio *_Dst,Inteiro _Val,size_t _Size);
#SenãoDefinido	NO_OLDNAMES
  Vazio *__cdecl memccpy(Vazio *_Dst,Constante Vazio *_Src,Inteiro _Val,size_t _Size);
  Inteiro __cdecl memicmp(Constante Vazio *_Buf1,Constante Vazio *_Buf2,size_t _Size);
#FimSe
#FimSe
  Caractere *__cdecl _strset(Caractere *_Str,Inteiro _Val);
  Caractere *__cdecl strcpy(Caractere *_Dest,Constante Caractere *_Source);
  Caractere *__cdecl strcat(Caractere *_Dest,Constante Caractere *_Source);
  Inteiro __cdecl strcmp(Constante Caractere *_Str1,Constante Caractere *_Str2);
  size_t __cdecl strlen(Constante Caractere *_Str);
#Se 0
  size_t __cdecl strnlen(Constante Caractere *_Str,size_t _MaxCount);
#FimSe
  Vazio *__cdecl memmove(Vazio *_Dst,Constante Vazio *_Src,size_t _Size);
  _CRTIMP Caractere *__cdecl _strdup(Constante Caractere *_Src);
  _CONST_RETURN Caractere *__cdecl strchr(Constante Caractere *_Str,Inteiro _Val);
  _CRTIMP Inteiro __cdecl _stricmp(Constante Caractere *_Str1,Constante Caractere *_Str2);
  _CRTIMP Inteiro __cdecl _strcmpi(Constante Caractere *_Str1,Constante Caractere *_Str2);
  _CRTIMP Inteiro __cdecl _stricmp_l(Constante Caractere *_Str1,Constante Caractere *_Str2,_locale_t _Locale);
  Inteiro __cdecl strcoll(Constante Caractere *_Str1,Constante Caractere *_Str2);
  _CRTIMP Inteiro __cdecl _strcoll_l(Constante Caractere *_Str1,Constante Caractere *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _stricoll(Constante Caractere *_Str1,Constante Caractere *_Str2);
  _CRTIMP Inteiro __cdecl _stricoll_l(Constante Caractere *_Str1,Constante Caractere *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _strncoll (Constante Caractere *_Str1,Constante Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro __cdecl _strncoll_l(Constante Caractere *_Str1,Constante Caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _strnicoll (Constante Caractere *_Str1,Constante Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro __cdecl _strnicoll_l(Constante Caractere *_Str1,Constante Caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  size_t __cdecl strcspn(Constante Caractere *_Str,Constante Caractere *_Control);
  _CRTIMP Caractere *__cdecl _strerror(Constante Caractere *_ErrMsg);
  Caractere *__cdecl strerror(Inteiro);
  _CRTIMP Caractere *__cdecl _strlwr(Caractere *_String);
  Caractere *strlwr_l(Caractere *_String,_locale_t _Locale);
  Caractere *__cdecl strncat(Caractere *_Dest,Constante Caractere *_Source,size_t _Count);
  Inteiro __cdecl strncmp(Constante Caractere *_Str1,Constante Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro __cdecl _strnicmp(Constante Caractere *_Str1,Constante Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro __cdecl _strnicmp_l(Constante Caractere *_Str1,Constante Caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  Caractere *strncpy(Caractere *_Dest,Constante Caractere *_Source,size_t _Count);
  _CRTIMP Caractere *__cdecl _strnset(Caractere *_Str,Inteiro _Val,size_t _MaxCount);
  _CONST_RETURN Caractere *__cdecl strpbrk(Constante Caractere *_Str,Constante Caractere *_Control);
  _CONST_RETURN Caractere *__cdecl strrchr(Constante Caractere *_Str,Inteiro _Ch);
  _CRTIMP Caractere *__cdecl _strrev(Caractere *_Str);
  size_t __cdecl strspn(Constante Caractere *_Str,Constante Caractere *_Control);
  _CONST_RETURN Caractere *__cdecl strstr(Constante Caractere *_Str,Constante Caractere *_SubStr);
  Caractere *__cdecl strtok(Caractere *_Str,Constante Caractere *_Delim);
  _CRTIMP Caractere *__cdecl _strupr(Caractere *_String);
  _CRTIMP Caractere *_strupr_l(Caractere *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(Caractere *_Dst,Constante Caractere *_Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _strxfrm_l(Caractere *_Dst,Constante Caractere *_Src,size_t _MaxCount,_locale_t _Locale);

#SenãoDefinido	NO_OLDNAMES
  Caractere *__cdecl strdup(Constante Caractere *_Src);
  Inteiro __cdecl strcmpi(Constante Caractere *_Str1,Constante Caractere *_Str2);
  Inteiro __cdecl stricmp(Constante Caractere *_Str1,Constante Caractere *_Str2);
  Caractere *__cdecl strlwr(Caractere *_Str);
  Inteiro __cdecl strnicmp(Constante Caractere *_Str1,Constante Caractere *_Str,size_t _MaxCount);
  __CRT_INLINE Inteiro __cdecl strncasecmp (Constante Caractere *__sz1, Constante Caractere *__sz2, size_t __sizeMaxCompare) { Retorno _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE Inteiro __cdecl strcasecmp (Constante Caractere *__sz1, Constante Caractere *__sz2) { Retorno _stricmp (__sz1, __sz2); }
  Caractere *__cdecl strnset(Caractere *_Str,Inteiro _Val,size_t _MaxCount);
  Caractere *__cdecl strrev(Caractere *_Str);
  Caractere *__cdecl strset(Caractere *_Str,Inteiro _Val);
  Caractere *__cdecl strupr(Caractere *_Str);
#FimSe

#SenãoDefinido _WSTRING_DEFINED
#Defina _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(Constante wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,Constante wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(Constante wchar_t *_Str,wchar_t _Ch);
  Inteiro __cdecl wcscmp(Constante wchar_t *_Str1,Constante wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,Constante wchar_t *_Source);
  size_t __cdecl wcscspn(Constante wchar_t *_Str,Constante wchar_t *_Control);
  size_t __cdecl wcslen(Constante wchar_t *_Str);
  size_t __cdecl wcsnlen(Constante wchar_t *_Src,size_t _MaxCount);
  wchar_t *wcsncat(wchar_t *_Dest,Constante wchar_t *_Source,size_t _Count);
  Inteiro __cdecl wcsncmp(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount);
  wchar_t *wcsncpy(wchar_t *_Dest,Constante wchar_t *_Source,size_t _Count);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(Constante wchar_t *_Str,Constante wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(Constante wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(Constante wchar_t *_Str,Constante wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(Constante wchar_t *_Str,Constante wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,Constante wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(Inteiro _ErrNum);
  _CRTIMP wchar_t *__cdecl __wcserror(Constante wchar_t *_Str);
  _CRTIMP Inteiro __cdecl _wcsicmp(Constante wchar_t *_Str1,Constante wchar_t *_Str2);
  _CRTIMP Inteiro __cdecl _wcsicmp_l(Constante wchar_t *_Str1,Constante wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _wcsnicmp(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro __cdecl _wcsnicmp_l(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,Constante wchar_t *_Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,Constante wchar_t *_Src,size_t _MaxCount,_locale_t _Locale);
  Inteiro __cdecl wcscoll(Constante wchar_t *_Str1,Constante wchar_t *_Str2);
  _CRTIMP Inteiro __cdecl _wcscoll_l(Constante wchar_t *_Str1,Constante wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _wcsicoll(Constante wchar_t *_Str1,Constante wchar_t *_Str2);
  _CRTIMP Inteiro __cdecl _wcsicoll_l(Constante wchar_t *_Str1,Constante wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _wcsncoll(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro __cdecl _wcsncoll_l(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _wcsnicoll(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro __cdecl _wcsnicoll_l(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);

#SenãoDefinido	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(Constante wchar_t *_Str);
#Defina wcswcs wcsstr
  Inteiro __cdecl wcsicmp(Constante wchar_t *_Str1,Constante wchar_t *_Str2);
  Inteiro __cdecl wcsnicmp(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  Inteiro __cdecl wcsicoll(Constante wchar_t *_Str1,Constante wchar_t *_Str2);
#FimSe
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Inclua <sec_api/string_s.h>
#FimSe
