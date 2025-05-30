
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _IO_H_
#Defina _IO_H_

#Inclua <_mingw.h>
#Inclua <string.h>

#Diretiva pack(push,_CRT_PACKING)

#SenãoDefinido _POSIX_

#SeDefinido __cplusplus
Externo "C" {
#FimSe

_CRTIMP Caractere* __cdecl _getcwd (Caractere*, Inteiro);
#SenãoDefinido _FSIZE_T_DEFINED
  Tipo SemSinal Longo _fsize_t;
#Defina _FSIZE_T_DEFINED
#FimSe

#SenãoDefinido _FINDDATA_T_DEFINED

  Estrutura _finddata32_t {
    SemSinal attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    Caractere name[260];
  };

/*#Se _INTEGRAL_MAX_BITS >= 64*/

  Estrutura _finddata32i64_t {
    SemSinal attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    Caractere name[260];
  };

  Estrutura _finddata64i32_t {
    SemSinal attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    Caractere name[260];
  };

  Estrutura __finddata64_t {
    SemSinal attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    Caractere name[260];
  };
/* #FimSe */

#SeDefinido _USE_32BIT_TIME_T
#Defina _finddata_t _finddata32_t
#Defina _finddatai64_t _finddata32i64_t

#SeDefinido _WIN64
#Defina _findfirst _findfirst32
#Defina _findnext _findnext32
#Senão
#Defina _findfirst32 _findfirst
#Defina _findnext32 _findnext
#FimSe
#Defina _findfirsti64 _findfirst32i64
#Defina _findnexti64 _findnext32i64
#Senão
#Defina _finddata_t _finddata64i32_t
#Defina _finddatai64_t __finddata64_t

#Defina _findfirst _findfirst64i32
#Defina _findnext _findnext64i32
#Defina _findfirsti64 _findfirst64
#Defina _findnexti64 _findnext64
#FimSe

#Defina _FINDDATA_T_DEFINED
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

#Defina _A_NORMAL 0x00
#Defina _A_RDONLY 0x01
#Defina _A_HIDDEN 0x02
#Defina _A_SYSTEM 0x04
#Defina _A_SUBDIR 0x10
#Defina _A_ARCH 0x20

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
#Se Definido(__GNUC__) && Definido(__STRICT_ANSI__)
  Tipo Inteiro _off64_t __attribute__ ((mode (DI)));
#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
  Tipo Inteiro off64_t __attribute__ ((mode (DI)));
#FimSe
#Senão
  Tipo Longo Longo _off64_t;
#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
  Tipo Longo Longo off64_t;
#FimSe
#FimSe
#FimSe

  /* Some defines Para _access nAccessMode (MS doesn't Defina them, but
  * it doesn't seem to hurt to add them). */
#Defina	F_OK	0	/* Check Para file existence */
#Defina	X_OK	1	/* Check Para execute permission. */
#Defina	W_OK	2	/* Check Para write permission */
#Defina	R_OK	4	/* Check Para read permission */

  _CRTIMP Inteiro __cdecl _access(Constante Caractere *_Filename,Inteiro _AccessMode);
  _CRTIMP Inteiro __cdecl _chmod(Constante Caractere *_Filename,Inteiro _Mode);
  _CRTIMP Inteiro __cdecl _chsize(Inteiro _FileHandle,Longo _Size);
  _CRTIMP Inteiro __cdecl _close(Inteiro _FileHandle);
  _CRTIMP Inteiro __cdecl _commit(Inteiro _FileHandle);
  _CRTIMP Inteiro __cdecl _creat(Constante Caractere *_Filename,Inteiro _PermissionMode);
  _CRTIMP Inteiro __cdecl _dup(Inteiro _FileHandle);
  _CRTIMP Inteiro __cdecl _dup2(Inteiro _FileHandleSrc,Inteiro _FileHandleDst);
  _CRTIMP Inteiro __cdecl _eof(Inteiro _FileHandle);
  _CRTIMP Longo __cdecl _filelength(Inteiro _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(Constante Caractere *_Filename,Estrutura _finddata32_t *_FindData);
  _CRTIMP Inteiro __cdecl _findnext32(intptr_t _FindHandle,Estrutura _finddata32_t *_FindData);
  _CRTIMP Inteiro __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP Inteiro __cdecl _isatty(Inteiro _FileHandle);
  _CRTIMP Inteiro __cdecl _locking(Inteiro _FileHandle,Inteiro _LockMode,Longo _NumOfBytes);
  _CRTIMP Longo __cdecl _lseek(Inteiro _FileHandle,Longo _Offset,Inteiro _Origin);
  _off64_t lseek64(Inteiro fd,_off64_t offset, Inteiro whence);
  _CRTIMP Caractere *__cdecl _mktemp(Caractere *_TemplateName);
  _CRTIMP Inteiro __cdecl _pipe(Inteiro *_PtHandles,SemSinal Inteiro _PipeSize,Inteiro _TextMode);
  _CRTIMP Inteiro __cdecl _read(Inteiro _FileHandle,Vazio *_DstBuf,SemSinal Inteiro _MaxCharCount);

#SenãoDefinido _CRT_DIRECTORY_DEFINED
#Defina _CRT_DIRECTORY_DEFINED
  Inteiro __cdecl remove(Constante Caractere *_Filename);
  Inteiro __cdecl rename(Constante Caractere *_OldFilename,Constante Caractere *_NewFilename);
  _CRTIMP Inteiro __cdecl _unlink(Constante Caractere *_Filename);
#SenãoDefinido	NO_OLDNAMES
  Inteiro __cdecl unlink(Constante Caractere *_Filename);
#FimSe
#FimSe

  _CRTIMP Inteiro __cdecl _setmode(Inteiro _FileHandle,Inteiro _Mode);
  _CRTIMP Longo __cdecl _tell(Inteiro _FileHandle);
  _CRTIMP Inteiro __cdecl _umask(Inteiro _Mode);
  _CRTIMP Inteiro __cdecl _write(Inteiro _FileHandle,Constante Vazio *_Buf,SemSinal Inteiro _MaxCharCount);

#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(Inteiro _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(Constante Caractere *_Filename,Estrutura _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(Constante Caractere *_Filename,Estrutura __finddata64_t *_FindData);
#SeDefinido __cplusplus
#Inclua <string.h>
#FimSe
  intptr_t __cdecl _findfirst64i32(Constante Caractere *_Filename,Estrutura _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(Constante Caractere *_Filename,Estrutura _finddata64i32_t *_FindData)
  {
    Estrutura __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    Retorno ret;
  }
  _CRTIMP Inteiro __cdecl _findnext32i64(intptr_t _FindHandle,Estrutura _finddata32i64_t *_FindData);
  _CRTIMP Inteiro __cdecl _findnext64(intptr_t _FindHandle,Estrutura __finddata64_t *_FindData);
  Inteiro __cdecl _findnext64i32(intptr_t _FindHandle,Estrutura _finddata64i32_t *_FindData);
  __CRT_INLINE Inteiro __cdecl _findnext64i32(intptr_t _FindHandle,Estrutura _finddata64i32_t *_FindData)
  {
    Estrutura __finddata64_t fd;
    Inteiro ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    Retorno ret;
  }
  __int64 __cdecl _lseeki64(Inteiro _FileHandle,__int64 _Offset,Inteiro _Origin);
  __int64 __cdecl _telli64(Inteiro _FileHandle);
#FimSe
#SenãoDefinido NO_OLDNAMES

#SenãoDefinido _UWIN
  Inteiro __cdecl chdir (Constante Caractere *);
  Caractere *__cdecl getcwd (Caractere *, Inteiro);
  Inteiro __cdecl mkdir (Constante Caractere *);
  Caractere *__cdecl mktemp(Caractere *);
  Inteiro __cdecl rmdir (Constante Caractere*);
  Inteiro __cdecl chmod (Constante Caractere *, Inteiro);
#FimSe /* _UWIN */

#FimSe /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(Inteiro *_FileHandle,Constante Caractere *_Filename,Inteiro _OpenFlag,Inteiro _ShareFlag,Inteiro _PermissionMode);

#SenãoDefinido __cplusplus
  _CRTIMP Inteiro __cdecl _open(Constante Caractere *_Filename,Inteiro _OpenFlag,...);
  _CRTIMP Inteiro __cdecl _sopen(Constante Caractere *_Filename,Inteiro _OpenFlag,Inteiro _ShareFlag,...);
#Senão
  Externo "C++" _CRTIMP Inteiro __cdecl _open(Constante Caractere *_Filename,Inteiro _Openflag,Inteiro _PermissionMode = 0);
  Externo "C++" _CRTIMP Inteiro __cdecl _sopen(Constante Caractere *_Filename,Inteiro _Openflag,Inteiro _ShareFlag,Inteiro _PermissionMode = 0);
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

  Inteiro __cdecl __lock_fhandle(Inteiro _Filehandle);
  Vazio __cdecl _unlock_fhandle(Inteiro _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(Inteiro _FileHandle);
  _CRTIMP Inteiro __cdecl _open_osfhandle(intptr_t _OSFileHandle,Inteiro _Flags);

#SenãoDefinido	NO_OLDNAMES
  Inteiro __cdecl access(Constante Caractere *_Filename,Inteiro _AccessMode);
  Inteiro __cdecl chmod(Constante Caractere *_Filename,Inteiro _AccessMode);
  Inteiro __cdecl chsize(Inteiro _FileHandle,Longo _Size);
  Inteiro __cdecl close(Inteiro _FileHandle);
  Inteiro __cdecl creat(Constante Caractere *_Filename,Inteiro _PermissionMode);
  Inteiro __cdecl dup(Inteiro _FileHandle);
  Inteiro __cdecl dup2(Inteiro _FileHandleSrc,Inteiro _FileHandleDst);
  Inteiro __cdecl eof(Inteiro _FileHandle);
  Longo __cdecl filelength(Inteiro _FileHandle);
  Inteiro __cdecl isatty(Inteiro _FileHandle);
  Inteiro __cdecl locking(Inteiro _FileHandle,Inteiro _LockMode,Longo _NumOfBytes);
  Longo __cdecl lseek(Inteiro _FileHandle,Longo _Offset,Inteiro _Origin);
  Caractere *__cdecl mktemp(Caractere *_TemplateName);
  Inteiro __cdecl open(Constante Caractere *_Filename,Inteiro _OpenFlag,...);
  Inteiro __cdecl read(Inteiro _FileHandle,Vazio *_DstBuf,SemSinal Inteiro _MaxCharCount);
  Inteiro __cdecl setmode(Inteiro _FileHandle,Inteiro _Mode);
  Inteiro __cdecl sopen(Constante Caractere *_Filename,Inteiro _OpenFlag,Inteiro _ShareFlag,...);
  Longo __cdecl tell(Inteiro _FileHandle);
  Inteiro __cdecl umask(Inteiro _Mode);
  Inteiro __cdecl write(Inteiro _Filehandle,Constante Vazio *_Buf,SemSinal Inteiro _MaxCharCount);
#FimSe

#SeDefinido __cplusplus
}
#FimSe
#FimSe

#SeDefinido __cplusplus
Externo "C" {
#FimSe

/* Misc stuff */
Caractere *getlogin(Vazio);
#SeDefinido __USE_MINGW_ALARM
SemSinal Inteiro alarm(SemSinal Inteiro seconds);
#FimSe

#SeDefinido __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, Enquanto the version
    shipped with Vista, returns an Erro code.  This will restore the
    old behaviour  */
Estático EmLinha Inteiro __mingw_access (Constante Caractere *__fname, Inteiro __mode) {
  Retorno  _access (__fname, __mode & ~X_OK);
}

#Defina access(__f,__m)  __mingw_access (__f, __m)
#FimSe


#SeDefinido __cplusplus
}
#FimSe


#Diretiva pack(pop)

#Inclua <sec_api/io_s.h>

#FimSe /* End _IO_H_ */

