/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_STDLIB
#Defina _INC_STDLIB

#Inclua <_mingw.h>
#Inclua <limits.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#Defina EXIT_SUCCESS 0
#Defina EXIT_FAILURE 1

#SenãoDefinido _ONEXIT_T_DEFINED
#Defina _ONEXIT_T_DEFINED

  Tipo Inteiro (__cdecl *_onexit_t)(Vazio);

#SenãoDefinido NO_OLDNAMES
#Defina onexit_t _onexit_t
#FimSe
#FimSe

#SenãoDefinido _DIV_T_DEFINED
#Defina _DIV_T_DEFINED

  Tipo Estrutura _div_t {
    Inteiro quot;
    Inteiro rem;
  } div_t;

  Tipo Estrutura _ldiv_t {
    Longo quot;
    Longo rem;
  } ldiv_t;
#FimSe

#SenãoDefinido _CRT_DOUBLE_DEC
#Defina _CRT_DOUBLE_DEC

#Diretiva pack(4)
  Tipo Estrutura {
    SemSinal Caractere ld[10];
  } _LDOUBLE;
#Diretiva pack()

#Defina _PTR_LD(x) ((SemSinal Caractere *)(&(x)->ld))

  Tipo Estrutura {
    Duplo x;
  } _CRT_DOUBLE;

  Tipo Estrutura {
    Real f;
  } _CRT_FLOAT;

#Diretiva push_macro("Longo")
#Indefinido Longo

  Tipo Estrutura {
    Longo Duplo x;
  } _LONGDOUBLE;

#Diretiva pop_macro("Longo")

#Diretiva pack(4)
  Tipo Estrutura {
    SemSinal Caractere ld12[12];
  } _LDBL12;
#Diretiva pack()
#FimSe

#Defina RAND_MAX 0x7fff

#SenãoDefinido MB_CUR_MAX
#Defina MB_CUR_MAX ___mb_cur_max_func()
#SenãoDefinido __mb_cur_max
#SeDefinido _MSVCRT_
  Externo Inteiro __mb_cur_max;
#Senão
#Defina __mb_cur_max    (*_imp____mb_cur_max)
  Externo Inteiro *_imp____mb_cur_max;
#FimSe
#FimSe
#SeDefinido _MSVCRT_
  Externo Inteiro __mbcur_max;
#Defina ___mb_cur_max_func() (__mb_cur_max)
#Senão
  Externo Inteiro* _imp____mbcur_max;
#Defina ___mb_cur_max_func() (*_imp____mb_cur_max)
#FimSe
#FimSe

#Defina __max(a,b) (((a) > (b)) ? (a) : (b))
#Defina __min(a,b) (((a) < (b)) ? (a) : (b))

#Defina _MAX_PATH 260
#Defina _MAX_DRIVE 3
#Defina _MAX_DIR 256
#Defina _MAX_FNAME 256
#Defina _MAX_EXT 256

#Defina _OUT_TO_DEFAULT 0
#Defina _OUT_TO_STDERR 1
#Defina _OUT_TO_MSGBOX 2
#Defina _REPORT_ERRMODE 3

#Defina _WRITE_ABORT_MSG 0x1
#Defina _CALL_REPORTFAULT 0x2

