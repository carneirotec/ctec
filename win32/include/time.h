/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _TIME_H_
#Defina _TIME_H_

#Inclua <_mingw.h>

#SenãoDefinido _WIN32
#Erro Only Win32 target is supported!
#FimSe

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido _CRTIMP
#Defina _CRTIMP __declspec(dllimport)
#FimSe

#SenãoDefinido _WCHAR_T_DEFINED
#Defina _WCHAR_T_DEFINED
  Tipo SemSinal Curto wchar_t;
#FimSe

#SenãoDefinido _TIME32_T_DEFINED
#Defina _TIME32_T_DEFINED
  Tipo Longo __time32_t;
#FimSe

#SenãoDefinido _TIME64_T_DEFINED
#Defina _TIME64_T_DEFINED
#Se _INTEGRAL_MAX_BITS >= 64
#Se Definido(__GNUC__) && Definido(__STRICT_ANSI__)
  Tipo Inteiro _time64_t __attribute__ ((mode (DI)));
#Senão
  Tipo __int64 __time64_t;
#FimSe
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

#SenãoDefinido _CLOCK_T_DEFINED
#Defina _CLOCK_T_DEFINED
  Tipo Longo clock_t;
#FimSe

#SenãoDefinido _SIZE_T_DEFINED
#Defina _SIZE_T_DEFINED
#Indefinido size_t
#SeDefinido _WIN64
#Se Definido(__GNUC__) && Definido(__STRICT_ANSI__)
  Tipo SemSinal Inteiro size_t __attribute__ ((mode (DI)));
#Senão
  Tipo SemSinal __int64 size_t;
#FimSe
#Senão
  Tipo SemSinal Inteiro size_t;
#FimSe
#FimSe

#SenãoDefinido _SSIZE_T_DEFINED
#Defina _SSIZE_T_DEFINED
#Indefinido ssize_t
#SeDefinido _WIN64
#Se Definido(__GNUC__) && Definido(__STRICT_ANSI__)
  Tipo Inteiro ssize_t __attribute__ ((mode (DI)));
#Senão
  Tipo __int64 ssize_t;
#FimSe
#Senão
  Tipo Inteiro ssize_t;
#FimSe
#FimSe

#SenãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#SeDefinido _USE_32BIT_TIME_T
#Defina _localtime32 localtime
#Defina _difftime32     difftime
#Defina _ctime32        ctime
#Defina _gmtime32       gmtime
#Defina _mktime32       mktime
#Defina _time32 time
#FimSe

#SenãoDefinido _TM_DEFINED
#Defina _TM_DEFINED
  Estrutura tm {
    Inteiro tm_sec;
    Inteiro tm_min;
    Inteiro tm_hour;
    Inteiro tm_mday;
    Inteiro tm_mon;
    Inteiro tm_year;
    Inteiro tm_wday;
    Inteiro tm_yday;
    Inteiro tm_isdst;
  };
#FimSe

