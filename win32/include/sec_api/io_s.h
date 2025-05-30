/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_IO_S
#Defina _INC_IO_S

#Inclua <io.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  _CRTIMP errno_t __cdecl _access_s(Constante Caractere *_Filename,Inteiro _AccessMode);
  _CRTIMP errno_t __cdecl _chsize_s(Inteiro _FileHandle,__int64 _Size);
  _CRTIMP errno_t __cdecl _mktemp_s(Caractere *_TemplateName,size_t _Size);
  _CRTIMP errno_t __cdecl _umask_s(Inteiro _NewMode,Inteiro *_OldMode);

#SenãoDefinido _WIO_S_DEFINED
#Defina _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(Constante wchar_t *_Filename,Inteiro _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t _SizeInWords);
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#FimSe
#FimSe
