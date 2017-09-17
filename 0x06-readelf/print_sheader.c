#include "readelf.h"

void print_sheader(ElfN_Shdr *shdr, ElfN_Ehdr *ehdr, char *sh_strtab)
{
	uint16_t shnum;

	shnum = ehdr->e_shnum;
	printf("There are %u section headers, starting at offset 0x%lx:\n\n",
	       shnum, ehdr->e_shoff);
	printf("Section Headers:\n");
	if (ehdr->e_ident[EI_CLASS] == ELFCLASS32)
		print_middle32(shdr, shnum, sh_strtab);
	else
		print_middle64(shdr, shnum, sh_strtab);
	print_tail();
	free(sh_strtab);
	free(shdr);
}

void print_middle32(ElfN_Shdr *shdr, uint16_t shnum, char *sh_strtab)
{
	uint16_t i;
	int nwidth = 18;
	int twidth = 15;

	printf("  [Nr] %-*s%-*s %-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s\n",
	       nwidth, "Name", twidth, "Type", 9, "Addr", 7, "Off", 7, "Size", 3,
	       "ES", 4, "Flg", 3, "Lk", 4, "Inf", 2, "Al");
	for (i = 0; i < shnum; i++)
	{
		/* TODO add function to return section type */
		printf("  [%2u] %-*s%-*s %08lx %06lx %06lx %02lx%*s %2u %3u %2lu\n",
		       i, nwidth, sh_strtab + shdr[i].sh_name, twidth,
		       get_type(shdr[i].sh_type), shdr[i].sh_addr, shdr[i].sh_offset,
		       shdr[i].sh_size, shdr[i].sh_entsize, 4,
		       get_flags(shdr[i].sh_flags), shdr[i].sh_link,
		       shdr[i].sh_info, shdr[i].sh_addralign);
	}
}

void print_middle64(ElfN_Shdr *shdr, uint16_t shnum, char *sh_strtab)
{
	uint16_t i;
	int nwidth = 18;
	int twidth = 15;

	printf("  [Nr] %-*s%-*s %-*s%-*s%-*s%-*s%-*s%-*s%-*s%-*s\n",
	       nwidth, "Name", twidth, "Type", 17, "Address", 7, "Off", 7, "Size", 3,
	       "ES", 4, "Flg", 3, "Lk", 4, "Inf", 2, "Al");
	for (i = 0; i < shnum; i++)
	{
		/* TODO add function to return section type */
		printf("  [%2u] %-*s%-*s %016lx %06lx %06lx %02lx%*s %2u %3u %2lu\n",
		       i, nwidth, sh_strtab + shdr[i].sh_name, twidth,
		       get_type(shdr[i].sh_type), shdr[i].sh_addr, shdr[i].sh_offset,
		       shdr[i].sh_size, shdr[i].sh_entsize, 4,
		       get_flags(shdr[i].sh_flags), shdr[i].sh_link,
		       shdr[i].sh_info, shdr[i].sh_addralign);
	}
}

void print_tail(void)
{
	printf("Key to Flags:\n");
	printf("  W (write), A (alloc), X (execute), M (merge), S (strings)\n");
	printf("  I (info), L (link order), G (group), T (TLS), E (exclude), ");
	printf("x (unknown)\n");
	printf("  O (extra OS processing required) o (OS specific), ");
	printf("p (processor specific)\n");
}
