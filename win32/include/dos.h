/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_DOS
#Defina _INC_DOS

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

#Defina _A_NORMAL 0x00
#Defina _A_RDONLY 0x01
#Defina _A_HIDDEN 0x02
#Defina _A_SYSTEM 0x04
#Defina _A_SUBDIR 0x10
#Defina _A_ARCH 0x20

#SenãoDefinido _GETDISKFREE_DEFINED
#Defina _GETDISKFREE_DEFINED
  _CRTIMP SemSinal __cdecl _getdiskfree(SemSinal _Drive,Estrutura _diskfree_t *_DiskFree);
#FimSe

#Se (Definido(_X86_) && !Definido(__x86_64))
  Vazio __cdecl _disable(Vazio);
  Vazio __cdecl _enable(Vazio);
#FimSe

#SenãoDefinido	NO_OLDNAMES
#Defina diskfree_t _diskfree_t
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)
#FimSe
