#ifdef TARGET_DEFS_ONLY

#define EM_CTEC_TARGET EM_X86_64

/* relocation type for 32 bit data relocation */
#define R_DATA_32   R_X86_64_32S
#define R_DATA_PTR  R_X86_64_64
#define R_JMP_SLOT  R_X86_64_JUMP_SLOT
#define R_GLOB_DAT  R_X86_64_GLOB_DAT
#define R_COPY      R_X86_64_COPY
#define R_RELATIVE  R_X86_64_RELATIVE

#define R_NUM       R_X86_64_NUM

#define ELF_START_ADDR 0x400000
#define ELF_PAGE_SIZE  0x200000

#define PCRELATIVE_DLLPLT 1
#define RELOCATE_DLLPLT 1

#else /* !TARGET_DEFS_ONLY */

#include "ctec.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
int code_reloc (int reloc_type)
{
    switch (reloc_type) {
        case R_X86_64_32:
        case R_X86_64_32S:
        case R_X86_64_64:
        case R_X86_64_GOTPC32:
        case R_X86_64_GOTPC64:
        case R_X86_64_GOTPCREL:
        case R_X86_64_GOTPCRELX:
        case R_X86_64_REX_GOTPCRELX:
        case R_X86_64_GOTTPOFF:
        case R_X86_64_GOT32:
        case R_X86_64_GOT64:
        case R_X86_64_GLOB_DAT:
        case R_X86_64_COPY:
        case R_X86_64_RELATIVE:
        case R_X86_64_GOTOFF64:
            return 0;

        case R_X86_64_PC32:
        case R_X86_64_PC64:
        case R_X86_64_PLT32:
        case R_X86_64_PLTOFF64:
        case R_X86_64_JUMP_SLOT:
            return 1;
    }

    ctec_error ("Unknown relocation type: %d", reloc_type);
    return -1;
}

/* Returns an enumerator to describe whether and when the relocation needs a
   GOT and/or PLT entry to be created. See ctec.h for a description of the
   different values. */
int gotplt_entry_type (int reloc_type)
{
    switch (reloc_type) {
        case R_X86_64_GLOB_DAT:
        case R_X86_64_JUMP_SLOT:
        case R_X86_64_COPY:
        case R_X86_64_RELATIVE:
            return NO_GOTPLT_ENTRY;

	/* The following relocs wouldn't normally need GOT or PLT
	   slots, but we need them for simplicity in the link
	   editor part.  See our caller for comments.  */
        case R_X86_64_32:
        case R_X86_64_32S:
        case R_X86_64_64:
        case R_X86_64_PC32:
        case R_X86_64_PC64:
            return AUTO_GOTPLT_ENTRY;

        case R_X86_64_GOTTPOFF:
            return BUILD_GOT_ONLY;

        case R_X86_64_GOT32:
        case R_X86_64_GOT64:
        case R_X86_64_GOTPC32:
        case R_X86_64_GOTPC64:
        case R_X86_64_GOTOFF64:
        case R_X86_64_GOTPCREL:
        case R_X86_64_GOTPCRELX:
        case R_X86_64_REX_GOTPCRELX:
        case R_X86_64_PLT32:
        case R_X86_64_PLTOFF64:
            return ALWAYS_GOTPLT_ENTRY;
    }

    ctec_error ("Unknown relocation type: %d", reloc_type);
    return -1;
}

ST_FUNC unsigned create_plt_entry(CTECState *s1, unsigned got_offset, struct sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    int modrm;
    unsigned plt_offset, relofs;

    modrm = 0x25;

    /* empty PLT: create PLT0 entry that pushes the library identifier
       (GOT + PTR_SIZE) and jumps to ld.so resolution routine
       (GOT + 2 * PTR_SIZE) */
    if (plt->data_offset == 0) {
        p = section_ptr_add(plt, 16);
        p[0] = 0xff; /* pushl got + PTR_SIZE */
        p[1] = modrm + 0x10;
        write32le(p + 2, PTR_SIZE);
        p[6] = 0xff; /* jmp *(got + PTR_SIZE * 2) */
        p[7] = modrm;
        write32le(p + 8, PTR_SIZE * 2);
    }
    plt_offset = plt->data_offset;

    /* The PLT slot refers to the relocation entry it needs via offset.
       The reloc entry is created below, so its offset is the current
       data_offset */
    relofs = s1->got->reloc ? s1->got->reloc->data_offset : 0;

    /* Jump to GOT entry where ld.so initially put the address of ip + 4 */
    p = section_ptr_add(plt, 16);
    p[0] = 0xff; /* jmp *(got + x) */
    p[1] = modrm;
    write32le(p + 2, got_offset);
    p[6] = 0x68; /* push $xxx */
    /* On x86-64, the relocation is referred to by _index_ */
    write32le(p + 7, relofs / sizeof (ElfW_Rel));
    p[11] = 0xe9; /* jmp plt_start */
    write32le(p + 12, -(plt->data_offset));
    return plt_offset;
}