#Defina _MAX_ENV 32767

  Tipo Vazio (__cdecl *_purecall_handler)(Vazio);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(Vazio);

  Tipo Vazio (__cdecl *_invalid_parameter_handler)(Constante wchar_t *,Constante wchar_t *,Constante wchar_t *,SemSinal Inteiro,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(Vazio);

#SenãoDefinido _CRT_ERRNO_DEFINED
#Defina _CRT_ERRNO_DEFINED
  _CRTIMP Externo Inteiro *__cdecl _errno(Vazio);
#Defina errno (*_errno())
  errno_t __cdecl _set_errno(Inteiro _Value);
  errno_t __cdecl _get_errno(Inteiro *_Value);
#FimSe
  _CRTIMP SemSinal Longo *__cdecl __doserrno(Vazio);
#Defina _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(SemSinal Longo _Value);
  errno_t __cdecl _get_doserrno(SemSinal Longo *_Value);
#SeDefinido _MSVCRT_
  Externo Caractere *_sys_errlist[];
  Externo Inteiro _sys_nerr;
#Senão
  _CRTIMP Caractere *_sys_errlist[1];
  _CRTIMP Inteiro _sys_nerr;
#FimSe
#Se (Definido(_X86_) && !Definido(__x86_64))
  _CRTIMP Inteiro *__cdecl __p___argc(Vazio);
  _CRTIMP Caractere ***__cdecl __p___argv(Vazio);
  _CRTIMP wchar_t ***__cdecl __p___wargv(Vazio);
  _CRTIMP Caractere ***__cdecl __p__environ(Vazio);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(Vazio);
  _CRTIMP Caractere **__cdecl __p__pgmptr(Vazio);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(Vazio);
#FimSe
#SenãoDefinido __argc
#SeDefinido _MSVCRT_
  Externo Inteiro __argc;
#Senão
#Defina __argc (*_imp____argc)
  Externo Inteiro *_imp____argc;
#FimSe
#FimSe
#SenãoDefinido __argv
#SeDefinido _MSVCRT_
  Externo Caractere **__argv;
#Senão
#Defina __argv  (*_imp____argv)
  Externo Caractere ***_imp____argv;
#FimSe
#FimSe
#SenãoDefinido __wargv
#SeDefinido _MSVCRT_
  Externo wchar_t **__wargv;
#Senão
#Defina __wargv (*_imp____wargv)
  Externo wchar_t ***_imp____wargv;
#FimSe
#FimSe

#SeDefinido _POSIX_
  Externo Caractere **environ;
#Senão
#SenãoDefinido _environ
#SeDefinido _MSVCRT_
  Externo Caractere **_environ;
#Senão
#Defina _environ (*_imp___environ)
  Externo Caractere ***_imp___environ;
#FimSe
#FimSe

#SenãoDefinido _wenviron
#SeDefinido _MSVCRT_
  Externo wchar_t **_wenviron;
#Senão
#Defina _wenviron       (*_imp___wenviron)
  Externo wchar_t ***_imp___wenviron;
#FimSe
#FimSe
#FimSe
#SenãoDefinido _pgmptr
#SeDefinido _MSVCRT_
  Externo Caractere *_pgmptr;
#Senão
#Defina _pgmptr (*_imp___pgmptr)
  Externo Caractere **_imp___pgmptr;
#FimSe
#FimSe

#SenãoDefinido _wpgmptr
#SeDefinido _MSVCRT_
  Externo wchar_t *_wpgmptr;
#Senão
#Defina _wpgmptr        (*_imp___wpgmptr)
  Externo wchar_t **_imp___wpgmptr;
#FimSe
#FimSe
  errno_t __cdecl _get_pgmptr(Caractere **_Value);
  errno_t __cdecl _get_wpgmptr(wchar_t **_Value);
#SenãoDefinido _fmode
#SeDefinido _MSVCRT_
  Externo Inteiro _fmode;
#Senão
#Defina _fmode  (*_imp___fmode)
  Externo Inteiro *_imp___fmode;
#FimSe
#FimSe
  _CRTIMP errno_t __cdecl _set_fmode(Inteiro _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(Inteiro *_PMode);

#SenãoDefinido _osplatform
#SeDefinido _MSVCRT_
  Externo SemSinal Inteiro _osplatform;
#Senão
#Defina _osplatform (*_imp___osplatform)
  Externo SemSinal Inteiro *_imp___osplatform;
#FimSe
#FimSe

#SenãoDefinido _osver
#SeDefinido _MSVCRT_
  Externo SemSinal Inteiro _osver;
#Senão
#Defina _osver  (*_imp___osver)
  Externo SemSinal Inteiro *_imp___osver;
#FimSe
#FimSe

#SenãoDefinido _winver
#SeDefinido _MSVCRT_
  Externo SemSinal Inteiro _winver;
#Senão
#Defina _winver (*_imp___winver)
  Externo SemSinal Inteiro *_imp___winver;
#FimSe
#FimSe

#SenãoDefinido _winmajor
#SeDefinido _MSVCRT_
  Externo SemSinal Inteiro _winmajor;
#Senão
#Defina _winmajor       (*_imp___winmajor)
  Externo SemSinal Inteiro *_imp___winmajor;
#FimSe
#FimSe

#SenãoDefinido _winminor
#SeDefinido _MSVCRT_
  Externo SemSinal Inteiro _winminor;
#Senão
#Defina _winminor       (*_imp___winminor)
  Externo SemSinal Inteiro *_imp___winminor;
#FimSe
#FimSe

  errno_t __cdecl _get_osplatform(SemSinal Inteiro *_Value);
  errno_t __cdecl _get_osver(SemSinal Inteiro *_Value);
  errno_t __cdecl _get_winver(SemSinal Inteiro *_Value);
  errno_t __cdecl _get_winmajor(SemSinal Inteiro *_Value);
  errno_t __cdecl _get_winminor(SemSinal Inteiro *_Value);
#SenãoDefinido _countof
#SenãoDefinido __cplusplus
#Defina _countof(_Array) (TamanhoDe(_Array) / TamanhoDe(_Array[0]))
#Senão
  Externo "C++" {
    template <typename _CountofType,size_t _SizeOfArray> Caractere (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#Defina _countof(_Array) TamanhoDe(*__countof_helper(_Array))
  }
#FimSe
#FimSe

#SenãoDefinido _CRT_TERMINATE_DEFINED
#Defina _CRT_TERMINATE_DEFINED
  Vazio __cdecl __MINGW_NOTHROW exit(Inteiro _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP Vazio __cdecl __MINGW_NOTHROW _exit(Inteiro _Code) __MINGW_ATTRIB_NORETURN;
#Se !Definido __NO_ISOCEXT /* Externo stub in Estático libmingwex.a */
  /* C99 function name */
  Vazio __cdecl _Exit(Inteiro) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN Vazio  __cdecl _Exit(Inteiro status)
  {  _exit(status); }
#FimSe

#Diretiva push_macro("abort")
#Indefinido abort
  Vazio __cdecl __declspec(noreturn) abort(Vazio);
#Diretiva pop_macro("abort")

#FimSe

  _CRTIMP SemSinal Inteiro __cdecl _set_abort_behavior(SemSinal Inteiro _Flags,SemSinal Inteiro _Mask);

#SenãoDefinido _CRT_ABS_DEFINED
#Defina _CRT_ABS_DEFINED
  Inteiro __cdecl abs(Inteiro _X);
  Longo __cdecl labs(Longo _X);
#FimSe

#Se _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#FimSe
  Inteiro __cdecl atexit(Vazio (__cdecl *)(Vazio));
#SenãoDefinido _CRT_ATOF_DEFINED
#Defina _CRT_ATOF_DEFINED
  Duplo __cdecl atof(Constante Caractere *_String);
  Duplo __cdecl _atof_l(Constante Caractere *_String,_locale_t _Locale);
#FimSe
  Inteiro __cdecl atoi(Constante Caractere *_Str);
  _CRTIMP Inteiro __cdecl _atoi_l(Constante Caractere *_Str,_locale_t _Locale);
  Longo __cdecl atol(Constante Caractere *_Str);
  _CRTIMP Longo __cdecl _atol_l(Constante Caractere *_Str,_locale_t _Locale);
#SenãoDefinido _CRT_ALGO_DEFINED
#Defina _CRT_ALGO_DEFINED
  Vazio *__cdecl bsearch(Constante Vazio *_Key,Constante Vazio *_Base,size_t _NumOfElements,size_t _SizeOfElements,Inteiro (__cdecl *_PtFuncCompare)(Constante Vazio *,Constante Vazio *));
  Vazio __cdecl qsort(Vazio *_Base,size_t _NumOfElements,size_t _SizeOfElements,Inteiro (__cdecl *_PtFuncCompare)(Constante Vazio *,Constante Vazio *));
#FimSe
  SemSinal Curto __cdecl _byteswap_ushort(SemSinal Curto _Short);
  /*SemSinal Longo __cdecl _byteswap_ulong (SemSinal Longo _Long); */
#Se _INTEGRAL_MAX_BITS >= 64
  SemSinal __int64 __cdecl _byteswap_uint64(SemSinal __int64 _Int64);
#FimSe
  div_t __cdecl div(Inteiro _Numerator,Inteiro _Denominator);
  Caractere *__cdecl getenv(Constante Caractere *_VarName);
  _CRTIMP Caractere *__cdecl _itoa(Inteiro _Value,Caractere *_Dest,Inteiro _Radix);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP Caractere *__cdecl _i64toa(__int64 _Val,Caractere *_DstBuf,Inteiro _Radix);
  _CRTIMP Caractere *__cdecl _ui64toa(SemSinal __int64 _Val,Caractere *_DstBuf,Inteiro _Radix);
  _CRTIMP __int64 __cdecl _atoi64(Constante Caractere *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(Constante Caractere *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(Constante Caractere *_String,Caractere **_EndPtr,Inteiro _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(Constante Caractere *_String,Caractere **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  _CRTIMP SemSinal __int64 __cdecl _strtoui64(Constante Caractere *_String,Caractere **_EndPtr,Inteiro _Radix);
  _CRTIMP SemSinal __int64 __cdecl _strtoui64_l(Constante Caractere *_String,Caractere **_EndPtr,Inteiro _Radix,_locale_t _Locale);
#FimSe
  ldiv_t __cdecl ldiv(Longo _Numerator,Longo _Denominator);
  _CRTIMP Caractere *__cdecl _ltoa(Longo _Value,Caractere *_Dest,Inteiro _Radix);
  Inteiro __cdecl mblen(Constante Caractere *_Ch,size_t _MaxCount);
  _CRTIMP Inteiro __cdecl _mblen_l(Constante Caractere *_Ch,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(Constante Caractere *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(Constante Caractere *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(Constante Caractere *_Str,size_t _MaxCount);
  _CRTIMP size_t __cdecl _mbstrnlen_l(Constante Caractere *_Str,size_t _MaxCount,_locale_t _Locale);
  Inteiro __cdecl mbtowc(wchar_t *_DstCh,Constante Caractere *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP Inteiro __cdecl _mbtowc_l(wchar_t *_DstCh,Constante Caractere *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,Constante Caractere *_Source,size_t _MaxCount);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,Constante Caractere *_Source,size_t _MaxCount,_locale_t _Locale);
  Inteiro __cdecl rand(Vazio);
  _CRTIMP Inteiro __cdecl _set_error_mode(Inteiro _Mode);
  Vazio __cdecl srand(SemSinal Inteiro _Seed);
  Duplo __cdecl strtod(Constante Caractere *_Str,Caractere **_EndPtr);
  Real __cdecl strtof(Constante Caractere *nptr, Caractere **endptr);
#Se !Definido __NO_ISOCEXT  /* in libmingwex.a */
  Real __cdecl strtof (Constante Caractere * Restrito, Caractere ** Restrito);
  Longo Duplo __cdecl strtold(Constante Caractere * Restrito, Caractere ** Restrito);
#FimSe /* __NO_ISOCEXT */
  _CRTIMP Duplo __cdecl _strtod_l(Constante Caractere *_Str,Caractere **_EndPtr,_locale_t _Locale);
  Longo __cdecl strtol(Constante Caractere *_Str,Caractere **_EndPtr,Inteiro _Radix);
  _CRTIMP Longo __cdecl _strtol_l(Constante Caractere *_Str,Caractere **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  SemSinal Longo __cdecl strtoul(Constante Caractere *_Str,Caractere **_EndPtr,Inteiro _Radix);
  _CRTIMP SemSinal Longo __cdecl _strtoul_l(Constante Caractere *_Str,Caractere **_EndPtr,Inteiro _Radix,_locale_t _Locale);
#SenãoDefinido _CRT_SYSTEM_DEFINED
#Defina _CRT_SYSTEM_DEFINED
  Inteiro __cdecl system(Constante Caractere *_Command);
#FimSe
  _CRTIMP Caractere *__cdecl _ultoa(SemSinal Longo _Value,Caractere *_Dest,Inteiro _Radix);
  Inteiro __cdecl wctomb(Caractere *_MbCh,wchar_t _WCh);
  _CRTIMP Inteiro __cdecl _wctomb_l(Caractere *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(Caractere *_Dest,Constante wchar_t *_Source,size_t _MaxCount);
  _CRTIMP size_t __cdecl _wcstombs_l(Caractere *_Dest,Constante wchar_t *_Source,size_t _MaxCount,_locale_t _Locale);

#SenãoDefinido _CRT_ALLOCATION_DEFINED
#Defina _CRT_ALLOCATION_DEFINED
  Vazio *__cdecl calloc(size_t _NumOfElements,size_t _SizeOfElements);
  Vazio __cdecl free(Vazio *_Memory);
  Vazio *__cdecl malloc(size_t _Size);
  Vazio *__cdecl realloc(Vazio *_Memory,size_t _NewSize);
  _CRTIMP Vazio *__cdecl _recalloc(Vazio *_Memory,size_t _Count,size_t _Size);
  //_CRTIMP Vazio __cdecl _aligned_free(Vazio *_Memory);
  //_CRTIMP Vazio *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP Vazio *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP Vazio *__cdecl _aligned_realloc(Vazio *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP Vazio *__cdecl _aligned_recalloc(Vazio *_Memory,size_t _Count,size_t _Size,size_t _Alignment);
  _CRTIMP Vazio *__cdecl _aligned_offset_realloc(Vazio *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP Vazio *__cdecl _aligned_offset_recalloc(Vazio *_Memory,size_t _Count,size_t _Size,size_t _Alignment,size_t _Offset);
#FimSe

#SenãoDefinido _WSTDLIB_DEFINED
#Defina _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(Inteiro _Value,wchar_t *_Dest,Inteiro _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(Longo _Value,wchar_t *_Dest,Inteiro _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(SemSinal Longo _Value,wchar_t *_Dest,Inteiro _Radix);
  Duplo __cdecl wcstod(Constante wchar_t *_Str,wchar_t **_EndPtr);
  Real __cdecl wcstof(Constante wchar_t *nptr, wchar_t **endptr);
#Se !Definido __NO_ISOCEXT /* in libmingwex.a */
  Real __cdecl wcstof( Constante wchar_t * Restrito, wchar_t ** Restrito);
  Longo Duplo __cdecl wcstold(Constante wchar_t * Restrito, wchar_t ** Restrito);
#FimSe /* __NO_ISOCEXT */
  _CRTIMP Duplo __cdecl _wcstod_l(Constante wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  Longo __cdecl wcstol(Constante wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix);
  _CRTIMP Longo __cdecl _wcstol_l(Constante wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  SemSinal Longo __cdecl wcstoul(Constante wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix);
  _CRTIMP SemSinal Longo __cdecl _wcstoul_l(Constante wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(Constante wchar_t *_VarName);
#SenãoDefinido _CRT_WSYSTEM_DEFINED
#Defina _CRT_WSYSTEM_DEFINED
  _CRTIMP Inteiro __cdecl _wsystem(Constante wchar_t *_Command);
#FimSe
  _CRTIMP Duplo __cdecl _wtof(Constante wchar_t *_Str);
  _CRTIMP Duplo __cdecl _wtof_l(Constante wchar_t *_Str,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _wtoi(Constante wchar_t *_Str);
  _CRTIMP Inteiro __cdecl _wtoi_l(Constante wchar_t *_Str,_locale_t _Locale);
  _CRTIMP Longo __cdecl _wtol(Constante wchar_t *_Str);
  _CRTIMP Longo __cdecl _wtol_l(Constante wchar_t *_Str,_locale_t _Locale);

#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,Inteiro _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(SemSinal __int64 _Val,wchar_t *_DstBuf,Inteiro _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(Constante wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(Constante wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(Constante wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(Constante wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  _CRTIMP SemSinal __int64 __cdecl _wcstoui64(Constante wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix);
  _CRTIMP SemSinal __int64 __cdecl _wcstoui64_l(Constante wchar_t *_Str ,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
#FimSe
#FimSe

#SenãoDefinido _POSIX_
#Defina _CVTBUFSIZE (309+40)
  _CRTIMP Caractere *__cdecl _fullpath(Caractere *_FullPath,Constante Caractere *_Path,size_t _SizeInBytes);
  _CRTIMP Caractere *__cdecl _ecvt(Duplo _Val,Inteiro _NumOfDigits,Inteiro *_PtDec,Inteiro *_PtSign);
  _CRTIMP Caractere *__cdecl _fcvt(Duplo _Val,Inteiro _NumOfDec,Inteiro *_PtDec,Inteiro *_PtSign);
  _CRTIMP Caractere *__cdecl _gcvt(Duplo _Val,Inteiro _NumOfDigits,Caractere *_DstBuf);
  _CRTIMP Inteiro __cdecl _atodbl(_CRT_DOUBLE *_Result,Caractere *_Str);
  _CRTIMP Inteiro __cdecl _atoldbl(_LDOUBLE *_Result,Caractere *_Str);
  _CRTIMP Inteiro __cdecl _atoflt(_CRT_FLOAT *_Result,Caractere *_Str);
  _CRTIMP Inteiro __cdecl _atodbl_l(_CRT_DOUBLE *_Result,Caractere *_Str,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _atoldbl_l(_LDOUBLE *_Result,Caractere *_Str,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _atoflt_l(_CRT_FLOAT *_Result,Caractere *_Str,_locale_t _Locale);
  SemSinal Longo __cdecl _lrotl(SemSinal Longo _Val,Inteiro _Shift);
  SemSinal Longo __cdecl _lrotr(SemSinal Longo _Val,Inteiro _Shift);
  _CRTIMP Vazio __cdecl _makepath(Caractere *_Path,Constante Caractere *_Drive,Constante Caractere *_Dir,Constante Caractere *_Filename,Constante Caractere *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#SenãoDefinido _CRT_PERROR_DEFINED
#Defina _CRT_PERROR_DEFINED
  Vazio __cdecl perror(Constante Caractere *_ErrMsg);
#FimSe
  _CRTIMP Inteiro __cdecl _putenv(Constante Caractere *_EnvString);
  SemSinal Inteiro __cdecl _rotl(SemSinal Inteiro _Val,Inteiro _Shift);
#Se _INTEGRAL_MAX_BITS >= 64
  SemSinal __int64 __cdecl _rotl64(SemSinal __int64 _Val,Inteiro _Shift);
#FimSe
  SemSinal Inteiro __cdecl _rotr(SemSinal Inteiro _Val,Inteiro _Shift);
#Se _INTEGRAL_MAX_BITS >= 64
  SemSinal __int64 __cdecl _rotr64(SemSinal __int64 _Val,Inteiro _Shift);
#FimSe
  _CRTIMP Vazio __cdecl _searchenv(Constante Caractere *_Filename,Constante Caractere *_EnvVar,Caractere *_ResultPath);
  _CRTIMP Vazio __cdecl _splitpath(Constante Caractere *_FullPath,Caractere *_Drive,Caractere *_Dir,Caractere *_Filename,Caractere *_Ext);
  _CRTIMP Vazio __cdecl _swab(Caractere *_Buf1,Caractere *_Buf2,Inteiro _SizeInBytes);

#SenãoDefinido _WSTDLIBP_DEFINED
#Defina _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,Constante wchar_t *_Path,size_t _SizeInWords);
  _CRTIMP Vazio __cdecl _wmakepath(wchar_t *_ResultPath,Constante wchar_t *_Drive,Constante wchar_t *_Dir,Constante wchar_t *_Filename,Constante wchar_t *_Ext);
#SenãoDefinido _CRT_WPERROR_DEFINED
#Defina _CRT_WPERROR_DEFINED
  _CRTIMP Vazio __cdecl _wperror(Constante wchar_t *_ErrMsg);
#FimSe
  _CRTIMP Inteiro __cdecl _wputenv(Constante wchar_t *_EnvString);
  _CRTIMP Vazio __cdecl _wsearchenv(Constante wchar_t *_Filename,Constante wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP Vazio __cdecl _wsplitpath(Constante wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#FimSe

  _CRTIMP Vazio __cdecl _beep(SemSinal _Frequency,SemSinal _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (Inteiro).  */
  _CRTIMP Vazio __cdecl _seterrormode(Inteiro _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP Vazio __cdecl _sleep(SemSinal Longo _Duration) __MINGW_ATTRIB_DEPRECATED;
#FimSe

#SenãoDefinido NO_OLDNAMES
#SenãoDefinido _POSIX_
#Se 0
#SenãoDefinido __cplusplus
#SenãoDefinido NOMINMAX
#SenãoDefinido max
#Defina max(a,b) (((a) > (b)) ? (a) : (b))
#FimSe
#SenãoDefinido min
#Defina min(a,b) (((a) < (b)) ? (a) : (b))
#FimSe
#FimSe
#FimSe
#FimSe

#Defina sys_errlist _sys_errlist
#Defina sys_nerr _sys_nerr
#Defina environ _environ
  Caractere *__cdecl ecvt(Duplo _Val,Inteiro _NumOfDigits,Inteiro *_PtDec,Inteiro *_PtSign);
  Caractere *__cdecl fcvt(Duplo _Val,Inteiro _NumOfDec,Inteiro *_PtDec,Inteiro *_PtSign);
  Caractere *__cdecl gcvt(Duplo _Val,Inteiro _NumOfDigits,Caractere *_DstBuf);
  Caractere *__cdecl itoa(Inteiro _Val,Caractere *_DstBuf,Inteiro _Radix);
  Caractere *__cdecl ltoa(Longo _Val,Caractere *_DstBuf,Inteiro _Radix);
  Inteiro __cdecl putenv(Constante Caractere *_EnvString);
  Vazio __cdecl swab(Caractere *_Buf1,Caractere *_Buf2,Inteiro _SizeInBytes);
  Caractere *__cdecl ultoa(SemSinal Longo _Val,Caractere *_Dstbuf,Inteiro _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#FimSe
#FimSe

#Se !Definido __NO_ISOCEXT /* externs in Estático libmingwex.a */

  Tipo Estrutura { Longo Longo quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(Longo Longo, Longo Longo);

  __CRT_INLINE Longo Longo __cdecl llabs(Longo Longo _j) { Retorno (_j >= 0 ? _j : -_j); }

  Longo Longo  __cdecl strtoll(Constante Caractere* Restrito, Caractere** Restrito, Inteiro);
  SemSinal Longo Longo  __cdecl strtoull(Constante Caractere* Restrito, Caractere** Restrito, Inteiro);

  /* these are stubs Para MS _i64 versions */
  Longo Longo  __cdecl atoll (Constante Caractere *);

#SenãoDefinido __STRICT_ANSI__
  Longo Longo  __cdecl wtoll (Constante wchar_t *);
  Caractere *__cdecl lltoa (Longo Longo, Caractere *, Inteiro);
  Caractere *__cdecl ulltoa (SemSinal Longo Longo , Caractere *, Inteiro);
  wchar_t *__cdecl lltow (Longo Longo, wchar_t *, Inteiro);
  wchar_t *__cdecl ulltow (SemSinal Longo Longo, wchar_t *, Inteiro);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE Longo Longo  __cdecl atoll (Constante Caractere * _c) { Retorno _atoi64 (_c); }
  __CRT_INLINE Caractere *__cdecl lltoa (Longo Longo _n, Caractere * _c, Inteiro _i) { Retorno _i64toa (_n, _c, _i); }
  __CRT_INLINE Caractere *__cdecl ulltoa (SemSinal Longo Longo _n, Caractere * _c, Inteiro _i) { Retorno _ui64toa (_n, _c, _i); }
  __CRT_INLINE Longo Longo  __cdecl wtoll (Constante wchar_t * _w) { Retorno _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (Longo Longo _n, wchar_t * _w, Inteiro _i) { Retorno _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (SemSinal Longo Longo _n, wchar_t * _w, Inteiro _i) { Retorno _ui64tow (_n, _w, _i); }
#FimSe /* (__STRICT_ANSI__)  */

#FimSe /* !__NO_ISOCEXT */

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)

#Inclua <sec_api/stdlib_s.h>
#Inclua <malloc.h>

#FimSe
