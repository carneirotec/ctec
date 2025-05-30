/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_MBSTRING_S
#Defina _INC_MBSTRING_S

#Inclua <mbstring.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido _MBSTRING_S_DEFINED
#Defina _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Constante SemSinal Caractere *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Constante SemSinal Caractere *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Constante SemSinal Caractere *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Constante SemSinal Caractere *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(SemSinal Caractere *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(SemSinal Caractere *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Constante SemSinal Caractere *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Constante SemSinal Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Constante SemSinal Caractere *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Constante SemSinal Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,SemSinal Inteiro _Ch,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,SemSinal Inteiro _Ch,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Constante SemSinal Caractere *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Constante SemSinal Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Constante SemSinal Caractere *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Constante SemSinal Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,SemSinal Inteiro _Val,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,SemSinal Inteiro _Val,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,SemSinal Inteiro _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,SemSinal Inteiro _Val,_locale_t _Locale);
  _CRTIMP SemSinal Caractere *__cdecl _mbstok_s(SemSinal Caractere *_Str,Constante SemSinal Caractere *_Delim,SemSinal Caractere **_Context);
  _CRTIMP SemSinal Caractere *__cdecl _mbstok_s_l(SemSinal Caractere *_Str,Constante SemSinal Caractere *_Delim,SemSinal Caractere **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(SemSinal Caractere *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(SemSinal Caractere *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Inteiro *_PCopied,Constante SemSinal Caractere *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(SemSinal Caractere *_Dst,size_t _DstSizeInBytes,Inteiro *_PCopied,Constante SemSinal Caractere *_Src,_locale_t _Locale);
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#FimSe
#FimSe
