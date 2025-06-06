#ifdef TARGET_DEFS_ONLY

#define EM_CTEC_TARGET EM_AARCH64

#define R_DATA_32  R_AARCH64_ABS32
#define R_DATA_PTR R_AARCH64_ABS64
#define R_JMP_SLOT R_AARCH64_JUMP_SLOT
#define R_GLOB_DAT R_AARCH64_GLOB_DAT
#define R_COPY     R_AARCH64_COPY
#define R_RELATIVE R_AARCH64_RELATIVE

#define R_NUM      R_AARCH64_NUM

#define ELF_START_ADDR 0x00400000
#define ELF_PAGE_SIZE 0x1000

#define PCRELATIVE_DLLPLT 1
#define RELOCATE_DLLPLT 1

#else /* !TARGET_DEFS_ONLY */

#include "ctec.h"

/* Returns 1 for a code relocation, 0 for a data relocation. For unknown
   relocations, returns -1. */
int code_reloc (int reloc_type)
{
    switch (reloc_type) {
        case R_AARCH64_ABS32:
        case R_AARCH64_ABS64:
	case R_AARCH64_PREL32:
        case R_AARCH64_MOVW_UABS_G0_NC:
        case R_AARCH64_MOVW_UABS_G1_NC:
        case R_AARCH64_MOVW_UABS_G2_NC:
        case R_AARCH64_MOVW_UABS_G3:
        case R_AARCH64_ADR_PREL_PG_HI21:
        case R_AARCH64_ADD_ABS_LO12_NC:
        case R_AARCH64_ADR_GOT_PAGE:
        case R_AARCH64_LD64_GOT_LO12_NC:
        case R_AARCH64_GLOB_DAT:
        case R_AARCH64_COPY:
            return 0;

        case R_AARCH64_JUMP26:
        case R_AARCH64_CALL26:
        case R_AARCH64_JUMP_SLOT:
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
	case R_AARCH64_PREL32:
        case R_AARCH64_MOVW_UABS_G0_NC:
        case R_AARCH64_MOVW_UABS_G1_NC:
        case R_AARCH64_MOVW_UABS_G2_NC:
        case R_AARCH64_MOVW_UABS_G3:
        case R_AARCH64_ADR_PREL_PG_HI21:
        case R_AARCH64_ADD_ABS_LO12_NC:
        case R_AARCH64_GLOB_DAT:
        case R_AARCH64_JUMP_SLOT:
        case R_AARCH64_COPY:
            return NO_GOTPLT_ENTRY;

        case R_AARCH64_ABS32:
        case R_AARCH64_ABS64:
        case R_AARCH64_JUMP26:
        case R_AARCH64_CALL26:
            return AUTO_GOTPLT_ENTRY;

        case R_AARCH64_ADR_GOT_PAGE:
        case R_AARCH64_LD64_GOT_LO12_NC:
            return ALWAYS_GOTPLT_ENTRY;
    }

    ctec_error ("Unknown relocation type: %d", reloc_type);
    return -1;
}

