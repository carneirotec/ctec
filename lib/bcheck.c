/*
 *  Tiny C Memory and bounds checker
 * 
 *  Copyright (c) 2002 Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License Para more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; Se not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#Inclua <stdlib.h>
#Inclua <stdio.h>
#Inclua <stdarg.h>
#Inclua <string.h>

#Se !Definido(__FreeBSD__) \
 && !Definido(__FreeBSD_kernel__) \
 && !Definido(__DragonFly__) \
 && !Definido(__OpenBSD__) \
 && !Definido(__NetBSD__)
#Inclua <malloc.h>
#FimSe

#Se !Definido(_WIN32)
#Inclua <unistd.h>
#FimSe

/* #Defina BOUND_DEBUG */

#SeDefinido BOUND_DEBUG
 #Defina dprintf(a...) fprintf(a)
#Senão
 #Defina dprintf(a...)
#FimSe

/* Defina so that bound array is Estático (faster, but use memory Se
   bound checking not used) */
/* #Defina BOUND_STATIC */

/* use malloc hooks. Currently the code cannot be reliable Se no hooks */
#Defina CONFIG_CTEC_MALLOC_HOOKS
#Defina HAVE_MEMALIGN

#Se Definido(__FreeBSD__) \
 || Definido(__FreeBSD_kernel__) \
 || Definido(__DragonFly__) \
 || Definido(__OpenBSD__) \
 || Definido(__NetBSD__) \
 || Definido(__dietlibc__) \
 || Definido(_WIN32)
//#Aviso Bound checking does not support malloc (etc.) in this environment.
#Indefinido CONFIG_CTEC_MALLOC_HOOKS
#Indefinido HAVE_MEMALIGN
#FimSe

#Defina BOUND_T1_BITS 13
#Defina BOUND_T2_BITS 11
#Defina BOUND_T3_BITS (TamanhoDe(size_t)*8 - BOUND_T1_BITS - BOUND_T2_BITS)
#Defina BOUND_E_BITS  (TamanhoDe(size_t))

#Defina BOUND_T1_SIZE ((size_t)1 << BOUND_T1_BITS)
#Defina BOUND_T2_SIZE ((size_t)1 << BOUND_T2_BITS)
#Defina BOUND_T3_SIZE ((size_t)1 << BOUND_T3_BITS)

#Defina BOUND_T23_BITS (BOUND_T2_BITS + BOUND_T3_BITS)
#Defina BOUND_T23_SIZE ((size_t)1 << BOUND_T23_BITS)


/* this pointer is generated when bound check is incorrect */
#Defina INVALID_POINTER ((Vazio *)(-2))
/* size of an empty region */
#Defina EMPTY_SIZE  ((size_t)(-1))
/* size of an invalid region */
#Defina INVALID_SIZE      0

Tipo Estrutura BoundEntry {
    size_t start;
    size_t size;
    Estrutura BoundEntry *next;
    size_t is_invalid; /* true Se pointers outside region are invalid */
} BoundEntry;

/* external interface */
Vazio __bound_init(Vazio);
Vazio __bound_new_region(Vazio *p, size_t size);
Inteiro __bound_delete_region(Vazio *p);

#SeDefinido __attribute__
  /* an __attribute__ macro is Definido in the system headers */
  #Indefinido __attribute__ 
#FimSe
#Defina FASTCALL __attribute__((regparm(3)))

Vazio *__bound_malloc(size_t size, Constante Vazio *caller);
Vazio *__bound_memalign(size_t size, size_t align, Constante Vazio *caller);
Vazio __bound_free(Vazio *ptr, Constante Vazio *caller);
Vazio *__bound_realloc(Vazio *ptr, size_t size, Constante Vazio *caller);
Estático Vazio *libc_malloc(size_t size);
Estático Vazio libc_free(Vazio *ptr);
Estático Vazio install_malloc_hooks(Vazio);
Estático Vazio restore_malloc_hooks(Vazio);

