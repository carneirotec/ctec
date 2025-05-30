/* keywords */
     DEF(TOK_INT, "Inteiro")
     DEF(TOK_VOID, "Vazio")
     DEF(TOK_CHAR, "Caractere")
     DEF(TOK_IF, "Se")
     DEF(TOK_ELSE, "Senão")
     DEF(TOK_WHILE, "Enquanto")
     DEF(TOK_BREAK, "Pare")
     DEF(TOK_RETURN, "Retorno")
     DEF(TOK_FOR, "Para")
     DEF(TOK_EXTERN, "Externo")
     DEF(TOK_STATIC, "Estático")
     DEF(TOK_UNSIGNED, "SemSinal")
     DEF(TOK_GOTO, "VáPara")
     DEF(TOK_DO, "Faça")
     DEF(TOK_CONTINUE, "Continue")
     DEF(TOK_SWITCH, "Troque")
     DEF(TOK_CASE, "Caso")

     DEF(TOK_CONST1, "Constante")
     DEF(TOK_CONST2, "__const") /* gcc keyword */
     DEF(TOK_CONST3, "__const__") /* gcc keyword */
     DEF(TOK_VOLATILE1, "Volátil")
     DEF(TOK_VOLATILE2, "__volatile") /* gcc keyword */
     DEF(TOK_VOLATILE3, "__volatile__") /* gcc keyword */
     DEF(TOK_LONG, "Longo")
     DEF(TOK_REGISTER, "Registrador")
     DEF(TOK_SIGNED1, "ComSinal")
     DEF(TOK_SIGNED2, "__signed") /* gcc keyword */
     DEF(TOK_SIGNED3, "__signed__") /* gcc keyword */
     DEF(TOK_AUTO, "Automático")
     DEF(TOK_INLINE1, "EmLinha")
     DEF(TOK_INLINE2, "__inline") /* gcc keyword */
     DEF(TOK_INLINE3, "__inline__") /* gcc keyword */
     DEF(TOK_RESTRICT1, "Restrito")
     DEF(TOK_RESTRICT2, "__restrict")
     DEF(TOK_RESTRICT3, "__restrict__")
     DEF(TOK_EXTENSION, "__extension__") /* gcc keyword */

     DEF(TOK_GENERIC, "Genérico")

     DEF(TOK_FLOAT, "Real")
     DEF(TOK_DOUBLE, "Duplo")
     DEF(TOK_BOOL, "Lógico")
     DEF(TOK_SHORT, "Curto")
     DEF(TOK_STRUCT, "Estrutura")
     DEF(TOK_UNION, "União")
     DEF(TOK_TYPEDEF, "Tipo")
     DEF(TOK_DEFAULT, "Padrão")
     DEF(TOK_ENUM, "Enumeração")
     DEF(TOK_SIZEOF, "TamanhoDe")
     DEF(TOK_ATTRIBUTE1, "__attribute")
     DEF(TOK_ATTRIBUTE2, "__attribute__")
     DEF(TOK_ALIGNOF1, "__alignof")
     DEF(TOK_ALIGNOF2, "__alignof__")
     DEF(TOK_TYPEOF1, "TipoDe")
     DEF(TOK_TYPEOF2, "__typeof")
     DEF(TOK_TYPEOF3, "__typeof__")
     DEF(TOK_LABEL, "__label__")
     DEF(TOK_ASM1, "Montador")
     DEF(TOK_ASM2, "__asm")
     DEF(TOK_ASM3, "__asm__")

#ifdef CTEC_TARGET_ARM64
     DEF(TOK_UINT128, "__uint128_t")
#endif

/*********************************************************************/
/* the following are not keywords. They are included to ease parsing */
/* preprocessor only */
     DEF(TOK_DEFINE, "Defina")
     DEF(TOK_INCLUDE, "Inclua")
     DEF(TOK_INCLUDE_NEXT, "IncluaPróximo")
     DEF(TOK_IFDEF, "SeDefinido")
     DEF(TOK_IFNDEF, "SenãoDefinido")
     DEF(TOK_ELIF, "SenãoSe")
     DEF(TOK_ENDIF, "FimSe")
     DEF(TOK_DEFINED, "Definido")
     DEF(TOK_UNDEF, "Indefinido")
     DEF(TOK_ERROR, "Erro")
     DEF(TOK_WARNING, "Aviso")
     DEF(TOK_LINE, "Linha")
     DEF(TOK_PRAGMA, "Diretiva")
     DEF(TOK___LINE__, "__LINHA__")
     DEF(TOK___FILE__, "__ARQUIVO__")
     DEF(TOK___DATE__, "__DATA__")
     DEF(TOK___TIME__, "__HORA__")
     DEF(TOK___FUNCTION__, "__FUNCTION__")
     DEF(TOK___VA_ARGS__, "__ARG_VARIÁDICOS__")
     DEF(TOK___COUNTER__, "__CONTADOR__")