ST_FUNC unsigned create_plt_entry(CTECState *s1, unsigned got_offset, struct sym_attr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    unsigned plt_offset;

    if (s1->output_type == CTEC_OUTPUT_DLL)
        ctec_error("DLLs unimplemented!");

    if (plt->data_offset == 0) {
        section_ptr_add(plt, 32);
    }
    plt_offset = plt->data_offset;

    p = section_ptr_add(plt, 16);
    write32le(p, got_offset);
    write32le(p + 4, (uint64_t) got_offset >> 32);
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
        uint64_t plt = s1->plt->sh_addr;
        uint64_t got = s1->got->sh_addr;
        uint64_t off = (got >> 12) - (plt >> 12);
        if ((off + ((uint32_t)1 << 20)) >> 21)
            ctec_error("Failed relocating PLT (off=0x%lx, got=0x%lx, plt=0x%lx)", off, got, plt);
        write32le(p, 0xa9bf7bf0); // stp x16,x30,[sp,#-16]!
        write32le(p + 4, (0x90000010 | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
        write32le(p + 8, (0xf9400211 | // ldr x17,[x16,#...]
			  (got & 0xff8) << 7));
        write32le(p + 12, (0x91000210 | // add x16,x16,#...
			   (got & 0xfff) << 10));
        write32le(p + 16, 0xd61f0220); // br x17
        write32le(p + 20, 0xd503201f); // nop
        write32le(p + 24, 0xd503201f); // nop
        write32le(p + 28, 0xd503201f); // nop
        p += 32;
        while (p < p_end) {
            uint64_t pc = plt + (p - s1->plt->data);
            uint64_t addr = got + read64le(p);
            uint64_t off = (addr >> 12) - (pc >> 12);
            if ((off + ((uint32_t)1 << 20)) >> 21)
                ctec_error("Failed relocating PLT (off=0x%lx, addr=0x%lx, pc=0x%lx)", off, addr, pc);
            write32le(p, (0x90000010 | // adrp x16,...
			  (off & 0x1ffffc) << 3 | (off & 3) << 29));
            write32le(p + 4, (0xf9400211 | // ldr x17,[x16,#...]
			      (addr & 0xff8) << 7));
            write32le(p + 8, (0x91000210 | // add x16,x16,#...
			      (addr & 0xfff) << 10));
            write32le(p + 12, 0xd61f0220); // br x17
            p += 16;
        }
    }
}

void relocate_init(Section *sr) {}

void relocate(CTECState *s1, ElfW_Rel *rel, int type, unsigned char *ptr, addr_t addr, addr_t val)
{
    int sym_index = ELFW(R_SYM)(rel->r_info);
#ifdef DEBUG_RELOC
    ElfW(Sym) *sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
#endif

    switch(type) {
        case R_AARCH64_ABS64:
            write64le(ptr, val);
            return;
        case R_AARCH64_ABS32:
            write32le(ptr, val);
            return;
	case R_AARCH64_PREL32:
	    write32le(ptr, val - addr);
	    return;
        case R_AARCH64_MOVW_UABS_G0_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val & 0xffff) << 5));
            return;
        case R_AARCH64_MOVW_UABS_G1_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 16 & 0xffff) << 5));
            return;
        case R_AARCH64_MOVW_UABS_G2_NC:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 32 & 0xffff) << 5));
            return;
        case R_AARCH64_MOVW_UABS_G3:
            write32le(ptr, ((read32le(ptr) & 0xffe0001f) |
                            (val >> 48 & 0xffff) << 5));
            return;
        case R_AARCH64_ADR_PREL_PG_HI21: {
            uint64_t off = (val >> 12) - (addr >> 12);
            if ((off + ((uint64_t)1 << 20)) >> 21)
                ctec_error("R_AARCH64_ADR_PREL_PG_HI21 relocation failed");
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            return;
        }
        case R_AARCH64_ADD_ABS_LO12_NC:
            write32le(ptr, ((read32le(ptr) & 0xffc003ff) |
                            (val & 0xfff) << 10));
            return;
        case R_AARCH64_JUMP26:
        case R_AARCH64_CALL26:
#ifdef DEBUG_RELOC
	    printf ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr, val,
		    (char *) symtab_section->link->data + sym->st_name);
#endif
            if (((val - addr) + ((uint64_t)1 << 27)) & ~(uint64_t)0xffffffc)
                ctec_error("R_AARCH64_(JUMP|CALL)26 relocation failed"
                          " (val=%lx, addr=%lx)", val, addr);
            write32le(ptr, (0x14000000 |
                            (uint32_t)(type == R_AARCH64_CALL26) << 31 |
                            ((val - addr) >> 2 & 0x3ffffff)));
            return;
        case R_AARCH64_ADR_GOT_PAGE: {
            uint64_t off =
                (((s1->got->sh_addr +
                   s1->sym_attrs[sym_index].got_offset) >> 12) - (addr >> 12));
            if ((off + ((uint64_t)1 << 20)) >> 21)
                ctec_error("R_AARCH64_ADR_GOT_PAGE relocation failed");
            write32le(ptr, ((read32le(ptr) & 0x9f00001f) |
                            (off & 0x1ffffc) << 3 | (off & 3) << 29));
            return;
        }
        case R_AARCH64_LD64_GOT_LO12_NC:
            write32le(ptr,
                      ((read32le(ptr) & 0xfff803ff) |
                       ((s1->got->sh_addr +
                         s1->sym_attrs[sym_index].got_offset) & 0xff8) << 7));
            return;
        case R_AARCH64_COPY:
            return;
        case R_AARCH64_GLOB_DAT:
        case R_AARCH64_JUMP_SLOT:
            /* They don't need addend */
#ifdef DEBUG_RELOC
	    printf ("reloc %d @ 0x%lx: val=0x%lx name=%s\n", type, addr,
		    val - rel->r_addend,
		    (char *) symtab_section->link->data + sym->st_name);
#endif
            write64le(ptr, val - rel->r_addend);
            return;
        case R_AARCH64_RELATIVE:
#ifdef CTEC_TARGET_PE
            add32le(ptr, val - s1->pe_imagebase);
#endif
            /* do nothing */
            return;
        default:
            fprintf(stderr, "FIXME: handle reloc type %x at %x [%p] to %x\n",
                    type, (unsigned)addr, ptr, (unsigned)val);
            return;
    }
}

#endif /* !TARGET_DEFS_ONLY */
