/* va_list.c - tinycc support Para va_list on X86_64 */

#Se Definido __x86_64__

/* Avoid Inclua files, they may not be available when cross compiling */
Externo Vazio *memset(Vazio *s, Inteiro c, __SIZE_TYPE__ n);
Externo Vazio abort(Vazio);

/* This should be in sync with our Inclua/stdarg.h */
Enumeração __va_arg_type {
    __va_gen_reg, __va_float_reg, __va_stack
};

/* GCC compatible definition of va_list. */
Tipo Estrutura {
    SemSinal Inteiro gp_offset;
    SemSinal Inteiro fp_offset;
    União {
        SemSinal Inteiro overflow_offset;
        Caractere *overflow_arg_area;
    };
    Caractere *reg_save_area;
} __va_list_struct;

Vazio __va_start(__va_list_struct *ap, Vazio *fp)
{
    memset(ap, 0, TamanhoDe(__va_list_struct));
    *ap = *(__va_list_struct *)((Caractere *)fp - 16);
    ap->overflow_arg_area = (Caractere *)fp + ap->overflow_offset;
    ap->reg_save_area = (Caractere *)fp - 176 - 16;
}

Vazio *__va_arg(__va_list_struct *ap,
               Enumeração __va_arg_type arg_type,
               Inteiro size, Inteiro align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    Troque (arg_type) {
    Caso __va_gen_reg:
        Se (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            Retorno ap->reg_save_area + ap->gp_offset - size;
        }
        VáPara use_overflow_area;

    Caso __va_float_reg:
        Se (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            Retorno ap->reg_save_area + ap->fp_offset - 16;
        }
        size = 8;
        VáPara use_overflow_area;

    Caso __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (Caractere*)((Longo Longo)(ap->overflow_arg_area + align - 1) & -align);
        Retorno ap->overflow_arg_area - size;

    Padrão: /* should never happen */
        abort();
    }
}
#FimSe
