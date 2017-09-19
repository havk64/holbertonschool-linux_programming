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


void print_pheader(ElfN_Phdr *phdr, ElfN_Ehdr *ehdr, char *strtab)
{
	printf("\nElf file type is %s\n", get_ftype(ehdr->e_type));
	printf("Entry point %lx\n", ehdr->e_entry);
	printf("There are %d program headers, starting at offset %lu\n\n",
	       ehdr->e_phnum, ehdr->e_phoff);
	printf("Program headers:\n");
	printf("  %-14s %-8s %-9s %-9s %-7s %-7s %-3s %s\n",
	       "Type", "Offset", "VirtAddr", "PhysAddr", "FileSiz", "MemSiz",
	       "Flg", "Align");
	free(strtab);
	free(phdr);
}
