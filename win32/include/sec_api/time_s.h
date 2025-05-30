/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _TIME_H__S
#Defina _TIME_H__S

#Inclua <time.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  _CRTIMP errno_t __cdecl _ctime32_s(Caractere *_Buf,size_t _SizeInBytes,Constante __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(Estrutura tm *_Tm,Constante __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(Estrutura tm *_Tm,Constante __time32_t *_Time);
  _CRTIMP errno_t __cdecl _strdate_s(Caractere *_Buf,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _strtime_s(Caractere *_Buf ,size_t _SizeInBytes);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(Caractere *_Buf,size_t _SizeInBytes,Constante __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(Estrutura tm *_Tm,Constante __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(Estrutura tm *_Tm,Constante __time64_t *_Time);
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

#SenãoDefinido RC_INVOKED
#SeDefinido _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl localtime_s(Estrutura tm *_Tm,Constante time_t *_Time) { Retorno _localtime32_s(_Tm,_Time); }
#Senão
__CRT_INLINE errno_t __cdecl localtime_s(Estrutura tm *_Tm,Constante time_t *_Time) { Retorno _localtime64_s(_Tm,_Time); }
#FimSe
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#FimSe
#FimSe
