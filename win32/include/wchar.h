/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_WCHAR
#Defina _INC_WCHAR

#Inclua <_mingw.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido WCHAR_MIN  /* also at stdint.h */
#Defina WCHAR_MIN 0
#Defina WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#FimSe

#SenãoDefinido __GNUC_VA_LIST
#Defina __GNUC_VA_LIST
  Tipo __builtin_va_list __gnuc_va_list;
#FimSe

#SenãoDefinido _VA_LIST_DEFINED
#Defina _VA_LIST_DEFINED
  Tipo __gnuc_va_list va_list;
#FimSe

#SenãoDefinido WEOF
#Defina WEOF (wint_t)(0xFFFF)
#FimSe

#SenãoDefinido _FILE_DEFINED
  Estrutura _iobuf {
    Caractere *_ptr;
    Inteiro _cnt;
    Caractere *_base;
    Inteiro _flag;
    Inteiro _file;
    Inteiro _charbuf;
    Inteiro _bufsiz;
    Caractere *_tmpfname;
  };
  Tipo Estrutura _iobuf FILE;
#Defina _FILE_DEFINED
#FimSe

#SenãoDefinido _STDIO_DEFINED
#SeDefinido _WIN64
  _CRTIMP FILE *__cdecl __iob_func(Vazio);
#Senão
#SeDefinido _MSVCRT_
Externo FILE _iob[];	/* A pointer to an array of FILE */
#Defina __iob_func()	(_iob)
#Senão
Externo FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
#Defina __iob_func()	(*_imp___iob)
#Defina _iob __iob_func()
#FimSe
#FimSe

#Defina _iob __iob_func()
#FimSe

#SenãoDefinido _STDSTREAM_DEFINED
#Defina stdin (&__iob_func()[0])
#Defina stdout (&__iob_func()[1])
#Defina stderr (&__iob_func()[2])
#Defina _STDSTREAM_DEFINED
#FimSe

#SenãoDefinido _FSIZE_T_DEFINED
  Tipo SemSinal Longo _fsize_t;
#Defina _FSIZE_T_DEFINED
#FimSe

