#include "readelf.h"

static char *get_ftype(unsigned int e_type)
{
	static char buf[32];

	switch (e_type)
	{
	case ET_NONE:		return ("NONE (None)");
	case ET_REL:		return ("REL (Relocatable file)");
	case ET_EXEC:		return ("EXEC (Executable file)");
	case ET_DYN:		return ("DYN (Shared object file)");
	case ET_CORE:		return ("CORE (Core file)");
	default:
		if ((e_type >= ET_LOPROC) && (e_type <= ET_HIPROC))
			snprintf(buf, sizeof(buf), "Processor Specific: (%x)", e_type);
		else if ((e_type >= ET_LOOS) && (e_type <= ET_HIOS))
			snprintf(buf, sizeof(buf), "OS Specific: (%x)", e_type);
		else
			snprintf(buf, sizeof(buf), "<unknown>: %x", e_type);
		return (buf);
	}
}

static char *get_segment_type(uint32_t p_type)
{
	static char buf[16];

	switch (p_type)
	{
	case PT_NULL:		return "NULL";
	case PT_LOAD:		return "LOAD";
	case PT_DYNAMIC:	return "DYNAMIC";
	case PT_INTERP:		return "INTERP";
	case PT_NOTE:		return "NOTE";
	case PT_SHLIB:		return "SHLIB";
	case PT_PHDR:		return "PHDR";
	case PT_TLS:		return "TLS";
	case PT_GNU_EH_FRAME:	return "GNU_EH_FRAME";
	case PT_GNU_STACK:	return "GNU_STACK";
	case PT_GNU_RELRO:	return "GNU_RELRO";
	default:
		if (p_type >= PT_LOOS)
			sprintf(buf, "LOOS+%x", p_type - PT_LOOS);
		return (buf);
	}
}

static char *get_pflags(uint32_t p_flags)
{
	static char buf[3];

	buf[0] = (p_flags & PF_R) ? 'R' : ' ';
	buf[1] = (p_flags & PF_W) ? 'W' : ' ';
	buf[2] = (p_flags & PF_X) ? 'E' : ' ';
	return (buf);
}

static void print_middleph(ElfN_Phdr *phdr, uint16_t phnum, ElfClass class)
{
	uint16_t i;
	char *format;
	uint16_t adwidth, fswidth;

	adwidth = (class == ELF32) ? 8 : 16;
	fswidth = (class == ELF32) ? 5 : 6;
	format = "  %-*s 0x%06lx 0x%0*lx 0x%0*lx 0x%0*lx 0x%0*lx %3s %#lx\n";
	for (i = 0; i < phnum; i++)
	{
		printf(format, 14, get_segment_type(phdr[i].p_type), phdr[i].p_offset,
		       adwidth, phdr[i].p_vaddr, adwidth, phdr[i].p_paddr,
		       fswidth, phdr[i].p_filesz, fswidth, phdr[i].p_memsz,
		       get_pflags(phdr[i].p_flags), phdr[i].p_align);
	}
}

void
print_pheader(ElfN_Phdr *phdr, ElfN_Shdr *shdr, ElfN_Ehdr *ehdr, char *strtab)
{
	char *format;
	ElfClass class;
	uint16_t adwidth, fswidth;

	class = (get_class(ehdr->e_ident[EI_CLASS]));
	adwidth = (class == ELF32) ? 10 : 18;
	fswidth = (class == ELF32) ? 7 : 8;

	printf("\nElf file type is %s\n", get_ftype(ehdr->e_type));
	printf("Entry point 0x%lx\n", ehdr->e_entry);
	printf("There are %d program headers, starting at offset %lu\n\n",
	       ehdr->e_phnum, ehdr->e_phoff);
	printf("Program Headers:\n");
	format = "  %-14s %-8s %-*s %-*s %-*s %-*s %-3s %s\n";
	printf(format, "Type", "Offset", adwidth, "VirtAddr", adwidth, "PhysAddr",
	       fswidth, "FileSiz", fswidth, "MemSiz", "Flg", "Align");
	print_middleph(phdr, ehdr->e_phnum, class);
	print_segment_mapping(phdr, shdr, ehdr, strtab);
	free(strtab);
	free(shdr);
	free(phdr);
}