/* special identifiers */
     DEF(TOK___FUNC__, "__func__")

/* special floating point values */
     DEF(TOK___NAN__, "__nan__")
     DEF(TOK___SNAN__, "__snan__")
     DEF(TOK___INF__, "__inf__")

/* attribute identifiers */
/* XXX: handle all tokens generically since speed is not critical */
     DEF(TOK_SECTION1, "section")
     DEF(TOK_SECTION2, "__section__")
     DEF(TOK_ALIGNED1, "aligned")
     DEF(TOK_ALIGNED2, "__aligned__")
     DEF(TOK_PACKED1, "packed")
     DEF(TOK_PACKED2, "__packed__")
     DEF(TOK_WEAK1, "weak")
     DEF(TOK_WEAK2, "__weak__")
     DEF(TOK_ALIAS1, "alias")
     DEF(TOK_ALIAS2, "__alias__")
     DEF(TOK_UNUSED1, "unused")
     DEF(TOK_UNUSED2, "__unused__")
     DEF(TOK_CDECL1, "cdecl")
     DEF(TOK_CDECL2, "__cdecl")
     DEF(TOK_CDECL3, "__cdecl__")
     DEF(TOK_STDCALL1, "stdcall")
     DEF(TOK_STDCALL2, "__stdcall")
     DEF(TOK_STDCALL3, "__stdcall__")
     DEF(TOK_FASTCALL1, "fastcall")
     DEF(TOK_FASTCALL2, "__fastcall")
     DEF(TOK_FASTCALL3, "__fastcall__")
     DEF(TOK_REGPARM1, "regparm")
     DEF(TOK_REGPARM2, "__regparm__")

     DEF(TOK_MODE, "__mode__")
     DEF(TOK_MODE_QI, "__QI__")
     DEF(TOK_MODE_DI, "__DI__")
     DEF(TOK_MODE_HI, "__HI__")
     DEF(TOK_MODE_SI, "__SI__")
     DEF(TOK_MODE_word, "__word__")

     DEF(TOK_DLLEXPORT, "dllexport")
     DEF(TOK_DLLIMPORT, "dllimport")
     DEF(TOK_NORETURN1, "noreturn")
     DEF(TOK_NORETURN2, "__noreturn__")
     DEF(TOK_VISIBILITY1, "visibility")
     DEF(TOK_VISIBILITY2, "__visibility__")

     DEF(TOK_builtin_types_compatible_p, "__builtin_types_compatible_p")
     DEF(TOK_builtin_choose_expr, "__builtin_choose_expr")
     DEF(TOK_builtin_constant_p, "__builtin_constant_p")
     DEF(TOK_builtin_frame_address, "__builtin_frame_address")
     DEF(TOK_builtin_return_address, "__builtin_return_address")
     DEF(TOK_builtin_expect, "__builtin_expect")
     /*DEF(TOK_builtin_va_list, "__builtin_va_list")*/
#if defined CTEC_TARGET_PE && defined CTEC_TARGET_X86_64
     DEF(TOK_builtin_va_start, "__builtin_va_start")
#elif defined CTEC_TARGET_X86_64
     DEF(TOK_builtin_va_arg_types, "__builtin_va_arg_types")
#elif defined CTEC_TARGET_ARM64
     DEF(TOK___va_start, "__va_start")
     DEF(TOK___va_arg, "__va_arg")
#endif

/* pragma */
     DEF(TOK_pack, "pack")
#if !defined(CTEC_TARGET_I386) && !defined(CTEC_TARGET_X86_64)
     /* already defined for assembler */
     DEF(TOK_ASM_push, "push")
     DEF(TOK_ASM_pop, "pop")
#endif
     DEF(TOK_comment, "comment")
     DEF(TOK_lib, "lib")
     DEF(TOK_push_macro, "push_macro")
     DEF(TOK_pop_macro, "pop_macro")
     DEF(TOK_once, "once")
     DEF(TOK_option, "option")