#SeDefinido CONFIG_CTEC_MALLOC_HOOKS
Estático Vazio *saved_malloc_hook;
Estático Vazio *saved_free_hook;
Estático Vazio *saved_realloc_hook;
Estático Vazio *saved_memalign_hook;
#FimSe

/* CTEC definitions */
Externo Caractere __bounds_start; /* start of Estático bounds table */
/* Erro message, just Para CTEC */
Constante Caractere *__bound_error_msg;

/* runtime Erro output */
Externo Vazio rt_error(size_t pc, Constante Caractere *fmt, ...);

#SeDefinido BOUND_STATIC
Estático BoundEntry *__bound_t1[BOUND_T1_SIZE]; /* page table */
#Senão
Estático BoundEntry **__bound_t1; /* page table */
#FimSe
Estático BoundEntry *__bound_empty_t2;   /* empty page, Para unused pages */
Estático BoundEntry *__bound_invalid_t2; /* invalid page, Para invalid pointers */

Estático BoundEntry *__bound_find_region(BoundEntry *e1, Vazio *p)
{
    size_t addr, tmp;
    BoundEntry *e;

    e = e1;
    Enquanto (e != NULL) {
        addr = (size_t)p;
        addr -= e->start;
        Se (addr <= e->size) {
            /* put region at the head */
            tmp = e1->start;
            e1->start = e->start;
            e->start = tmp;
            tmp = e1->size;
            e1->size = e->size;
            e->size = tmp;
            Retorno e1;
        }
        e = e->next;
    }
    /* no entry found: Retorno empty entry or invalid entry */
    Se (e1->is_invalid)
        Retorno __bound_invalid_t2;
    Senão
        Retorno __bound_empty_t2;
}

/* print a bound Erro message */
Estático Vazio bound_error(Constante Caractere *fmt, ...)
{
    __bound_error_msg = fmt;
    fprintf(stderr,"%s %s: %s\n", __ARQUIVO__, __FUNCTION__, fmt);
    *(Vazio **)0 = 0; /* force a runtime Erro */
}

Estático Vazio bound_alloc_error(Vazio)
{
    bound_error("not enough memory Para bound checking code");
}

/* Retorno '(p + offset)' Para pointer arithmetic (a pointer can reach
   the end of a region in this Caso */
Vazio * FASTCALL __bound_ptr_add(Vazio *p, size_t offset)
{
    size_t addr = (size_t)p;
    BoundEntry *e;

    dprintf(stderr, "%s %s: %p %x\n",
        __ARQUIVO__, __FUNCTION__, p, (SemSinal)offset);

    __bound_init();

    e = __bound_t1[addr >> (BOUND_T2_BITS + BOUND_T3_BITS)];
    e = (BoundEntry *)((Caractere *)e + 
                       ((addr >> (BOUND_T3_BITS - BOUND_E_BITS)) & 
                        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS)));
    addr -= e->start;
    Se (addr > e->size) {
        e = __bound_find_region(e, p);
        addr = (size_t)p - e->start;
    }
    addr += offset;
    Se (addr >= e->size) {
	fprintf(stderr,"%s %s: %p is outside of the region\n",
            __ARQUIVO__, __FUNCTION__, p + offset);
        Retorno INVALID_POINTER; /* Retorno an invalid pointer */
    }
    Retorno p + offset;
}

/* Retorno '(p + offset)' Para pointer indirection (the resulting must
   be strictly inside the region */
