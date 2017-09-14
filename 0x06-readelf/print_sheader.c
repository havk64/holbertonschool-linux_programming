#include "readelf.h"

void print_sheader(ElfN_Shdr *shdr, ElfN_Ehdr *ehdr, FILE *file)
{
	uint64_t i, shnum;
	int nwidth = 18;
	int twidth = 15;
	char *sh_strtab;

	sh_strtab = get_strtab(file, ehdr);
	shnum = ehdr->e_shnum;
	printf("There are %lu section headers, starting at offset 0x%lx:\n\n",
	       shnum, ehdr->e_shoff);
	printf("Section Headers:\n");
	printf("  [Nr] %-*s%-*s %-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s\n",
	       nwidth, "Name", twidth, "Type", 9, "Addr", 7, "Off", 7, "Size", 3,
	       "ES", 4, "Flg", 3, "Lk", 4, "Inf", 2, "Al");
	for (i = 0; i < shnum; i++)
	{
		/* TODO add function to return section type */
		printf("  [%2lu] %-*s%-*s %08lx %06lx %06lx %02lx%*s %2u %3u %2lu\n",
		       i, nwidth, sh_strtab + shdr[i].sh_name, twidth,
		       get_type(shdr[i].sh_type), shdr[i].sh_addr, shdr[i].sh_offset,
		       shdr[i].sh_size, shdr[i].sh_entsize, 4,
		       get_flags(shdr[i].sh_flags), shdr[i].sh_link,
		       shdr[i].sh_info, shdr[i].sh_addralign);
	}
	printf("Key to Flags:\n");
	printf("  W (write), A (alloc), X (execute), M (merge), S (strings)\n");
	printf("  I (info), L (link order), G (group), T (TLS), E (exclude), ");
	printf("x (unknown)\n");
	printf("  O (extra OS processing required) o (OS specific), ");
	printf("p (processor specific)\n");
	free(sh_strtab);
}