/* builtin functions or variables */
#ifndef CTEC_ARM_EABI
     DEF(TOK_memcpy, "memcpy")
     DEF(TOK_memmove, "memmove")
     DEF(TOK_memset, "memset")
     DEF(TOK___divdi3, "__divdi3")
     DEF(TOK___moddi3, "__moddi3")
     DEF(TOK___udivdi3, "__udivdi3")
     DEF(TOK___umoddi3, "__umoddi3")
     DEF(TOK___ashrdi3, "__ashrdi3")
     DEF(TOK___lshrdi3, "__lshrdi3")
     DEF(TOK___ashldi3, "__ashldi3")
     DEF(TOK___floatundisf, "__floatundisf")
     DEF(TOK___floatundidf, "__floatundidf")
# ifndef CTEC_ARM_VFP
     DEF(TOK___floatundixf, "__floatundixf")
     DEF(TOK___fixunsxfdi, "__fixunsxfdi")
# endif
     DEF(TOK___fixunssfdi, "__fixunssfdi")
     DEF(TOK___fixunsdfdi, "__fixunsdfdi")
#endif

#if defined CTEC_TARGET_ARM
# ifdef CTEC_ARM_EABI
     DEF(TOK_memcpy, "__aeabi_memcpy")
     DEF(TOK_memcpy4, "__aeabi_memcpy4")
     DEF(TOK_memcpy8, "__aeabi_memcpy8")
     DEF(TOK_memmove, "__aeabi_memmove")
     DEF(TOK_memset, "__aeabi_memset")
     DEF(TOK___aeabi_ldivmod, "__aeabi_ldivmod")
     DEF(TOK___aeabi_uldivmod, "__aeabi_uldivmod")
     DEF(TOK___aeabi_idivmod, "__aeabi_idivmod")
     DEF(TOK___aeabi_uidivmod, "__aeabi_uidivmod")
     DEF(TOK___divsi3, "__aeabi_idiv")
     DEF(TOK___udivsi3, "__aeabi_uidiv")
     DEF(TOK___floatdisf, "__aeabi_l2f")
     DEF(TOK___floatdidf, "__aeabi_l2d")
     DEF(TOK___fixsfdi, "__aeabi_f2lz")
     DEF(TOK___fixdfdi, "__aeabi_d2lz")
     DEF(TOK___ashrdi3, "__aeabi_lasr")
     DEF(TOK___lshrdi3, "__aeabi_llsr")
     DEF(TOK___ashldi3, "__aeabi_llsl")
     DEF(TOK___floatundisf, "__aeabi_ul2f")
     DEF(TOK___floatundidf, "__aeabi_ul2d")
     DEF(TOK___fixunssfdi, "__aeabi_f2ulz")
     DEF(TOK___fixunsdfdi, "__aeabi_d2ulz")
# else
     DEF(TOK___modsi3, "__modsi3")
     DEF(TOK___umodsi3, "__umodsi3")
     DEF(TOK___divsi3, "__divsi3")
     DEF(TOK___udivsi3, "__udivsi3")
     DEF(TOK___floatdisf, "__floatdisf")
     DEF(TOK___floatdidf, "__floatdidf")
#  ifndef CTEC_ARM_VFP
     DEF(TOK___floatdixf, "__floatdixf")
     DEF(TOK___fixunssfsi, "__fixunssfsi")
     DEF(TOK___fixunsdfsi, "__fixunsdfsi")
     DEF(TOK___fixunsxfsi, "__fixunsxfsi")
     DEF(TOK___fixxfdi, "__fixxfdi")
#  endif
     DEF(TOK___fixsfdi, "__fixsfdi")
     DEF(TOK___fixdfdi, "__fixdfdi")
# endif
#endif

#if defined CTEC_TARGET_C67
     DEF(TOK__divi, "_divi")
     DEF(TOK__divu, "_divu")
     DEF(TOK__divf, "_divf")
     DEF(TOK__divd, "_divd")
     DEF(TOK__remi, "_remi")
     DEF(TOK__remu, "_remu")
#endif

#if defined CTEC_TARGET_I386
     DEF(TOK___fixsfdi, "__fixsfdi")
     DEF(TOK___fixdfdi, "__fixdfdi")
     DEF(TOK___fixxfdi, "__fixxfdi")
#endif

#if defined CTEC_TARGET_I386 || defined CTEC_TARGET_X86_64
     DEF(TOK_alloca, "alloca")
#endif

#if defined CTEC_TARGET_PE
     DEF(TOK___chkstk, "__chkstk")
