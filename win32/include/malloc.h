/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _MALLOC_H_
#Defina _MALLOC_H_

#Inclua <_mingw.h>

#Diretiva pack(push,_CRT_PACKING)

#SenãoDefinido _MM_MALLOC_H_INCLUDED
#Defina _MM_MALLOC_H_INCLUDED
#FimSe

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeDefinido _WIN64
#Defina _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#Senão
#Defina _HEAP_MAXREQ 0xFFFFFFE0
#FimSe

#SenãoDefinido _STATIC_ASSERT
#Defina _STATIC_ASSERT(expr) Externo Vazio __static_assert_t(Inteiro [(expr)?1:-1])
#FimSe

/* Return codes Para _heapwalk()  */
#Defina _HEAPEMPTY (-1)
#Defina _HEAPOK (-2)
#Defina _HEAPBADBEGIN (-3)
#Defina _HEAPBADNODE (-4)
#Defina _HEAPEND (-5)
#Defina _HEAPBADPTR (-6)

/* Values Para _heapinfo.useflag */
#Defina _FREEENTRY 0
#Defina _USEDENTRY 1

#SenãoDefinido _HEAPINFO_DEFINED
#Defina _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  Tipo Estrutura _heapinfo {
    Inteiro *_pentry;
    size_t _size;
    Inteiro _useflag;
  } _HEAPINFO;
#FimSe

  Externo SemSinal Inteiro _amblksiz;

#Defina _mm_free(a) _aligned_free(a)
#Defina _mm_malloc(a,b) _aligned_malloc(a,b)

#SenãoDefinido _CRT_ALLOCATION_DEFINED
#Defina _CRT_ALLOCATION_DEFINED
  Vazio *__cdecl calloc(size_t _NumOfElements,size_t _SizeOfElements);
  Vazio __cdecl free(Vazio *_Memory);
  Vazio *__cdecl malloc(size_t _Size);
  Vazio *__cdecl realloc(Vazio *_Memory,size_t _NewSize);
  _CRTIMP Vazio *__cdecl _recalloc(Vazio *_Memory,size_t _Count,size_t _Size);
  /*	_CRTIMP Vazio __cdecl _aligned_free(Vazio *_Memory);
  _CRTIMP Vazio *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment); */
  _CRTIMP Vazio *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP Vazio *__cdecl _aligned_realloc(Vazio *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP Vazio *__cdecl _aligned_recalloc(Vazio *_Memory,size_t _Count,size_t _Size,size_t _Alignment);
  _CRTIMP Vazio *__cdecl _aligned_offset_realloc(Vazio *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP Vazio *__cdecl _aligned_offset_recalloc(Vazio *_Memory,size_t _Count,size_t _Size,size_t _Alignment,size_t _Offset);
#FimSe

#Defina _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP Inteiro __cdecl _resetstkoflw (Vazio);
  _CRTIMP SemSinal Longo __cdecl _set_malloc_crt_max_wait(SemSinal Longo _NewValue);

  _CRTIMP Vazio *__cdecl _expand(Vazio *_Memory,size_t _NewSize);
  _CRTIMP size_t __cdecl _msize(Vazio *_Memory);
#SeDefinido __GNUC__
#Indefinido _alloca
#Defina _alloca(x) __builtin_alloca((x))
#Senão
  /* ctec implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at Inclua/stddef.h (which is distributed with ctec).
   */
#SeDefinido _alloca
#Indefinido _alloca
#FimSe
#Defina _alloca(x) alloca((x))
#FimSe
  _CRTIMP size_t __cdecl _get_sbh_threshold(Vazio);
  _CRTIMP Inteiro __cdecl _set_sbh_threshold(size_t _NewValue);
  _CRTIMP errno_t __cdecl _set_amblksiz(size_t _Value);
  _CRTIMP errno_t __cdecl _get_amblksiz(size_t *_Value);
  _CRTIMP Inteiro __cdecl _heapadd(Vazio *_Memory,size_t _Size);
  _CRTIMP Inteiro __cdecl _heapchk(Vazio);
  _CRTIMP Inteiro __cdecl _heapmin(Vazio);
  _CRTIMP Inteiro __cdecl _heapset(SemSinal Inteiro _Fill);
  _CRTIMP Inteiro __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP size_t __cdecl _heapused(size_t *_Used,size_t *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(Vazio);

#Defina _ALLOCA_S_THRESHOLD 1024
#Defina _ALLOCA_S_STACK_MARKER 0xCCCC
#Defina _ALLOCA_S_HEAP_MARKER 0xDDDD

#Se(Definido(_X86_) && !Definido(__x86_64))
#Defina _ALLOCA_S_MARKER_SIZE 8
#SenãoSe Definido(__ia64__) || Definido(__x86_64)
#Defina _ALLOCA_S_MARKER_SIZE 16
#FimSe

#Se !Definido(RC_INVOKED)
  Estático EmLinha Vazio *_MarkAllocaS(Vazio *_Ptr,SemSinal Inteiro _Marker) {
    Se(_Ptr) {
      *((SemSinal Inteiro*)_Ptr) = _Marker;
      _Ptr = (Caractere*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    Retorno _Ptr;
  }
#FimSe

#Indefinido _malloca
#Defina _malloca(size) \
  ((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_STACK_MARKER) : \
    _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_HEAP_MARKER))
#Indefinido _FREEA_INLINE
#Defina _FREEA_INLINE

#SenãoDefinido RC_INVOKED
#Indefinido _freea
  Estático EmLinha Vazio __cdecl _freea(Vazio *_Memory) {
    SemSinal Inteiro _Marker;
    Se(_Memory) {
      _Memory = (Caractere*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(SemSinal Inteiro *)_Memory;
      Se(_Marker==_ALLOCA_S_HEAP_MARKER) {
	free(_Memory);
      }
#SeDefinido _ASSERTE
      Senão Se(_Marker!=_ALLOCA_S_STACK_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#FimSe
    }
  }
#FimSe /* RC_INVOKED */

#SenãoDefinido	NO_OLDNAMES
#SeDefinido __GNUC__
#Indefinido alloca
#Defina alloca(x) __builtin_alloca((x))
#FimSe
#FimSe

#SeDefinido HEAPHOOK
#SenãoDefinido _HEAPHOOK_DEFINED
#Defina _HEAPHOOK_DEFINED
  Tipo Inteiro (__cdecl *_HEAPHOOK)(Inteiro,size_t,Vazio *,Vazio **);
#FimSe

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#Defina _HEAP_MALLOC 1
#Defina _HEAP_CALLOC 2
#Defina _HEAP_FREE 3
#Defina _HEAP_REALLOC 4
#Defina _HEAP_MSIZE 5
#Defina _HEAP_EXPAND 6
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)

#FimSe /* _MALLOC_H_ */
