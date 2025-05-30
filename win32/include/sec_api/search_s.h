/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_SEARCH_S
#Defina _INC_SEARCH_S

#Inclua <search.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  _CRTIMP Vazio *__cdecl _lfind_s(Constante Vazio *_Key,Constante Vazio *_Base,SemSinal Inteiro *_NumOfElements,size_t _SizeOfElements,Inteiro (__cdecl *_PtFuncCompare)(Vazio *,Constante Vazio *,Constante Vazio *),Vazio *_Context);
  _CRTIMP Vazio *__cdecl _lsearch_s(Constante Vazio *_Key,Vazio *_Base,SemSinal Inteiro *_NumOfElements,size_t _SizeOfElements,Inteiro (__cdecl *_PtFuncCompare)(Vazio *,Constante Vazio *,Constante Vazio *),Vazio *_Context);

#SeDefinido __cplusplus
}
#FimSe

#FimSe
#FimSe