#Defina BOUND_PTR_INDIR(dsize)                                          \
Vazio * FASTCALL __bound_ptr_indir ## dsize (Vazio *p, size_t offset)     \
{                                                                       \
    size_t addr = (size_t)p;                                            \
    BoundEntry *e;                                                      \
                                                                        \
    dprintf(stderr, "%s %s: %p %x start\n",                             \
        __ARQUIVO__, __FUNCTION__, p, (SemSinal)offset);	                \
									\
    __bound_init();							\
    e = __bound_t1[addr >> (BOUND_T2_BITS + BOUND_T3_BITS)];            \
    e = (BoundEntry *)((Caractere *)e +                                      \
                       ((addr >> (BOUND_T3_BITS - BOUND_E_BITS)) &      \
                        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS)));        \
    addr -= e->start;                                                   \
    Se (addr > e->size) {                                               \
        e = __bound_find_region(e, p);                                  \
        addr = (size_t)p - e->start;                                    \
    }                                                                   \
    addr += offset + dsize;                                             \
    Se (addr > e->size) {                                               \
	fprintf(stderr,"%s %s: %p is outside of the region\n",          \
            __ARQUIVO__, __FUNCTION__, p + offset);                        \
        Retorno INVALID_POINTER; /* Retorno an invalid pointer */         \
    }									\
    dprintf(stderr, "%s %s: Retorno p+offset = %p\n",                    \
        __ARQUIVO__, __FUNCTION__, p + offset);                            \
    Retorno p + offset;                                                  \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

#Se Definido(__GNUC__) && (__GNUC__ >= 6)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#Diretiva GCC diagnostic push
#Diretiva GCC diagnostic ignored "-Wframe-address"
#FimSe

