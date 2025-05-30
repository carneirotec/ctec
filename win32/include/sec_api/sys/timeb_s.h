/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#SenãoDefinido _TIMEB_H_S
#Defina _TIMEB_H_S

#Inclua <sys/timeb.h>

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido _USE_32BIT_TIME_T
#Defina _ftime_s _ftime32_s
#Senão
#Defina _ftime_s _ftime64_s
#FimSe

  _CRTIMP errno_t __cdecl _ftime32_s(Estrutura __timeb32 *_Time);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ftime64_s(Estrutura __timeb64 *_Time);
#FimSe
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#FimSe
