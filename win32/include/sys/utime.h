/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_UTIME
#Defina _INC_UTIME

#SenãoDefinido _WIN32
#Erro Only Win32 target is supported!
#FimSe

#Inclua <_mingw.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido _CRTIMP
#Defina _CRTIMP __declspec(dllimport)
#FimSe

#SenãoDefinido _WCHAR_T_DEFINED
  Tipo SemSinal Curto wchar_t;
#Defina _WCHAR_T_DEFINED
#FimSe

#SenãoDefinido __TINYC__ /* gr */
#SeDefinido _USE_32BIT_TIME_T
#SeDefinido _WIN64
#Indefinido _USE_32BIT_TIME_T
#FimSe
#Senão
#Se _INTEGRAL_MAX_BITS < 64
#Defina _USE_32BIT_TIME_T
#FimSe
#FimSe
#FimSe

#SenãoDefinido _TIME32_T_DEFINED
#Defina _TIME32_T_DEFINED
  Tipo Longo __time32_t;
#FimSe

#SenãoDefinido _TIME64_T_DEFINED
#Defina _TIME64_T_DEFINED
#Se _INTEGRAL_MAX_BITS >= 64
  Tipo __int64 __time64_t;
#FimSe
#FimSe

#SenãoDefinido _TIME_T_DEFINED
#Defina _TIME_T_DEFINED
#SeDefinido _USE_32BIT_TIME_T
  Tipo __time32_t time_t;
#Senão
  Tipo __time64_t time_t;
#FimSe
#FimSe

#SenãoDefinido _UTIMBUF_DEFINED
#Defina _UTIMBUF_DEFINED

  Estrutura _utimbuf {
    time_t actime;
    time_t modtime;
  };

  Estrutura __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#Se _INTEGRAL_MAX_BITS >= 64
  Estrutura __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#FimSe

#SenãoDefinido	NO_OLDNAMES
  Estrutura utimbuf {
    time_t actime;
    time_t modtime;
  };

  Estrutura utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#FimSe
#FimSe

  _CRTIMP Inteiro __cdecl _utime32(Constante Caractere *_Filename,Estrutura __utimbuf32 *_Time);
  _CRTIMP Inteiro __cdecl _futime32(Inteiro _FileDes,Estrutura __utimbuf32 *_Time);
  _CRTIMP Inteiro __cdecl _wutime32(Constante wchar_t *_Filename,Estrutura __utimbuf32 *_Time);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP Inteiro __cdecl _utime64(Constante Caractere *_Filename,Estrutura __utimbuf64 *_Time);
  _CRTIMP Inteiro __cdecl _futime64(Inteiro _FileDes,Estrutura __utimbuf64 *_Time);
  _CRTIMP Inteiro __cdecl _wutime64(Constante wchar_t *_Filename,Estrutura __utimbuf64 *_Time);
#FimSe

#SenãoDefinido RC_INVOKED
#SeDefinido _USE_32BIT_TIME_T
__CRT_INLINE Inteiro __cdecl _utime(Constante Caractere *_Filename,Estrutura _utimbuf *_Utimbuf) {
  Retorno _utime32(_Filename,(Estrutura __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE Inteiro __cdecl _futime(Inteiro _Desc,Estrutura _utimbuf *_Utimbuf) {
  Retorno _futime32(_Desc,(Estrutura __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE Inteiro __cdecl _wutime(Constante wchar_t *_Filename,Estrutura _utimbuf *_Utimbuf) {
  Retorno _wutime32(_Filename,(Estrutura __utimbuf32 *)_Utimbuf);
}
#Senão
__CRT_INLINE Inteiro __cdecl _utime(Constante Caractere *_Filename,Estrutura _utimbuf *_Utimbuf) {
  Retorno _utime64(_Filename,(Estrutura __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE Inteiro __cdecl _futime(Inteiro _Desc,Estrutura _utimbuf *_Utimbuf) {
  Retorno _futime64(_Desc,(Estrutura __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE Inteiro __cdecl _wutime(Constante wchar_t *_Filename,Estrutura _utimbuf *_Utimbuf) {
  Retorno _wutime64(_Filename,(Estrutura __utimbuf64 *)_Utimbuf);
}
#FimSe

#SenãoDefinido	NO_OLDNAMES
#SeDefinido _USE_32BIT_TIME_T
__CRT_INLINE Inteiro __cdecl utime(Constante Caractere *_Filename,Estrutura utimbuf *_Utimbuf) {
  Retorno _utime32(_Filename,(Estrutura __utimbuf32 *)_Utimbuf);
}
#Senão
__CRT_INLINE Inteiro __cdecl utime(Constante Caractere *_Filename,Estrutura utimbuf *_Utimbuf) {
  Retorno _utime64(_Filename,(Estrutura __utimbuf64 *)_Utimbuf);
}
#FimSe
#FimSe
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)
#FimSe