#Defina CLOCKS_PER_SEC 1000

  __MINGW_IMPORT Inteiro _daylight;
  __MINGW_IMPORT Longo _dstbias;
  __MINGW_IMPORT Longo _timezone;
  __MINGW_IMPORT Caractere * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(Inteiro *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(Longo *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(Longo *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *_ReturnValue,Caractere *_Buffer,size_t _SizeInBytes,Inteiro _Index);
  Caractere *__cdecl asctime(Constante Estrutura tm *_Tm);
  _CRTIMP Caractere *__cdecl _ctime32(Constante __time32_t *_Time);
  clock_t __cdecl clock(Vazio);
  _CRTIMP Duplo __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP Estrutura tm *__cdecl _gmtime32(Constante __time32_t *_Time);
  _CRTIMP Estrutura tm *__cdecl _localtime32(Constante __time32_t *_Time);
  size_t __cdecl strftime(Caractere *_Buf,size_t _SizeInBytes,Constante Caractere *_Format,Constante Estrutura tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(Caractere *_Buf,size_t _Max_size,Constante Caractere *_Format,Constante Estrutura tm *_Tm,_locale_t _Locale);
  _CRTIMP Caractere *__cdecl _strdate(Caractere *_Buffer);
  _CRTIMP Caractere *__cdecl _strtime(Caractere *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(Estrutura tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(Estrutura tm *_Tm);
#Se Definido (_POSIX_) || Definido(__GNUC__)
  Vazio __cdecl tzset(Vazio);
#Senão
  _CRTIMP Vazio __cdecl _tzset(Vazio);
#FimSe

#Se _INTEGRAL_MAX_BITS >= 64
  Duplo __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP Caractere *__cdecl _ctime64(Constante __time64_t *_Time);
  _CRTIMP Estrutura tm *__cdecl _gmtime64(Constante __time64_t *_Time);
  _CRTIMP Estrutura tm *__cdecl _localtime64(Constante __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(Estrutura tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(Estrutura tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#FimSe
  SemSinal __cdecl _getsystime(Estrutura tm *_Tm);
  SemSinal __cdecl _setsystime(Estrutura tm *_Tm,SemSinal _MilliSec);

#SenãoDefinido _SIZE_T_DEFINED
#Defina _SIZE_T_DEFINED
#SeDefinido _WIN64
#Se Definido(__GNUC__) && Definido(__STRICT_ANSI__)
  Tipo SemSinal Inteiro size_t __attribute__ ((mode (DI)));
#Senão
  Tipo SemSinal __int64 size_t;
#FimSe
#Senão
  Tipo SemSinal Longo size_t;
#FimSe
#FimSe

#SenãoDefinido _SSIZE_T_DEFINED
#Defina _SSIZE_T_DEFINED
#SeDefinido _WIN64
#Se Definido(__GNUC__) && Definido(__STRICT_ANSI__)
  Tipo Inteiro ssize_t __attribute__ ((mode (DI)));
#Senão
  Tipo __int64 ssize_t;
#FimSe
#Senão
  Tipo Longo ssize_t;
#FimSe
#FimSe

#SenãoDefinido _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(Constante Estrutura tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(Constante __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t _SizeInWords,Constante wchar_t *_Format,Constante Estrutura tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t _SizeInWords,Constante wchar_t *_Format,Constante Estrutura tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(Constante __time64_t *_Time);
#FimSe

#Se !Definido (RC_INVOKED) && !Definido (_INC_WTIME_INL)
#Defina _INC_WTIME_INL
#SeDefinido _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(Constante time_t *_Time) { Retorno _wctime32(_Time); }
#Senão
__CRT_INLINE wchar_t *__cdecl _wctime(Constante time_t *_Time) { Retorno _wctime64(_Time); }
#FimSe
#FimSe

#Defina _WTIME_DEFINED
#FimSe

#SenãoDefinido RC_INVOKED
Duplo __cdecl difftime(time_t _Time1,time_t _Time2);
Caractere *__cdecl ctime(Constante time_t *_Time);
Estrutura tm *__cdecl gmtime(Constante time_t *_Time);
Estrutura tm *__cdecl localtime(Constante time_t *_Time);
Estrutura tm *__cdecl localtime_r(Constante time_t *_Time,Estrutura tm *);

time_t __cdecl mktime(Estrutura tm *_Tm);
time_t __cdecl _mkgmtime(Estrutura tm *_Tm);
time_t __cdecl time(time_t *_Time);

#SeDefinido _USE_32BIT_TIME_T
#Se 0
__CRT_INLINE Duplo __cdecl difftime(time_t _Time1,time_t _Time2) { Retorno _difftime32(_Time1,_Time2); }
__CRT_INLINE Caractere *__cdecl ctime(Constante time_t *_Time) { Retorno _ctime32(_Time); }
__CRT_INLINE Estrutura tm *__cdecl gmtime(Constante time_t *_Time) { Retorno _gmtime32(_Time); }
__CRT_INLINE Estrutura tm *__cdecl localtime(Constante time_t *_Time) { Retorno _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(Estrutura tm *_Tm) { Retorno _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(Estrutura tm *_Tm) { Retorno _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { Retorno _time32(_Time); }
#FimSe
#Senão
__CRT_INLINE Duplo __cdecl difftime(time_t _Time1,time_t _Time2) { Retorno _difftime64(_Time1,_Time2); }
__CRT_INLINE Caractere *__cdecl ctime(Constante time_t *_Time) { Retorno _ctime64(_Time); }
__CRT_INLINE Estrutura tm *__cdecl gmtime(Constante time_t *_Time) { Retorno _gmtime64(_Time); }
__CRT_INLINE Estrutura tm *__cdecl localtime(Constante time_t *_Time) { Retorno _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(Estrutura tm *_Tm) { Retorno _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(Estrutura tm *_Tm) { Retorno _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { Retorno _time64(_Time); }
#FimSe
#FimSe

#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
#Defina CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT Inteiro daylight;
  __MINGW_IMPORT Longo dstbias;
  __MINGW_IMPORT Longo timezone;
  __MINGW_IMPORT Caractere *tzname[2];
  Vazio __cdecl tzset(Vazio);
#FimSe

#SenãoDefinido _TIMEVAL_DEFINED /* also in winsock[2].h */
#Defina _TIMEVAL_DEFINED
Estrutura timeval {
  Longo tv_sec;
  Longo tv_usec;
};
#Defina timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#Defina timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#Defina timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#FimSe /* _TIMEVAL_DEFINED */

#SenãoDefinido __STRICT_ANSI__
#SenãoDefinido _TIMEZONE_DEFINED /* also in sys/time.h */
#Defina _TIMEZONE_DEFINED
Estrutura timezone {
  Inteiro tz_minuteswest;
  Inteiro tz_dsttime;
};

  Externo Inteiro __cdecl mingw_gettimeofday (Estrutura timeval *p, Estrutura timezone *z);
#FimSe
#FimSe /* __STRICT_ANSI__ */

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)

#Inclua <sec_api/time_s.h>

/* Adding timespec definition.  */
#Inclua <sys/timeb.h>

#FimSe /* End _TIME_H_ */