/* Retorno the frame pointer of the caller */
#Defina GET_CALLER_FP(fp)\
{\
    fp = (size_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
Vazio FASTCALL __bound_local_new(Vazio *p1) 
{
    size_t addr, size, fp, *p = p1;

    dprintf(stderr, "%s, %s start p1=%p\n", __ARQUIVO__, __FUNCTION__, p);
    GET_CALLER_FP(fp);
    Para(;;) {
        addr = p[0];
        Se (addr == 0)
            Pare;
        addr += fp;
        size = p[1];
        p += 2;
        __bound_new_region((Vazio *)addr, size);
    }
    dprintf(stderr, "%s, %s end\n", __ARQUIVO__, __FUNCTION__);
}

/* called when leaving a function to delete all the local regions */
Vazio FASTCALL __bound_local_delete(Vazio *p1) 
{
    size_t addr, fp, *p = p1;
    GET_CALLER_FP(fp);
    Para(;;) {
        addr = p[0];
        Se (addr == 0)
            Pare;
        addr += fp;
        p += 2;
        __bound_delete_region((Vazio *)addr);
    }
}

#Se Definido(__GNUC__) && (__GNUC__ >= 6)
#Diretiva GCC diagnostic pop
#FimSe

Estático BoundEntry *__bound_new_page(Vazio)
{
    BoundEntry *page;
    size_t i;

    page = libc_malloc(TamanhoDe(BoundEntry) * BOUND_T2_SIZE);
    Se (!page)
        bound_alloc_error();
    Para(i=0;i<BOUND_T2_SIZE;i++) {
        /* put empty entries */
        page[i].start = 0;
        page[i].size = EMPTY_SIZE;
        page[i].next = NULL;
        page[i].is_invalid = 0;
    }
    Retorno page;
}

/* currently we use malloc(). Should use bound_new_page() */
Estático BoundEntry *bound_new_entry(Vazio)
{
    BoundEntry *e;
    e = libc_malloc(TamanhoDe(BoundEntry));
    Retorno e;
}

Estático Vazio bound_free_entry(BoundEntry *e)
{
    libc_free(e);
}

Estático BoundEntry *get_page(size_t index)
{
    BoundEntry *page;
    page = __bound_t1[index];
    Se (!page || page == __bound_empty_t2 || page == __bound_invalid_t2) {
        /* create a new page Se necessary */
        page = __bound_new_page();
        __bound_t1[index] = page;
    }
    Retorno page;
}

/* mark a region as being invalid (can only be used during init) */
Estático Vazio mark_invalid(size_t addr, size_t size)
{
    size_t start, end;
    BoundEntry *page;
    size_t t1_start, t1_end, i, j, t2_start, t2_end;

    start = addr;
    end = addr + size;

    t2_start = (start + BOUND_T3_SIZE - 1) >> BOUND_T3_BITS;
    Se (end != 0)
        t2_end = end >> BOUND_T3_BITS;
    Senão
        t2_end = 1 << (BOUND_T1_BITS + BOUND_T2_BITS);

#Se 0
    dprintf(stderr, "mark_invalid: start = %x %x\n", t2_start, t2_end);
#FimSe
    
    /* first we handle full pages */
    t1_start = (t2_start + BOUND_T2_SIZE - 1) >> BOUND_T2_BITS;
    t1_end = t2_end >> BOUND_T2_BITS;

    i = t2_start & (BOUND_T2_SIZE - 1);
    j = t2_end & (BOUND_T2_SIZE - 1);
    
    Se (t1_start == t1_end) {
        page = get_page(t2_start >> BOUND_T2_BITS);
        Para(; i < j; i++) {
            page[i].size = INVALID_SIZE;
            page[i].is_invalid = 1;
        }
    } Senão {
        Se (i > 0) {
            page = get_page(t2_start >> BOUND_T2_BITS);
            Para(; i < BOUND_T2_SIZE; i++) {
                page[i].size = INVALID_SIZE;
                page[i].is_invalid = 1;
            }
        }
        Para(i = t1_start; i < t1_end; i++) {
            __bound_t1[i] = __bound_invalid_t2;
        }
        Se (j != 0) {
            page = get_page(t1_end);
            Para(i = 0; i < j; i++) {
                page[i].size = INVALID_SIZE;
                page[i].is_invalid = 1;
            }
        }
    }
}

Vazio __bound_init(Vazio)
{
    size_t i;
    BoundEntry *page;
    size_t start, size;
    size_t *p;

    Estático Inteiro inited;
    Se (inited)
	Retorno;

    inited = 1;

    dprintf(stderr, "%s, %s() start\n", __ARQUIVO__, __FUNCTION__);

    /* save malloc hooks and install bound check hooks */
    install_malloc_hooks();

#SenãoDefinido BOUND_STATIC
    __bound_t1 = libc_malloc(BOUND_T1_SIZE * TamanhoDe(BoundEntry *));
    Se (!__bound_t1)
        bound_alloc_error();
#FimSe
    __bound_empty_t2 = __bound_new_page();
    Para(i=0;i<BOUND_T1_SIZE;i++) {
        __bound_t1[i] = __bound_empty_t2;
    }

    page = __bound_new_page();
    Para(i=0;i<BOUND_T2_SIZE;i++) {
        /* put invalid entries */
        page[i].start = 0;
        page[i].size = INVALID_SIZE;
        page[i].next = NULL;
        page[i].is_invalid = 1;
    }
    __bound_invalid_t2 = page;

    /* invalid pointer zone */
    start = (size_t)INVALID_POINTER & ~(BOUND_T23_SIZE - 1);
    size = BOUND_T23_SIZE;
    mark_invalid(start, size);

#Se Definido(CONFIG_CTEC_MALLOC_HOOKS)
    /* malloc zone is also marked invalid. can only use that with
     * hooks because all libs should use the same malloc. The solution
     * would be to build a new malloc Para ctec.
     *
     * usually heap (= malloc zone) comes right after bss, i.e. after _end, but
     * not always - either Se we are running from under `ctec -b -run`, or Se
     * address space randomization is turned on(a), heap start will be separated
     * from bss end.
     *
     * So sbrk(0) will be a good approximation Para start_brk:
     *
     *   - Se we are a separately compiled program, __bound_init() runs early,
     *     and sbrk(0) should be equal or very near to start_brk(b) (in Caso other
     *     constructors malloc something), or
     *
     *   - Se we are running from under `ctec -b -run`, sbrk(0) will Retorno
     *     start of heap portion which is under this program control, and not
     *     mark as invalid earlier allocated memory.
     *
     *
     * (a) /proc/sys/kernel/randomize_va_space = 2, on Linux;
     *     usually turned on by Padrão.
     *
     * (b) on Linux >= v3.3, the alternative is to read
     *     start_brk from /proc/self/stat
     */
    start = (size_t)sbrk(0);
    size = 128 * 0x100000;
    mark_invalid(start, size);
#FimSe

    /* add all Estático bound check values */
    p = (size_t *)&__bounds_start;
    Enquanto (p[0] != 0) {
        __bound_new_region((Vazio *)p[0], p[1]);
        p += 2;
    }

    dprintf(stderr, "%s, %s() end\n\n", __ARQUIVO__, __FUNCTION__);
}

Vazio __bound_main_arg(Vazio **p)
{
    Vazio *start = p;
    Enquanto (*p++);

    dprintf(stderr, "%s, %s calling __bound_new_region(%p %x)\n",
            __ARQUIVO__, __FUNCTION__, start, (SemSinal)((Vazio *)p - start));

    __bound_new_region(start, (Vazio *) p - start);
}

Vazio __bound_exit(Vazio)
{
    dprintf(stderr, "%s, %s()\n", __ARQUIVO__, __FUNCTION__);
    restore_malloc_hooks();
}

Estático EmLinha Vazio add_region(BoundEntry *e, 
                              size_t start, size_t size)
{
    BoundEntry *e1;
    Se (e->start == 0) {
        /* no region : add it */
        e->start = start;
        e->size = size;
    } Senão {
        /* already regions in the list: add it at the head */
        e1 = bound_new_entry();
        e1->start = e->start;
        e1->size = e->size;
        e1->next = e->next;
        e->start = start;
        e->size = size;
        e->next = e1;
    }
}

/* create a new region. It should not already exist in the region list */
Vazio __bound_new_region(Vazio *p, size_t size)
{
    size_t start, end;
    BoundEntry *page, *e, *e2;
    size_t t1_start, t1_end, i, t2_start, t2_end;

    dprintf(stderr, "%s, %s(%p, %x) start\n",
        __ARQUIVO__, __FUNCTION__, p, (SemSinal)size);

    __bound_init();

    start = (size_t)p;
    end = start + size;
    t1_start = start >> (BOUND_T2_BITS + BOUND_T3_BITS);
    t1_end = end >> (BOUND_T2_BITS + BOUND_T3_BITS);

    /* start */
    page = get_page(t1_start);
    t2_start = (start >> (BOUND_T3_BITS - BOUND_E_BITS)) & 
        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS);
    t2_end = (end >> (BOUND_T3_BITS - BOUND_E_BITS)) & 
        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS);


    e = (BoundEntry *)((Caractere *)page + t2_start);
    add_region(e, start, size);

    Se (t1_end == t1_start) {
        /* same ending page */
        e2 = (BoundEntry *)((Caractere *)page + t2_end);
        Se (e2 > e) {
            e++;
            Para(;e<e2;e++) {
                e->start = start;
                e->size = size;
            }
            add_region(e, start, size);
        }
    } Senão {
        /* mark until end of page */
        e2 = page + BOUND_T2_SIZE;
        e++;
        Para(;e<e2;e++) {
            e->start = start;
            e->size = size;
        }
        /* mark intermediate pages, Se any */
        Para(i=t1_start+1;i<t1_end;i++) {
            page = get_page(i);
            e2 = page + BOUND_T2_SIZE;
            Para(e=page;e<e2;e++) {
                e->start = start;
                e->size = size;
            }
        }
        /* last page */
        page = get_page(t1_end);
        e2 = (BoundEntry *)((Caractere *)page + t2_end);
        Para(e=page;e<e2;e++) {
            e->start = start;
            e->size = size;
        }
        add_region(e, start, size);
    }

    dprintf(stderr, "%s, %s end\n", __ARQUIVO__, __FUNCTION__);
}