#SenãoDefinido _WFINDDATA_T_DEFINED
  Estrutura _wfinddata32_t {
    SemSinal attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #Se _INTEGRAL_MAX_BITS >= 64 */

  Estrutura _wfinddata32i64_t {
    SemSinal attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  Estrutura _wfinddata64i32_t {
    SemSinal attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  Estrutura _wfinddata64_t {
    SemSinal attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    wchar_t name[260];
  };
/* #FimSe */

#SeDefinido _USE_32BIT_TIME_T
#Defina _wfinddata_t _wfinddata32_t
#Defina _wfinddatai64_t _wfinddata32i64_t

#Defina _wfindfirst _wfindfirst32
#Defina _wfindnext _wfindnext32
#Defina _wfindfirsti64 _wfindfirst32i64
#Defina _wfindnexti64 _wfindnext32i64
#Senão
#Defina _wfinddata_t _wfinddata64i32_t
#Defina _wfinddatai64_t _wfinddata64_t

#Defina _wfindfirst _wfindfirst64i32
#Defina _wfindnext _wfindnext64i32
#Defina _wfindfirsti64 _wfindfirst64
#Defina _wfindnexti64 _wfindnext64
#FimSe

#Defina _WFINDDATA_T_DEFINED
#FimSe

#SenãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#SenãoDefinido _CONST_RETURN
#Defina _CONST_RETURN
#FimSe

#Defina _WConst_return _CONST_RETURN

#SenãoDefinido _CRT_CTYPEDATA_DEFINED
#Defina _CRT_CTYPEDATA_DEFINED
#SenãoDefinido _CTYPE_DISABLE_MACROS

#SenãoDefinido __PCTYPE_FUNC
#Defina __PCTYPE_FUNC __pctype_func()
#SeDefinido _MSVCRT_
#Defina __pctype_func() (_pctype)
#Senão
#Defina __pctype_func() (*_imp___pctype)
#FimSe
#FimSe

#SenãoDefinido _pctype
#SeDefinido _MSVCRT_
  Externo SemSinal Curto *_pctype;
#Senão
  Externo SemSinal Curto **_imp___pctype;
#Defina _pctype (*_imp___pctype)
#FimSe
#FimSe
#FimSe
#FimSe

#SenãoDefinido _CRT_WCTYPEDATA_DEFINED
#Defina _CRT_WCTYPEDATA_DEFINED
#SenãoDefinido _CTYPE_DISABLE_MACROS
#SenãoDefinido _wctype
#SeDefinido _MSVCRT_
  Externo SemSinal Curto *_wctype;
#Senão
  Externo SemSinal Curto **_imp___wctype;
#Defina _wctype (*_imp___wctype)
#FimSe
#FimSe

#SeDefinido _MSVCRT_
#Defina __pwctype_func() (_pwctype)
#Senão
#Defina __pwctype_func() (*_imp___pwctype)
#FimSe

#SenãoDefinido _pwctype
#SeDefinido _MSVCRT_
  Externo SemSinal Curto *_pwctype;
#Senão
  Externo SemSinal Curto **_imp___pwctype;
#Defina _pwctype (*_imp___pwctype)
#FimSe
#FimSe

#FimSe
#FimSe

#Defina _UPPER 0x1
#Defina _LOWER 0x2
#Defina _DIGIT 0x4
#Defina _SPACE 0x8

#Defina _PUNCT 0x10
#Defina _CONTROL 0x20
#Defina _BLANK 0x40
#Defina _HEX 0x80

#Defina _LEADBYTE 0x8000
#Defina _ALPHA (0x0100|_UPPER|_LOWER)

#SenãoDefinido _WCTYPE_DEFINED
#Defina _WCTYPE_DEFINED

  Inteiro __cdecl iswalpha(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswupper(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswlower(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswdigit(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswxdigit(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswspace(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswpunct(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswalnum(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswprint(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswgraph(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswcntrl(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswascii(wint_t _C);
  Inteiro __cdecl isleadbyte(Inteiro _C);
  _CRTIMP Inteiro __cdecl _isleadbyte_l(Inteiro _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP Inteiro __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl __iswcsymf(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl __iswcsym(wint_t _C);
  _CRTIMP Inteiro __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  Inteiro __cdecl is_wctype(wint_t _C,wctype_t _Type);
#FimSe

#SenãoDefinido _WDIRECT_DEFINED
#Defina _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,Inteiro _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(Inteiro _Drive,wchar_t *_DstBuf,Inteiro _SizeInWords);
  wchar_t *__cdecl _wgetdcwd_nolock(Inteiro _Drive,wchar_t *_DstBuf,Inteiro _SizeInWords);
  _CRTIMP Inteiro __cdecl _wchdir(Constante wchar_t *_Path);
  _CRTIMP Inteiro __cdecl _wmkdir(Constante wchar_t *_Path);
  _CRTIMP Inteiro __cdecl _wrmdir(Constante wchar_t *_Path);
#FimSe

#SenãoDefinido _WIO_DEFINED
#Defina _WIO_DEFINED

  _CRTIMP Inteiro __cdecl _waccess(Constante wchar_t *_Filename,Inteiro _AccessMode);
  _CRTIMP Inteiro __cdecl _wchmod(Constante wchar_t *_Filename,Inteiro _Mode);
  _CRTIMP Inteiro __cdecl _wcreat(Constante wchar_t *_Filename,Inteiro _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(Constante wchar_t *_Filename,Estrutura _wfinddata32_t *_FindData);
  _CRTIMP Inteiro __cdecl _wfindnext32(intptr_t _FindHandle,Estrutura _wfinddata32_t *_FindData);
  _CRTIMP Inteiro __cdecl _wunlink(Constante wchar_t *_Filename);
  _CRTIMP Inteiro __cdecl _wrename(Constante wchar_t *_NewFilename,Constante wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(Constante wchar_t *_Filename,Estrutura _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(Constante wchar_t *_Filename,Estrutura _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(Constante wchar_t *_Filename,Estrutura _wfinddata64_t *_FindData);
  _CRTIMP Inteiro __cdecl _wfindnext32i64(intptr_t _FindHandle,Estrutura _wfinddata32i64_t *_FindData);
  Inteiro __cdecl _wfindnext64i32(intptr_t _FindHandle,Estrutura _wfinddata64i32_t *_FindData);
  _CRTIMP Inteiro __cdecl _wfindnext64(intptr_t _FindHandle,Estrutura _wfinddata64_t *_FindData);
#FimSe
  _CRTIMP errno_t __cdecl _wsopen_s(Inteiro *_FileHandle,Constante wchar_t *_Filename,Inteiro _OpenFlag,Inteiro _ShareFlag,Inteiro _PermissionFlag);
#Se !Definido(__cplusplus) || !(Definido(_X86_) && !Definido(__x86_64))
  _CRTIMP Inteiro __cdecl _wopen(Constante wchar_t *_Filename,Inteiro _OpenFlag,...);
  _CRTIMP Inteiro __cdecl _wsopen(Constante wchar_t *_Filename,Inteiro _OpenFlag,Inteiro _ShareFlag,...);
#Senão
  Externo "C++" _CRTIMP Inteiro __cdecl _wopen(Constante wchar_t *_Filename,Inteiro _OpenFlag,Inteiro _PermissionMode = 0);
  Externo "C++" _CRTIMP Inteiro __cdecl _wsopen(Constante wchar_t *_Filename,Inteiro _OpenFlag,Inteiro _ShareFlag,Inteiro _PermissionMode = 0);
#FimSe
#FimSe

#SenãoDefinido _WLOCALE_DEFINED
#Defina _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(Inteiro _Category,Constante wchar_t *_Locale);
#FimSe

#SenãoDefinido _WPROCESS_DEFINED
#Defina _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList,Constante wchar_t *Constante *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList,Constante wchar_t *Constante *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList,Constante wchar_t *Constante *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList,Constante wchar_t *Constante *_Env);
#SenãoDefinido _CRT_WSYSTEM_DEFINED
#Defina _CRT_WSYSTEM_DEFINED
  _CRTIMP Inteiro __cdecl _wsystem(Constante wchar_t *_Command);
#FimSe
#FimSe

#SenãoDefinido _WCTYPE_INLINE_DEFINED
#Indefinido _CRT_WCTYPE_NOINLINE
#Se !Definido(__cplusplus) || Definido(_CRT_WCTYPE_NOINLINE)
#Defina iswalpha(_c) (iswctype(_c,_ALPHA))
#Defina iswupper(_c) (iswctype(_c,_UPPER))
#Defina iswlower(_c) (iswctype(_c,_LOWER))
#Defina iswdigit(_c) (iswctype(_c,_DIGIT))
#Defina iswxdigit(_c) (iswctype(_c,_HEX))
#Defina iswspace(_c) (iswctype(_c,_SPACE))
#Defina iswpunct(_c) (iswctype(_c,_PUNCT))
#Defina iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#Defina iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#Defina iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#Defina iswcntrl(_c) (iswctype(_c,_CONTROL))
#Defina iswascii(_c) ((SemSinal)(_c) < 0x80)

#Defina _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#Defina _iswupper_l(_c,_p) (_iswctype_l(_c,_UPPER,_p))
#Defina _iswlower_l(_c,_p) (_iswctype_l(_c,_LOWER,_p))
#Defina _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#Defina _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#Defina _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#Defina _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#Defina _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#Defina _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#Defina _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#Defina _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#SenãoDefinido _CTYPE_DISABLE_MACROS
#Defina isleadbyte(_c) (__PCTYPE_FUNC[(SemSinal Caractere)(_c)] & _LEADBYTE)
#FimSe
#FimSe
#Defina _WCTYPE_INLINE_DEFINED
#FimSe

#Se !Definido(_POSIX_) || Definido(__GNUC__)
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

#SenãoDefinido _STAT_DEFINED
#Defina _STAT_DEFINED

#SeDefinido _USE_32BIT_TIME_T
#SeDefinido WIN64
#Defina _fstat _fstat32
#Defina _stat _stat32
#Defina _wstat _wstat32
#Senão
#Defina _fstat32 _fstat
#Defina _stat32 _stat
#Defina _wstat32 _wstat
#FimSe
#Defina _fstati64 _fstat32i64
#Defina _stati64 _stat32i64
#Defina _wstati64 _wstat32i64
#Senão
#Defina _fstat _fstat64i32
#Defina _fstati64 _fstat64
#Defina _stat _stat64i32
#Defina _stati64 _stat64
#Defina _wstat _wstat64i32
#Defina _wstati64 _wstat64
#FimSe

  Estrutura _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    SemSinal Curto st_mode;
    Curto st_nlink;
    Curto st_uid;
    Curto st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#SenãoDefinido	NO_OLDNAMES
  Estrutura stat {
    _dev_t st_dev;
    _ino_t st_ino;
    SemSinal Curto st_mode;
    Curto st_nlink;
    Curto st_uid;
    Curto st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#FimSe

#Se _INTEGRAL_MAX_BITS >= 64

  Estrutura _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    SemSinal Curto st_mode;
    Curto st_nlink;
    Curto st_uid;
    Curto st_gid;
    _dev_t st_rdev;
    __int64 st_size;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  Estrutura _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    SemSinal Curto st_mode;
    Curto st_nlink;
    Curto st_uid;
    Curto st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  Estrutura _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    SemSinal Curto st_mode;
    Curto st_nlink;
    Curto st_uid;
    Curto st_gid;
    _dev_t st_rdev;
    __int64 st_size;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#FimSe

#Defina __stat64 _stat64

#FimSe

#SenãoDefinido _WSTAT_DEFINED
#Defina _WSTAT_DEFINED

  _CRTIMP Inteiro __cdecl _wstat32(Constante wchar_t *_Name,Estrutura _stat32 *_Stat);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP Inteiro __cdecl _wstat32i64(Constante wchar_t *_Name,Estrutura _stat32i64 *_Stat);
  Inteiro __cdecl _wstat64i32(Constante wchar_t *_Name,Estrutura _stat64i32 *_Stat);
  _CRTIMP Inteiro __cdecl _wstat64(Constante wchar_t *_Name,Estrutura _stat64 *_Stat);
#FimSe
#FimSe
#FimSe

#SenãoDefinido _WCONIO_DEFINED
#Defina _WCONIO_DEFINED

#SenãoDefinido WEOF
#Defina WEOF (wint_t)(0xFFFF)
#FimSe

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(Vazio);
  _CRTIMP wint_t __cdecl _getwche(Vazio);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP Inteiro __cdecl _cputws(Constante wchar_t *_String);
  _CRTIMP Inteiro __cdecl _cwprintf(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _cwscanf(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _cwscanf_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcwprintf(Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _cwprintf_p(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vcwprintf_p(Constante wchar_t *_Format,va_list _ArgList);

  _CRTIMP Inteiro __cdecl _cwprintf_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcwprintf_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _cwprintf_p_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcwprintf_p_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(Vazio);
  wint_t __cdecl _getwche_nolock(Vazio);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#FimSe

#SenãoDefinido _WSTDIO_DEFINED
#Defina _WSTDIO_DEFINED

#SenãoDefinido WEOF
#Defina WEOF (wint_t)(0xFFFF)
#FimSe

#SeDefinido _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(Constante wchar_t *_Filename,Constante wchar_t *_Mode);
#Senão
  _CRTIMP FILE *__cdecl _wfsopen(Constante wchar_t *_Filename,Constante wchar_t *_Mode,Inteiro _ShFlag);
#FimSe

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(Vazio);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(Vazio);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,Inteiro _SizeInWords,FILE *_File);
  Inteiro __cdecl fputws(Constante wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP Inteiro __cdecl _putws(Constante wchar_t *_Str);
  Inteiro __cdecl fwprintf(FILE *_File,Constante wchar_t *_Format,...);
  Inteiro __cdecl wprintf(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _scwprintf(Constante wchar_t *_Format,...);
  Inteiro __cdecl vfwprintf(FILE *_File,Constante wchar_t *_Format,va_list _ArgList);
  Inteiro __cdecl vwprintf(Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl swprintf(wchar_t*, Constante wchar_t*, ...);
  _CRTIMP Inteiro __cdecl vswprintf(wchar_t*, Constante wchar_t*,va_list);
  _CRTIMP Inteiro __cdecl _swprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _snwprintf(wchar_t *_Dest,size_t _Count,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,Constante wchar_t *_Format,va_list _Args);
#SenãoDefinido __NO_ISOCEXT  /* externs in libmingwex.a */
  Inteiro __cdecl snwprintf (wchar_t *s, size_t n, Constante wchar_t * format, ...);
  __CRT_INLINE Inteiro __cdecl vsnwprintf (wchar_t *s, size_t n, Constante wchar_t *format, va_list arg) { Retorno _vsnwprintf(s,n,format,arg); }
  Inteiro __cdecl vwscanf (Constante wchar_t *, va_list);
  Inteiro __cdecl vfwscanf (FILE *,Constante wchar_t *,va_list);
  Inteiro __cdecl vswscanf (Constante wchar_t *,Constante wchar_t *,va_list);
#FimSe
  _CRTIMP Inteiro __cdecl _fwprintf_p(FILE *_File,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _wprintf_p(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vfwprintf_p(FILE *_File,Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vwprintf_p(Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _swprintf_p(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _scwprintf_p(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vscwprintf_p(Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _wprintf_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _wprintf_p_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vwprintf_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vwprintf_p_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _fwprintf_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _fwprintf_p_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vfwprintf_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vfwprintf_p_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _scwprintf_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _scwprintf_p_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vscwprintf_p_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _swprintf(wchar_t *_Dest,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vswprintf(wchar_t *_Dest,Constante wchar_t *_Format,va_list _Args);
  _CRTIMP Inteiro __cdecl __swprintf_l(wchar_t *_Dest,Constante wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP Inteiro __cdecl __vswprintf_l(wchar_t *_Dest,Constante wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
#SenãoDefinido RC_INVOKED
#Inclua <vadefs.h>
#FimSe

#SeDefinido _CRT_NON_CONFORMING_SWPRINTFS
#SenãoDefinido __cplusplus
#Defina swprintf _swprintf
#Defina vswprintf _vswprintf
#Defina _swprintf_l __swprintf_l
#Defina _vswprintf_l __vswprintf_l
#FimSe
#FimSe

  _CRTIMP wchar_t *__cdecl _wtempnam(Constante wchar_t *_Directory,Constante wchar_t *_FilePrefix);
  _CRTIMP Inteiro __cdecl _vscwprintf(Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _vscwprintf_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  Inteiro __cdecl fwscanf(FILE *_File,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _fwscanf_l(FILE *_File,Constante wchar_t *_Format,_locale_t _Locale,...);
  Inteiro __cdecl swscanf(Constante wchar_t *_Src,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _swscanf_l(Constante wchar_t *_Src,Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _snwscanf(Constante wchar_t *_Src,size_t _MaxCount,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _snwscanf_l(Constante wchar_t *_Src,size_t _MaxCount,Constante wchar_t *_Format,_locale_t _Locale,...);
  Inteiro __cdecl wscanf(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _wscanf_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(Inteiro _FileHandle ,Constante wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(Constante wchar_t *_Filename,Constante wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(Constante wchar_t *_Filename,Constante wchar_t *_Mode,FILE *_OldFile);

#SenãoDefinido _CRT_WPERROR_DEFINED
#Defina _CRT_WPERROR_DEFINED
  _CRTIMP Vazio __cdecl _wperror(Constante wchar_t *_ErrMsg);
#FimSe
  _CRTIMP FILE *__cdecl _wpopen(Constante wchar_t *_Command,Constante wchar_t *_Mode);
#Se !Definido(NO_OLDNAMES) && !Definido(wpopen)
#Defina wpopen	_wpopen
#FimSe
  _CRTIMP Inteiro __cdecl _wremove(Constante wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#Indefinido _CRT_GETPUTWCHAR_NOINLINE

#Se !Definido(__cplusplus) || Definido(_CRT_GETPUTWCHAR_NOINLINE)
#Defina getwchar() fgetwc(stdin)
#Defina putwchar(_c) fputwc((_c),stdout)
#Senão
  __CRT_INLINE wint_t __cdecl getwchar() {Retorno (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {Retorno (fputwc(_C,stdout)); }
#FimSe

#Defina getwc(_stm) fgetwc(_stm)
#Defina putwc(_c,_stm) fputwc(_c,_stm)
#Defina _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#Defina _getwc_nolock(_c) _fgetwc_nolock(_c)
#FimSe

#SenãoDefinido _WSTDLIB_DEFINED
#Defina _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(Inteiro _Value,wchar_t *_Dest,Inteiro _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(Longo _Value,wchar_t *_Dest,Inteiro _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(SemSinal Longo _Value,wchar_t *_Dest,Inteiro _Radix);
  Duplo __cdecl wcstod(Constante wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP Duplo __cdecl _wcstod_l(Constante wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  Real __cdecl wcstof( Constante wchar_t *nptr, wchar_t **endptr);
#Se !Definido __NO_ISOCEXT /* in libmingwex.a */
  Real __cdecl wcstof (Constante wchar_t * Restrito, wchar_t ** Restrito);
  Longo Duplo __cdecl wcstold (Constante wchar_t * Restrito, wchar_t ** Restrito);
#FimSe /* __NO_ISOCEXT */
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
  _CRTIMP SemSinal __int64 __cdecl _wcstoui64_l(Constante wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
#FimSe
#FimSe

#SenãoDefinido _POSIX_
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
#FimSe

#SenãoDefinido _WSTRING_DEFINED
#Defina _WSTRING_DEFINED
  _CRTIMP wchar_t *__cdecl _wcsdup(Constante wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,Constante wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(Constante wchar_t *_Str,wchar_t _Ch);
  Inteiro __cdecl wcscmp(Constante wchar_t *_Str1,Constante wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,Constante wchar_t *_Source);
  size_t __cdecl wcscspn(Constante wchar_t *_Str,Constante wchar_t *_Control);
  size_t __cdecl wcslen(Constante wchar_t *_Str);
  size_t __cdecl wcsnlen(Constante wchar_t *_Src,size_t _MaxCount);
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,Constante wchar_t *_Source,size_t _Count);
  Inteiro __cdecl wcsncmp(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,Constante wchar_t *_Source,size_t _Count);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(Constante wchar_t *_Str,Constante wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(Constante wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(Constante wchar_t *_Str,Constante wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(Constante wchar_t *_Str,Constante wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,Constante wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(Inteiro _ErrNum);
  _CRTIMP wchar_t *__cdecl __wcserror(Constante wchar_t *_Str);
  _CRTIMP Inteiro __cdecl _wcsicmp(Constante wchar_t *_Str1,Constante wchar_t *_Str2);
  _CRTIMP Inteiro __cdecl _wcsicmp_l(Constante wchar_t *_Str1,Constante wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _wcsnicmp(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro __cdecl _wcsnicmp_l(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,Constante wchar_t *_Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,Constante wchar_t *_Src,size_t _MaxCount,_locale_t _Locale);
  Inteiro __cdecl wcscoll(Constante wchar_t *_Str1,Constante wchar_t *_Str2);
  _CRTIMP Inteiro __cdecl _wcscoll_l(Constante wchar_t *_Str1,Constante wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _wcsicoll(Constante wchar_t *_Str1,Constante wchar_t *_Str2);
  _CRTIMP Inteiro __cdecl _wcsicoll_l(Constante wchar_t *_Str1,Constante wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _wcsncoll(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro __cdecl _wcsncoll_l(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Inteiro __cdecl _wcsnicoll(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro __cdecl _wcsnicoll_l(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);

#SenãoDefinido	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(Constante wchar_t *_Str);
#Defina wcswcs wcsstr
  Inteiro __cdecl wcsicmp(Constante wchar_t *_Str1,Constante wchar_t *_Str2);
  Inteiro __cdecl wcsnicmp(Constante wchar_t *_Str1,Constante wchar_t *_Str2,size_t _MaxCount);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  Inteiro __cdecl wcsicoll(Constante wchar_t *_Str1,Constante wchar_t *_Str2);
#FimSe
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

#SenãoDefinido _WTIME_DEFINED
#Defina _WTIME_DEFINED

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
#FimSe

  Tipo Inteiro mbstate_t;
  Tipo wchar_t _Wint_t;

  wint_t __cdecl btowc(Inteiro);
  size_t __cdecl mbrlen(Constante Caractere *_Ch,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbrtowc(wchar_t *_DstCh,Constante Caractere *_SrcCh,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbsrtowcs(wchar_t *_Dest,Constante Caractere **_PSrc,size_t _Count,mbstate_t *_State);
  size_t __cdecl wcrtomb(Caractere *_Dest,wchar_t _Source,mbstate_t *_State);
  size_t __cdecl wcsrtombs(Caractere *_Dest,Constante wchar_t **_PSource,size_t _Count,mbstate_t *_State);
  Inteiro __cdecl wctob(wint_t _WCh);

#SenãoDefinido __NO_ISOCEXT /* these need Estático lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(Constante wchar_t *s, wchar_t c, size_t n);
  Inteiro wmemcmp(Constante wchar_t *s1, Constante wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,Constante wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, Constante wchar_t *s2, size_t n);
  Longo Longo __cdecl wcstoll(Constante wchar_t *nptr,wchar_t **endptr, Inteiro base);
  SemSinal Longo Longo __cdecl wcstoull(Constante wchar_t *nptr,wchar_t **endptr, Inteiro base);
#FimSe /* __NO_ISOCEXT */

  Vazio *__cdecl memmove(Vazio *_Dst,Constante Vazio *_Src,size_t _MaxCount);
  Vazio *__cdecl memcpy(Vazio *_Dst,Constante Vazio *_Src,size_t _MaxCount);
  __CRT_INLINE Inteiro __cdecl fwide(FILE *_F,Inteiro _M) { (Vazio)_F; Retorno (_M); }
  __CRT_INLINE Inteiro __cdecl mbsinit(Constante mbstate_t *_P) { Retorno (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(Constante wchar_t *_S,wchar_t _C,size_t _N) { Para (;0<_N;++_S,--_N) Se (*_S==_C) Retorno (_CONST_RETURN wchar_t *)(_S); Retorno (0); }
  __CRT_INLINE Inteiro __cdecl wmemcmp(Constante wchar_t *_S1,Constante wchar_t *_S2,size_t _N) { Para (; 0 < _N; ++_S1,++_S2,--_N) Se (*_S1!=*_S2) Retorno (*_S1 < *_S2 ? -1 : +1); Retorno (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,Constante wchar_t *_S2,size_t _N) { Retorno (wchar_t *)memcpy(_S1,_S2,_N*TamanhoDe(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,Constante wchar_t *_S2,size_t _N) { Retorno (wchar_t *)memmove(_S1,_S2,_N*TamanhoDe(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    Para (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    Retorno (_S);
  }
#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)

#Inclua <sec_api/wchar_s.h>
#FimSe
