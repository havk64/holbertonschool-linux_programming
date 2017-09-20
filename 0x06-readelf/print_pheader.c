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

static void print_middleph(ElfN_Phdr *phdr, char *strtab, uint16_t phnum)
{
	uint16_t i;

	(void)(strtab);
	for (i = 0; i < phnum; i++)
	{
		printf("  %-*s 0x%06lx 0x%08lx 0x%08lx 0x%05lx 0x%05lx %3s 0x%lx\n", 14,
		       get_segment_type(phdr[i].p_type), phdr[i].p_offset,
		       phdr[i].p_vaddr, phdr[i].p_paddr, phdr[i].p_filesz,
		       phdr[i].p_memsz, get_pflags(phdr[i].p_flags), phdr[i].p_align);
	}
}

void
print_pheader(ElfN_Phdr *phdr, ElfN_Shdr *shdr, ElfN_Ehdr *ehdr, char *strtab)
{
	printf("\nElf file type is %s\n", get_ftype(ehdr->e_type));
	printf("Entry point 0x%lx\n", ehdr->e_entry);
	printf("There are %d program headers, starting at offset %lu\n\n",
	       ehdr->e_phnum, ehdr->e_phoff);
	printf("Program Headers:\n");
	printf("  %-14s %-8s %-10s %-10s %-7s %-7s %-3s %s\n",
	       "Type", "Offset", "VirtAddr", "PhysAddr", "FileSiz", "MemSiz",
	       "Flg", "Align");
	print_middleph(phdr, strtab, ehdr->e_phnum);
	print_segment_mapping(phdr, ehdr, strtab);
	free(strtab);
	free(phdr);
}