/* delete a region */
Estático EmLinha Vazio delete_region(BoundEntry *e, Vazio *p, size_t empty_size)
{
    size_t addr;
    BoundEntry *e1;

    addr = (size_t)p;
    addr -= e->start;
    Se (addr <= e->size) {
        /* region found is first one */
        e1 = e->next;
        Se (e1 == NULL) {
            /* no more region: mark it empty */
            e->start = 0;
            e->size = empty_size;
        } Senão {
            /* copy next region in head */
            e->start = e1->start;
            e->size = e1->size;
            e->next = e1->next;
            bound_free_entry(e1);
        }
    } Senão {
        /* find the matching region */
        Para(;;) {
            e1 = e;
            e = e->next;
            /* region not found: Faça nothing */
            Se (e == NULL)
                Pare;
            addr = (size_t)p - e->start;
            Se (addr <= e->size) {
                /* found: remove entry */
                e1->next = e->next;
                bound_free_entry(e);
                Pare;
            }
        }
    }
}

/* WARNING: 'p' must be the starting point of the region. */
/* Retorno non zero Se Erro */
Inteiro __bound_delete_region(Vazio *p)
{
    size_t start, end, addr, size, empty_size;
    BoundEntry *page, *e, *e2;
    size_t t1_start, t1_end, t2_start, t2_end, i;

    dprintf(stderr, "%s %s() start\n", __ARQUIVO__, __FUNCTION__);

    __bound_init();

    start = (size_t)p;
    t1_start = start >> (BOUND_T2_BITS + BOUND_T3_BITS);
    t2_start = (start >> (BOUND_T3_BITS - BOUND_E_BITS)) & 
        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS);
    
    /* find region size */
    page = __bound_t1[t1_start];
    e = (BoundEntry *)((Caractere *)page + t2_start);
    addr = start - e->start;
    Se (addr > e->size)
        e = __bound_find_region(e, p);
    /* test Se invalid region */
    Se (e->size == EMPTY_SIZE || (size_t)p != e->start) 
        Retorno -1;
    /* compute the size we put in invalid regions */
    Se (e->is_invalid)
        empty_size = INVALID_SIZE;
    Senão
        empty_size = EMPTY_SIZE;
    size = e->size;
    end = start + size;

    /* now we can free each entry */
    t1_end = end >> (BOUND_T2_BITS + BOUND_T3_BITS);
    t2_end = (end >> (BOUND_T3_BITS - BOUND_E_BITS)) & 
        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS);

    delete_region(e, p, empty_size);
    Se (t1_end == t1_start) {
        /* same ending page */
        e2 = (BoundEntry *)((Caractere *)page + t2_end);
        Se (e2 > e) {
            e++;
            Para(;e<e2;e++) {
                e->start = 0;
                e->size = empty_size;
            }
            delete_region(e, p, empty_size);
        }
    } Senão {
        /* mark until end of page */
        e2 = page + BOUND_T2_SIZE;
        e++;
        Para(;e<e2;e++) {
            e->start = 0;
            e->size = empty_size;
        }
        /* mark intermediate pages, Se any */
        /* XXX: should free them */
        Para(i=t1_start+1;i<t1_end;i++) {
            page = get_page(i);
            e2 = page + BOUND_T2_SIZE;
            Para(e=page;e<e2;e++) {
                e->start = 0;
                e->size = empty_size;
            }
        }
        /* last page */
        page = get_page(t1_end);
        e2 = (BoundEntry *)((Caractere *)page + t2_end);
        Para(e=page;e<e2;e++) {
            e->start = 0;
            e->size = empty_size;
        }
        delete_region(e, p, empty_size);
    }

    dprintf(stderr, "%s %s() end\n", __ARQUIVO__, __FUNCTION__);

    Retorno 0;
}

