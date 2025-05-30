/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_WCHAR_S
#Defina _INC_WCHAR_S

#Inclua <wchar.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido _WIO_S_DEFINED
#Defina _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(Constante wchar_t *_Filename,Inteiro _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t _SizeInWords);
#FimSe

#SenãoDefinido _WCONIO_S_DEFINED
#Defina _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t _SizeInWords,size_t *_SizeRead);
  _CRTIMP Inteiro __cdecl _cwprintf_s(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _cwscanf_s(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _cwscanf_s_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcwprintf_s(Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _cwprintf_s_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcwprintf_s_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#FimSe

#SenãoDefinido _WSTDIO_S_DEFINED
#Defina _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t _SizeInWords);
  Inteiro __cdecl fwprintf_s(FILE *_File,Constante wchar_t *_Format,...);
  Inteiro __cdecl wprintf_s(Constante wchar_t *_Format,...);
  Inteiro __cdecl vfwprintf_s(FILE *_File,Constante wchar_t *_Format,va_list _ArgList);
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
#FimSe

#SenãoDefinido _WSTDLIB_S_DEFINED
#Defina _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (Inteiro _Val,wchar_t *_DstBuf,size_t _SizeInWords,Inteiro _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (Longo _Val,wchar_t *_DstBuf,size_t _SizeInWords,Inteiro _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (SemSinal Longo _Val,wchar_t *_DstBuf,size_t _SizeInWords,Inteiro _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t _DstSizeInWords,Constante wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *_BufferSizeInWords,Constante wchar_t *_VarName);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t _SizeInWords,Inteiro _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(SemSinal __int64 _Val,wchar_t *_DstBuf,size_t _SizeInWords,Inteiro _Radix);
#FimSe
#FimSe

#SenãoDefinido _POSIX_
#SenãoDefinido _WSTDLIBP_S_DEFINED
#Defina _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t _SizeInWords,Constante wchar_t *_Drive,Constante wchar_t *_Dir,Constante wchar_t *_Filename,Constante wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(Constante wchar_t *_Name,Constante wchar_t *_Value);
  _CRTIMP errno_t __cdecl _wsearchenv_s(Constante wchar_t *_Filename,Constante wchar_t *_EnvVar,wchar_t *_ResultPath,size_t _SizeInWords);
  _CRTIMP errno_t __cdecl _wsplitpath_s(Constante wchar_t *_FullPath,wchar_t *_Drive,size_t _DriveSizeInWords,wchar_t *_Dir,size_t _DirSizeInWords,wchar_t *_Filename,size_t _FilenameSizeInWords,wchar_t *_Ext,size_t _ExtSizeInWords);
#FimSe
#FimSe

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

#SenãoDefinido _WTIME_S_DEFINED
#Defina _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t _SizeInWords,Constante Estrutura tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t _SizeInWords,Constante __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t _SizeInWords);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t _SizeInWords);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t _SizeInWords,Constante __time64_t *_Time);
#FimSe

#Se !Definido (RC_INVOKED) && !Definido (_INC_WTIME_S_INL)
#Defina _INC_WTIME_S_INL
#SeDefinido _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t _SizeInWords,Constante time_t *_Time) { Retorno _wctime32_s(_Buffer,_SizeInWords,_Time); }
#Senão
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t _SizeInWords,Constante time_t *_Time) { Retorno _wctime64_s(_Buffer,_SizeInWords,_Time); }
#FimSe
#FimSe
#FimSe

  _CRTIMP errno_t __cdecl mbsrtowcs_s(size_t *_Retval,wchar_t *_Dst,size_t _SizeInWords,Constante Caractere **_PSrc,size_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(size_t *_Retval,Caractere *_Dst,size_t _SizeInBytes,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(size_t *_Retval,Caractere *_Dst,size_t _SizeInBytes,Constante wchar_t **_Src,size_t _Size,mbstate_t *_State);

#SeDefinido __cplusplus
}
#FimSe

#FimSe
#FimSe
