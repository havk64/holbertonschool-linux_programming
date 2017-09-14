#include "readelf.h"

char *get_strtab(FILE *file, ElfN_Ehdr *ehdr)
{
	char *name;
	ssize_t n;
	Elf32_Shdr shdr;

	n = fseek(file, ehdr->e_shoff + (ehdr->e_shstrndx * ehdr->e_shentsize),
		  SEEK_SET);
	if (n < 0)
	{
		perror("fseek error");
		exit(EXIT_FAILURE);
	}

	n = fread(&shdr, sizeof(Elf32_Shdr), 1, file);
	if (n != 1)
		exit(EXIT_FAILURE);

	name = malloc(shdr.sh_size);
	if (name == NULL)
		exit(EXIT_FAILURE);

	n = fseek(file, shdr.sh_offset, SEEK_SET);
	if (n < 0)
	{
		perror("fseek error");
		exit(EXIT_FAILURE);
	}

	n = fread(name, 1, shdr.sh_size, file);
	if (n != shdr.sh_size)
		exit(EXIT_FAILURE);

	return (name);
}

char get_letter(uint64_t flag)
{
	switch (flag)
	{
	case SHF_WRITE:			return ('W');
	case SHF_ALLOC:			return ('A');
	case SHF_EXECINSTR:		return ('X');
	case SHF_MERGE:			return ('M');
	case SHF_STRINGS:		return ('S');
	case SHF_INFO_LINK:		return ('I');
	case SHF_LINK_ORDER:		return ('L');
	case SHF_OS_NONCONFORMING:	return ('O');
	case SHF_GROUP:			return ('G');
	case SHF_TLS:			return ('T');
	case SHF_EXCLUDE:		return ('E');
	default:
		return (0);
	}
}

char *get_flags(uint64_t sh_flags)
{
	int i;
	static char buff[16];
	uint64_t flag;

	for (i = 0; sh_flags; i++)
	{
		flag = sh_flags & -sh_flags;
		sh_flags &= ~flag;
		buff[i] = get_letter(flag);
	}
	buff[i] = '\0';
	return (buff);
}