/* Retorno the size of the region starting at p, or EMPTY_SIZE Se non
   existent region. */
Estático size_t get_region_size(Vazio *p)
{
    size_t addr = (size_t)p;
    BoundEntry *e;

    e = __bound_t1[addr >> (BOUND_T2_BITS + BOUND_T3_BITS)];
    e = (BoundEntry *)((Caractere *)e + 
                       ((addr >> (BOUND_T3_BITS - BOUND_E_BITS)) & 
                        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS)));
    addr -= e->start;
    Se (addr > e->size)
        e = __bound_find_region(e, p);
    Se (e->start != (size_t)p)
        Retorno EMPTY_SIZE;
    Retorno e->size;
}

/* patched memory functions */

/* force compiler to perform stores coded up to this point */
#Defina barrier()   Montador Volátil ("": : : "memory")

Estático Vazio install_malloc_hooks(Vazio)
{
#SeDefinido CONFIG_CTEC_MALLOC_HOOKS
    saved_malloc_hook = __malloc_hook;
    saved_free_hook = __free_hook;
    saved_realloc_hook = __realloc_hook;
    saved_memalign_hook = __memalign_hook;
    __malloc_hook = __bound_malloc;
    __free_hook = __bound_free;
    __realloc_hook = __bound_realloc;
    __memalign_hook = __bound_memalign;

    barrier();
#FimSe
}

