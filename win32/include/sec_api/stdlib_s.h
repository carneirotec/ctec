/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_STDLIB_S
#Defina _INC_STDLIB_S

#Inclua <stdlib.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  _CRTIMP errno_t __cdecl _dupenv_s(Caractere **_PBuffer,size_t *_PBufferSizeInBytes,Constante Caractere *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(Inteiro _Value,Caractere *_DstBuf,size_t _Size,Inteiro _Radix);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,Caractere *_DstBuf,size_t _Size,Inteiro _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(SemSinal __int64 _Val,Caractere *_DstBuf,size_t _Size,Inteiro _Radix);
#FimSe
  _CRTIMP errno_t __cdecl _ltoa_s(Longo _Val,Caractere *_DstBuf,size_t _Size,Inteiro _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *_PtNumOfCharConverted,wchar_t *_DstBuf,size_t _SizeInWords,Constante Caractere *_SrcBuf,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *_PtNumOfCharConverted,wchar_t *_DstBuf,size_t _SizeInWords,Constante Caractere *_SrcBuf,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(SemSinal Longo _Val,Caractere *_DstBuf,size_t _Size,Inteiro _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(Inteiro *_SizeConverted,Caractere *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *_PtNumOfCharConverted,Caractere *_Dst,size_t _DstSizeInBytes,Constante wchar_t *_Src,size_t _MaxCountInBytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *_PtNumOfCharConverted,Caractere *_Dst,size_t _DstSizeInBytes,Constante wchar_t *_Src,size_t _MaxCountInBytes,_locale_t _Locale);

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
  _CRTIMP errno_t __cdecl _ecvt_s(Caractere *_DstBuf,size_t _Size,Duplo _Val,Inteiro _NumOfDights,Inteiro *_PtDec,Inteiro *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(Caractere *_DstBuf,size_t _Size,Duplo _Val,Inteiro _NumOfDec,Inteiro *_PtDec,Inteiro *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(Caractere *_DstBuf,size_t _Size,Duplo _Val,Inteiro _NumOfDigits);
  _CRTIMP errno_t __cdecl _makepath_s(Caractere *_PathResult,size_t _Size,Constante Caractere *_Drive,Constante Caractere *_Dir,Constante Caractere *_Filename,Constante Caractere *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(Constante Caractere *_Name,Constante Caractere *_Value);
  _CRTIMP errno_t __cdecl _searchenv_s(Constante Caractere *_Filename,Constante Caractere *_EnvVar,Caractere *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(Constante Caractere *_FullPath,Caractere *_Drive,size_t _DriveSize,Caractere *_Dir,size_t _DirSize,Caractere *_Filename,size_t _FilenameSize,Caractere *_Ext,size_t _ExtSize);

#SenãoDefinido _WSTDLIBP_S_DEFINED
#Defina _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t _SizeInWords,Constante wchar_t *_Drive,Constante wchar_t *_Dir,Constante wchar_t *_Filename,Constante wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(Constante wchar_t *_Name,Constante wchar_t *_Value);
  _CRTIMP errno_t __cdecl _wsearchenv_s(Constante wchar_t *_Filename,Constante wchar_t *_EnvVar,wchar_t *_ResultPath,size_t _SizeInWords);
  _CRTIMP errno_t __cdecl _wsplitpath_s(Constante wchar_t *_FullPath,wchar_t *_Drive,size_t _DriveSizeInWords,wchar_t *_Dir,size_t _DirSizeInWords,wchar_t *_Filename,size_t _FilenameSizeInWords,wchar_t *_Ext,size_t _ExtSizeInWords);
#FimSe
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#FimSe
#FimSe
