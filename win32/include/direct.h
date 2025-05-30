/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_DIRECT
#Defina _INC_DIRECT

#Inclua <_mingw.h>
#Inclua <io.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido _DISKFREE_T_DEFINED
#Defina _DISKFREE_T_DEFINED
  Estrutura _diskfree_t {
    SemSinal total_clusters;
    SemSinal avail_clusters;
    SemSinal sectors_per_cluster;
    SemSinal bytes_per_sector;
  };
#FimSe

  _CRTIMP Caractere *__cdecl _getcwd(Caractere *_DstBuf,Inteiro _SizeInBytes);
  _CRTIMP Caractere *__cdecl _getdcwd(Inteiro _Drive,Caractere *_DstBuf,Inteiro _SizeInBytes);
  Caractere *__cdecl _getdcwd_nolock(Inteiro _Drive,Caractere *_DstBuf,Inteiro _SizeInBytes);
  _CRTIMP Inteiro __cdecl _chdir(Constante Caractere *_Path);
  _CRTIMP Inteiro __cdecl _mkdir(Constante Caractere *_Path);
  _CRTIMP Inteiro __cdecl _rmdir(Constante Caractere *_Path);
  _CRTIMP Inteiro __cdecl _chdrive(Inteiro _Drive);
  _CRTIMP Inteiro __cdecl _getdrive(Vazio);
  _CRTIMP SemSinal Longo __cdecl _getdrives(Vazio);

#SenãoDefinido _GETDISKFREE_DEFINED
#Defina _GETDISKFREE_DEFINED
  _CRTIMP SemSinal __cdecl _getdiskfree(SemSinal _Drive,Estrutura _diskfree_t *_DiskFree);
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

#SenãoDefinido	NO_OLDNAMES

#Defina diskfree_t _diskfree_t

  Caractere *__cdecl getcwd(Caractere *_DstBuf,Inteiro _SizeInBytes);
  Inteiro __cdecl chdir(Constante Caractere *_Path);
  Inteiro __cdecl mkdir(Constante Caractere *_Path);
  Inteiro __cdecl rmdir(Constante Caractere *_Path);
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)
#FimSe