Estático Vazio restore_malloc_hooks(Vazio)
{
#SeDefinido CONFIG_CTEC_MALLOC_HOOKS
    __malloc_hook = saved_malloc_hook;
    __free_hook = saved_free_hook;
    __realloc_hook = saved_realloc_hook;
    __memalign_hook = saved_memalign_hook;

    barrier();
#FimSe
}

Estático Vazio *libc_malloc(size_t size)
{
    Vazio *ptr;
    restore_malloc_hooks();
    ptr = malloc(size);
    install_malloc_hooks();
    Retorno ptr;
}

Estático Vazio libc_free(Vazio *ptr)
{
    restore_malloc_hooks();
    free(ptr);
    install_malloc_hooks();
}

/* XXX: we should use a malloc which ensure that it is unlikely that
   two malloc'ed data have the same address Se 'free' are made in
   between. */
Vazio *__bound_malloc(size_t size, Constante Vazio *caller)
{
    Vazio *ptr;
    
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = libc_malloc(size + 1);
    
    Se (!ptr)
        Retorno NULL;

    dprintf(stderr, "%s, %s calling __bound_new_region(%p, %x)\n",
           __ARQUIVO__, __FUNCTION__, ptr, (SemSinal)size);

    __bound_new_region(ptr, size);
    Retorno ptr;
}

Vazio *__bound_memalign(size_t size, size_t align, Constante Vazio *caller)
{
    Vazio *ptr;

    restore_malloc_hooks();

#SenãoDefinido HAVE_MEMALIGN
    Se (align > 4) {
        /* XXX: handle it ? */
        ptr = NULL;
    } Senão {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = malloc(size + 1);
    }
#Senão
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = memalign(size + 1, align);
#FimSe
    
    install_malloc_hooks();
    
    Se (!ptr)
        Retorno NULL;

    dprintf(stderr, "%s, %s calling __bound_new_region(%p, %x)\n",
           __ARQUIVO__, __FUNCTION__, ptr, (SemSinal)size);

    __bound_new_region(ptr, size);
    Retorno ptr;
}

Vazio __bound_free(Vazio *ptr, Constante Vazio *caller)
{
    Se (ptr == NULL)
        Retorno;
    Se (__bound_delete_region(ptr) != 0)
        bound_error("freeing invalid region");

    libc_free(ptr);
}

Vazio *__bound_realloc(Vazio *ptr, size_t size, Constante Vazio *caller)
{
    Vazio *ptr1;
    size_t old_size;

    Se (size == 0) {
        __bound_free(ptr, caller);
        Retorno NULL;
    } Senão {
        ptr1 = __bound_malloc(size, caller);
        Se (ptr == NULL || ptr1 == NULL)
            Retorno ptr1;
        old_size = get_region_size(ptr);
        Se (old_size == EMPTY_SIZE)
            bound_error("realloc'ing invalid pointer");
        memcpy(ptr1, ptr, old_size);
        __bound_free(ptr, caller);
        Retorno ptr1;
    }
}

