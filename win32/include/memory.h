/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_MEMORY
#Defina _INC_MEMORY

#Inclua <_mingw.h>

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido _CONST_RETURN
#Defina _CONST_RETURN
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

#SeDefinido __cplusplus
}
#FimSe
#FimSe
