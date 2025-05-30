/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_TYPES
#Defina _INC_TYPES

#SenãoDefinido _WIN32
#Erro Only Win32 target is supported!
#FimSe

#Inclua <_mingw.h>

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

#SenãoDefinido _INO_T_DEFINED
#Defina _INO_T_DEFINED
Tipo SemSinal Curto _ino_t;
#SenãoDefinido	NO_OLDNAMES
Tipo SemSinal Curto ino_t;
#FimSe
#FimSe

#SenãoDefinido _DEV_T_DEFINED
#Defina _DEV_T_DEFINED
Tipo SemSinal Inteiro _dev_t;
#SenãoDefinido	NO_OLDNAMES
Tipo SemSinal Inteiro dev_t;
#FimSe
#FimSe

#SenãoDefinido _PID_T_
#Defina	_PID_T_
#SenãoDefinido _WIN64
Tipo Inteiro	_pid_t;
#Senão
Tipo __int64	_pid_t;
#FimSe

#SenãoDefinido	NO_OLDNAMES
Tipo _pid_t	pid_t;
#FimSe
#FimSe	/* Not _PID_T_ */

#SenãoDefinido _MODE_T_
#Defina	_MODE_T_
Tipo SemSinal Curto _mode_t;

#SenãoDefinido	NO_OLDNAMES
Tipo _mode_t	mode_t;
#FimSe
#FimSe	/* Not _MODE_T_ */

#SenãoDefinido _OFF_T_DEFINED
#Defina _OFF_T_DEFINED
#SenãoDefinido _OFF_T_
#Defina _OFF_T_
  Tipo Longo _off_t;
#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
  Tipo Longo off_t;
#FimSe
#FimSe
#FimSe

#SenãoDefinido _OFF64_T_DEFINED
#Defina _OFF64_T_DEFINED
  Tipo Longo Longo _off64_t;
#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
  Tipo Longo Longo off64_t;
#FimSe
#FimSe

#SenãoDefinido _TIMESPEC_DEFINED
#Defina _TIMESPEC_DEFINED
Estrutura timespec {
  time_t  tv_sec;   /* Seconds */
  Longo    tv_nsec;  /* Nanoseconds */
};

Estrutura itimerspec {
  Estrutura timespec  it_interval;  /* Timer period */
  Estrutura timespec  it_value;     /* Timer expiration */
};
#FimSe

#FimSe