/* relocate the PLT: compute addresses and offsets in the PLT now that final
   address for PLT and GOT are known (see fill_program_header) */
ST_FUNC void relocate_plt(CTECState *s1)
{
    uint8_t *p, *p_end;

    if (!s1->plt)
      return;

    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;

    if (p < p_end) {
        int x = s1->got->sh_addr - s1->plt->sh_addr - 6;
        add32le(p + 2, x);
        add32le(p + 8, x - 6);
        p += 16;
        while (p < p_end) {
            add32le(p + 2, x + s1->plt->data - p);
            p += 16;
        }
    }
}

static ElfW_Rel *qrel; /* ptr to next reloc entry reused */

void relocate_init(Section *sr)
{
    qrel = (ElfW_Rel *) sr->data;
}

void relocate(CTECState *s1, ElfW_Rel *rel, int type, unsigned char *ptr, addr_t addr, addr_t val)
{
    int sym_index, esym_index;

    sym_index = ELFW(R_SYM)(rel->r_info);

    switch (type) {
        case R_X86_64_64:
            if (s1->output_type == CTEC_OUTPUT_DLL) {
                esym_index = s1->sym_attrs[sym_index].dyn_index;
                qrel->r_offset = rel->r_offset;
                if (esym_index) {
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_64);
                    qrel->r_addend = rel->r_addend;
                    qrel++;
                    break;
                } else {
                    qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                    qrel->r_addend = read64le(ptr) + val;
                    qrel++;
                }
            }
            add64le(ptr, val);
            break;
        case R_X86_64_32:
        case R_X86_64_32S:
            if (s1->output_type == CTEC_OUTPUT_DLL) {
                /* XXX: this logic may depend on CTEC's codegen
                   now CTEC uses R_X86_64_32 even for a 64bit pointer */
                qrel->r_info = ELFW(R_INFO)(0, R_X86_64_RELATIVE);
                /* Use sign extension! */
                qrel->r_addend = (int)read32le(ptr) + val;
                qrel++;
            }
            add32le(ptr, val);
            break;

        case R_X86_64_PC32:
            if (s1->output_type == CTEC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = s1->sym_attrs[sym_index].dyn_index;
                if (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC32);
                    /* Use sign extension! */
                    qrel->r_addend = (int)read32le(ptr) + rel->r_addend;
                    qrel++;
                    break;
                }
            }
            goto plt32pc32;

        case R_X86_64_PLT32:
            /* fallthrough: val already holds the PLT slot address */

        plt32pc32:
        {
            long long diff;
            diff = (long long)val - addr;
            if (diff < -2147483648LL || diff > 2147483647LL) {
                ctec_error("internal error: relocation failed");
            }
            add32le(ptr, diff);
        }
            break;

        case R_X86_64_PLTOFF64:
            add64le(ptr, val - s1->got->sh_addr + rel->r_addend);
            break;

        case R_X86_64_PC64:
            if (s1->output_type == CTEC_OUTPUT_DLL) {
                /* DLL relocation */
                esym_index = s1->sym_attrs[sym_index].dyn_index;
                if (esym_index) {
                    qrel->r_offset = rel->r_offset;
                    qrel->r_info = ELFW(R_INFO)(esym_index, R_X86_64_PC64);
                    qrel->r_addend = read64le(ptr) + rel->r_addend;
                    qrel++;
                    break;
                }
            }
            add64le(ptr, val - addr);
            break;

        case R_X86_64_GLOB_DAT:
        case R_X86_64_JUMP_SLOT:
            /* They don't need addend */
            write64le(ptr, val - rel->r_addend);
            break;
        case R_X86_64_GOTPCREL:
        case R_X86_64_GOTPCRELX:
        case R_X86_64_REX_GOTPCRELX:
            add32le(ptr, s1->got->sh_addr - addr +
                         s1->sym_attrs[sym_index].got_offset - 4);
            break;
        case R_X86_64_GOTPC32:
            add32le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            break;
        case R_X86_64_GOTPC64:
            add64le(ptr, s1->got->sh_addr - addr + rel->r_addend);
            break;
        case R_X86_64_GOTTPOFF:
            add32le(ptr, val - s1->got->sh_addr);
            break;
        case R_X86_64_GOT32:
            /* we load the got offset */
            add32le(ptr, s1->sym_attrs[sym_index].got_offset);
            break;
        case R_X86_64_GOT64:
            /* we load the got offset */
            add64le(ptr, s1->sym_attrs[sym_index].got_offset);
            break;
        case R_X86_64_GOTOFF64:
            add64le(ptr, val - s1->got->sh_addr);
            break;
        case R_X86_64_RELATIVE:
#ifdef CTEC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            break;
    }
}

#endif /* !TARGET_DEFS_ONLY */
