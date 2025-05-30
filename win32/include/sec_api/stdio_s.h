/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_STDIO_S
#Defina _INC_STDIO_S

#Inclua <stdio.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido _STDIO_S_DEFINED
#Defina _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  Inteiro __cdecl fprintf_s(FILE *_File,Constante Caractere *_Format,...);
  size_t __cdecl fread_s(Vazio *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File);
  _CRTIMP Inteiro __cdecl _fscanf_s_l(FILE *_File,Constante Caractere *_Format,_locale_t _Locale,...);
  Inteiro __cdecl printf_s(Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _scanf_l(Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _scanf_s_l(Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _snprintf_s(Caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _snprintf_c(Caractere *_DstBuf,size_t _MaxCount,Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _vsnprintf_c(Caractere *_DstBuf,size_t _MaxCount,Constante Caractere *_Format,va_list _ArgList);
  Inteiro __cdecl sprintf_s(Caractere *_DstBuf,size_t _DstSize,Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _fscanf_l(FILE *_File,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _sscanf_l(Constante Caractere *_Src,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _sscanf_s_l(Constante Caractere *_Src,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _snscanf_s(Constante Caractere *_Src,size_t _MaxCount,Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _snscanf_l(Constante Caractere *_Src,size_t _MaxCount,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _snscanf_s_l(Constante Caractere *_Src,size_t _MaxCount,Constante Caractere *_Format,_locale_t _Locale,...);
  Inteiro __cdecl vfprintf_s(FILE *_File,Constante Caractere *_Format,va_list _ArgList);
  Inteiro __cdecl vprintf_s(Constante Caractere *_Format,va_list _ArgList);
  Inteiro __cdecl vsnprintf_s(Caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,Constante Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vsnprintf_s(Caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,Constante Caractere *_Format,va_list _ArgList);
  Inteiro __cdecl vsprintf_s(Caractere *_DstBuf,size_t _Size,Constante Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _fprintf_p(FILE *_File,Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _printf_p(Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _sprintf_p(Caractere *_Dst,size_t _MaxCount,Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _vfprintf_p(FILE *_File,Constante Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vprintf_p(Constante Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vsprintf_p(Caractere *_Dst,size_t _MaxCount,Constante Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _scprintf_p(Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _vscprintf_p(Constante Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _printf_l(Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _printf_p_l(Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vprintf_l(Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vprintf_p_l(Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _fprintf_l(FILE *_File,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _fprintf_p_l(FILE *_File,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vfprintf_l(FILE *_File,Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vfprintf_p_l(FILE *_File,Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _sprintf_l(Caractere *_DstBuf,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _sprintf_p_l(Caractere *_DstBuf,size_t _MaxCount,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vsprintf_l(Caractere *_DstBuf,Constante Caractere *_Format,_locale_t,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vsprintf_p_l(Caractere *_DstBuf,size_t _MaxCount,Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _scprintf_l(Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _scprintf_p_l(Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vscprintf_l(Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vscprintf_p_l(Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _printf_s_l(Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vprintf_s_l(Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _fprintf_s_l(FILE *_File,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vfprintf_s_l(FILE *_File,Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _sprintf_s_l(Caractere *_DstBuf,size_t _DstSize,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vsprintf_s_l(Caractere *_DstBuf,size_t _DstSize,Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _snprintf_s_l(Caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vsnprintf_s_l(Caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _snprintf_l(Caractere *_DstBuf,size_t _MaxCount,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _snprintf_c_l(Caractere *_DstBuf,size_t _MaxCount,Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vsnprintf_l(Caractere *_DstBuf,size_t _MaxCount,Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vsnprintf_c_l(Caractere *_DstBuf,size_t _MaxCount,Constante Caractere *,_locale_t _Locale,va_list _ArgList);

#SenãoDefinido _WSTDIO_S_DEFINED
#Defina _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t _SizeInWords);
  Inteiro __cdecl fwprintf_s(FILE *_File,Constante wchar_t *_Format,...);
  Inteiro __cdecl wprintf_s(Constante wchar_t *_Format,...);
  Inteiro __cdecl vwprintf_s(Constante wchar_t *_Format,va_list _ArgList);
  Inteiro __cdecl swprintf_s(wchar_t *_Dst,size_t _SizeInWords,Constante wchar_t *_Format,...);
  Inteiro __cdecl vswprintf_s(wchar_t *_Dst,size_t _SizeInWords,Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _snwprintf_s(wchar_t *_DstBuf,size_t _DstSizeInWords,size_t _MaxCount,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vsnwprintf_s(wchar_t *_DstBuf,size_t _DstSizeInWords,size_t _MaxCount,Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _wprintf_s_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vwprintf_s_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _fwprintf_s_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vfwprintf_s_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _fwscanf_s_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _swscanf_s_l(Constante wchar_t *_Src,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _snwscanf_s(Constante wchar_t *_Src,size_t _MaxCount,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _snwscanf_s_l(Constante wchar_t *_Src,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _wscanf_s_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,Constante wchar_t *_Filename,Constante wchar_t *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,Constante wchar_t *_Filename,Constante wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,size_t _SizeInWords);
  _CRTIMP Inteiro __cdecl _fwprintf_p(FILE *_File,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _wprintf_p(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vfwprintf_p(FILE *_File,Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vwprintf_p(Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _swprintf_p(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _scwprintf_p(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vscwprintf_p(Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _wprintf_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _wprintf_p_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vwprintf_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vwprintf_p_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _fwprintf_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _fwprintf_p_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vfwprintf_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vfwprintf_p_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _scwprintf_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _scwprintf_p_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vscwprintf_p_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl __swprintf_l(wchar_t *_Dest,Constante wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP Inteiro __cdecl __vswprintf_l(wchar_t *_Dest,Constante wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP Inteiro __cdecl _vscwprintf_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _fwscanf_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _swscanf_l(Constante wchar_t *_Src,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _snwscanf_l(Constante wchar_t *_Src,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _wscanf_l(Constante wchar_t *_Format,_locale_t _Locale,...);
#FimSe
#FimSe

  _CRTIMP size_t __cdecl _fread_nolock_s(Vazio *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File);

#SeDefinido __cplusplus
}
#FimSe
#FimSe
#FimSe