#SenãoDefinido CONFIG_CTEC_MALLOC_HOOKS
Vazio *__bound_calloc(size_t nmemb, size_t size)
{
    Vazio *ptr;
    size = size * nmemb;
    ptr = __bound_malloc(size, NULL);
    Se (!ptr)
        Retorno NULL;
    memset(ptr, 0, size);
    Retorno ptr;
}
#FimSe

#Se 0
Estático Vazio bound_dump(Vazio)
{
    BoundEntry *page, *e;
    size_t i, j;

    fprintf(stderr, "region dump:\n");
    Para(i=0;i<BOUND_T1_SIZE;i++) {
        page = __bound_t1[i];
        Para(j=0;j<BOUND_T2_SIZE;j++) {
            e = page + j;
            /* Faça not print invalid or empty entries */
            Se (e->size != EMPTY_SIZE && e->start != 0) {
                fprintf(stderr, "%08x:", 
                       (i << (BOUND_T2_BITS + BOUND_T3_BITS)) + 
                       (j << BOUND_T3_BITS));
                Faça {
                    fprintf(stderr, " %08lx:%08lx", e->start, e->start + e->size);
                    e = e->next;
                } Enquanto (e != NULL);
                fprintf(stderr, "\n");
            }
        }
    }
}
#FimSe

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, Se any */
Estático Vazio __bound_check(Constante Vazio *p, size_t size)
{
    Se (size == 0)
        Retorno;
    p = __bound_ptr_add((Vazio *)p, size - 1);
    Se (p == INVALID_POINTER)
        bound_error("invalid pointer");
}

Vazio *__bound_memcpy(Vazio *dst, Constante Vazio *src, size_t size)
{
    Vazio* p;

    dprintf(stderr, "%s %s: start, dst=%p src=%p size=%x\n",
            __ARQUIVO__, __FUNCTION__, dst, src, (SemSinal)size);

    __bound_check(dst, size);
    __bound_check(src, size);
    /* check also region overlap */
    Se (src >= dst && src < dst + size)
        bound_error("overlapping regions in memcpy()");

    p = memcpy(dst, src, size);

    dprintf(stderr, "%s %s: end, p=%p\n", __ARQUIVO__, __FUNCTION__, p);
    Retorno p;
}

Vazio *__bound_memmove(Vazio *dst, Constante Vazio *src, size_t size)
{
    __bound_check(dst, size);
    __bound_check(src, size);
    Retorno memmove(dst, src, size);
}

Vazio *__bound_memset(Vazio *dst, Inteiro c, size_t size)
{
    __bound_check(dst, size);
    Retorno memset(dst, c, size);
}

/* XXX: could be optimized */
Inteiro __bound_strlen(Constante Caractere *s)
{
    Constante Caractere *p;
    size_t len;

    len = 0;
    Para(;;) {
        p = __bound_ptr_indir1((Caractere *)s, len);
        Se (p == INVALID_POINTER)
            bound_error("bad pointer in strlen()");
        Se (*p == '\0')
            Pare;
        len++;
    }
    Retorno len;
}

Caractere *__bound_strcpy(Caractere *dst, Constante Caractere *src)
{
    size_t len;
    Vazio *p;

    dprintf(stderr, "%s %s: strcpy start, dst=%p src=%p\n",
            __ARQUIVO__, __FUNCTION__, dst, src);
    len = __bound_strlen(src);
    p = __bound_memcpy(dst, src, len + 1);
    dprintf(stderr, "%s %s: strcpy end, p = %p\n",
            __ARQUIVO__, __FUNCTION__, p);
    Retorno p;
}