#endif
#ifdef CTEC_TARGET_ARM64
     DEF(TOK___arm64_clear_cache, "__arm64_clear_cache")
     DEF(TOK___addtf3, "__addtf3")
     DEF(TOK___subtf3, "__subtf3")
     DEF(TOK___multf3, "__multf3")
     DEF(TOK___divtf3, "__divtf3")
     DEF(TOK___extendsftf2, "__extendsftf2")
     DEF(TOK___extenddftf2, "__extenddftf2")
     DEF(TOK___trunctfsf2, "__trunctfsf2")
     DEF(TOK___trunctfdf2, "__trunctfdf2")
     DEF(TOK___fixtfsi, "__fixtfsi")
     DEF(TOK___fixtfdi, "__fixtfdi")
     DEF(TOK___fixunstfsi, "__fixunstfsi")
     DEF(TOK___fixunstfdi, "__fixunstfdi")
     DEF(TOK___floatsitf, "__floatsitf")
     DEF(TOK___floatditf, "__floatditf")
     DEF(TOK___floatunsitf, "__floatunsitf")
     DEF(TOK___floatunditf, "__floatunditf")
     DEF(TOK___eqtf2, "__eqtf2")
     DEF(TOK___netf2, "__netf2")
     DEF(TOK___lttf2, "__lttf2")
     DEF(TOK___letf2, "__letf2")
     DEF(TOK___gttf2, "__gttf2")
     DEF(TOK___getf2, "__getf2")
#endif

/* bound checking symbols */
#ifdef CONFIG_CTEC_BCHECK
     DEF(TOK___bound_ptr_add, "__bound_ptr_add")
     DEF(TOK___bound_ptr_indir1, "__bound_ptr_indir1")
     DEF(TOK___bound_ptr_indir2, "__bound_ptr_indir2")
     DEF(TOK___bound_ptr_indir4, "__bound_ptr_indir4")
     DEF(TOK___bound_ptr_indir8, "__bound_ptr_indir8")
     DEF(TOK___bound_ptr_indir12, "__bound_ptr_indir12")
     DEF(TOK___bound_ptr_indir16, "__bound_ptr_indir16")
     DEF(TOK___bound_main_arg, "__bound_main_arg")
     DEF(TOK___bound_local_new, "__bound_local_new")
     DEF(TOK___bound_local_delete, "__bound_local_delete")
# ifdef CTEC_TARGET_PE
     DEF(TOK_malloc, "malloc")
     DEF(TOK_free, "free")
     DEF(TOK_realloc, "realloc")
     DEF(TOK_memalign, "memalign")
     DEF(TOK_calloc, "calloc")
# endif
     DEF(TOK_strlen, "strlen")
     DEF(TOK_strcpy, "strcpy")
#endif

/* Tiny Assembler */
 DEF_ASMDIR(byte)              /* must be first directive */
 DEF_ASMDIR(word)
 DEF_ASMDIR(align)
 DEF_ASMDIR(balign)
 DEF_ASMDIR(p2align)
 DEF_ASMDIR(set)
 DEF_ASMDIR(skip)
 DEF_ASMDIR(space)
 DEF_ASMDIR(string)
 DEF_ASMDIR(asciz)
 DEF_ASMDIR(ascii)
 DEF_ASMDIR(file)
 DEF_ASMDIR(globl)
 DEF_ASMDIR(global)
 DEF_ASMDIR(weak)
 DEF_ASMDIR(hidden)
 DEF_ASMDIR(ident)
 DEF_ASMDIR(size)
 DEF_ASMDIR(type)
 DEF_ASMDIR(text)
 DEF_ASMDIR(data)
 DEF_ASMDIR(bss)
 DEF_ASMDIR(previous)
 DEF_ASMDIR(pushsection)
 DEF_ASMDIR(popsection)
 DEF_ASMDIR(fill)
 DEF_ASMDIR(rept)
 DEF_ASMDIR(endr)
 DEF_ASMDIR(org)
 DEF_ASMDIR(quad)
#if defined(CTEC_TARGET_I386)
 DEF_ASMDIR(code16)
 DEF_ASMDIR(code32)
#elif defined(CTEC_TARGET_X86_64)
 DEF_ASMDIR(code64)
#endif
 DEF_ASMDIR(short)
 DEF_ASMDIR(long)
 DEF_ASMDIR(int)
 DEF_ASMDIR(section)            /* must be last directive */

#if defined CTEC_TARGET_I386 || defined CTEC_TARGET_X86_64
#include "i386-tok.h"
#endif
