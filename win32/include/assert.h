/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido __ASSERT_H_
#Defina __ASSERT_H_

#Inclua <_mingw.h>
#SeDefinido __cplusplus
#Inclua <stdlib.h>
#FimSe

#SeDefinido NDEBUG
#SenãoDefinido assert
#Defina assert(_Expression) ((Vazio)0)
#FimSe
#Senão

#SenãoDefinido _CRT_TERMINATE_DEFINED
#Defina _CRT_TERMINATE_DEFINED
  Vazio __cdecl __MINGW_NOTHROW exit(Inteiro _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP Vazio __cdecl __MINGW_NOTHROW _exit(Inteiro _Code) __MINGW_ATTRIB_NORETURN;
#Se !Definido __NO_ISOCEXT /* Externo stub in Estático libmingwex.a */
/* C99 function name */
Vazio __cdecl _Exit(Inteiro) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN Vazio __cdecl _Exit(Inteiro status)
{  _exit(status); }
#FimSe

#Diretiva push_macro("abort")
#Indefinido abort
  Vazio __cdecl __declspec(noreturn) abort(Vazio);
#Diretiva pop_macro("abort")

#FimSe

#SeDefinido __cplusplus
Externo "C" {
#FimSe


Externo Vazio __cdecl _wassert(Constante wchar_t *_Message,Constante wchar_t *_File,SemSinal _Line);
Externo Vazio __cdecl _assert(Constante Caractere *, Constante Caractere *, SemSinal);

#SeDefinido __cplusplus
}
#FimSe

#SenãoDefinido assert
//#Defina assert(_Expression) (Vazio)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__ARQUIVO__),__LINHA__),0))
#Defina assert(e) ((e) ? (Vazio)0 : _assert(#e, __ARQUIVO__, __LINHA__))
#FimSe

#FimSe

#FimSe
