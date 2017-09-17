#include "readelf.h"

/**
 * get_sizeoff - retrieves the sh_size and sh_offset of an strtab
 * @shdr: the destination section header
 * @ehdr: the struct representing the elf header
 * Return: Always void.
 */
void get_sizeoff(ElfN_Shdr *shdr, ElfN_Ehdr *ehdr, FILE *file)
{
	ssize_t n;
	uint64_t (*get_byte)(uint64_t, int);

	get_byte = (ehdr->e_ident[EI_DATA] == ELFDATA2MSB) ? get_byte_big_endian :
		get_byte_host;
	if (get_class(ehdr->e_ident[EI_CLASS]) == ELF32)
	{
		Elf32_Shdr xhdr;

		n = fread(&xhdr, sizeof(Elf32_Shdr), 1, file);
		if (n != 1)
			exit(EXIT_FAILURE);

		shdr->sh_size		= GET_BYTE(xhdr.sh_size);
		shdr->sh_offset		= GET_BYTE(xhdr.sh_offset);
	} else
	{
		Elf64_Shdr xhdr;

		n = fread(&xhdr, sizeof(Elf64_Shdr), 1, file);
		if (n != 1)
			exit(EXIT_FAILURE);

		shdr->sh_size		= GET_BYTE(xhdr.sh_size);
		shdr->sh_offset		= GET_BYTE(xhdr.sh_offset);
	}
}

char *get_strtab(FILE *file, ElfN_Ehdr *ehdr)
{
	char *name;
	ssize_t n;
	ElfN_Shdr shdr;

	n = fseek(file, ehdr->e_shoff + (ehdr->e_shstrndx * ehdr->e_shentsize),
		  SEEK_SET);
	if (n < 0)
	{
		perror("fseek error");
		exit(EXIT_FAILURE);
	}

	get_arch(&shdr, ehdr, file);
	name = malloc(shdr.sh_size);
	if (name == NULL)
		exit(EXIT_FAILURE);

	n = fseek(file, shdr.sh_offset, SEEK_SET);
	if (n < 0)
	{
		perror("fseek error");
		exit(EXIT_FAILURE);
	}

	n = fread(name, shdr.sh_size, 1, file);
	if (n != 1)
		exit(EXIT_FAILURE);

	return (name);
}

/**
 * get_letter - returns a character representing each section header flag
 * @flag: a bit flag
 * Return: a character representing miscellaneous attributes
 */
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

char *get_flags2(uint64_t sh_flags)
{
	static char buff[16];
	int i;

	i = 0;
	if (sh_flags & SHF_WRITE)
		buff[i++] = 'W';
	if (sh_flags & SHF_ALLOC)
		buff[i++] = 'A';
	if (sh_flags & SHF_EXECINSTR)
		buff[i++] = 'X';
	if (sh_flags & SHF_MERGE)
		buff[i++] = 'M';
	if (sh_flags & SHF_STRINGS)
		buff[i++] = 'S';
	if (sh_flags & SHF_INFO_LINK)
		buff[i++] = 'I';
	if (sh_flags & SHF_LINK_ORDER)
		buff[i++] = 'L';
	if (sh_flags & SHF_OS_NONCONFORMING)
		buff[i++] = 'O';
	if (sh_flags & SHF_GROUP)
		buff[i++] = 'G';
	if (sh_flags & SHF_TLS)
		buff[i++] = 'T';
	if (sh_flags & SHF_EXCLUDE)
		buff[i++] = 'E';

	buff[i] = '\0';
	return(buff);
}

char *get_type(uint64_t sh_type)
{
	switch (sh_type)
	{
	case SHT_NULL:			return "NULL";
	case SHT_PROGBITS:		return "PROGBITS";
	case SHT_SYMTAB:		return "SYMTAB";
	case SHT_STRTAB:		return "STRTAB";
	case SHT_RELA:			return "RELA";
	case SHT_HASH:			return "HASH";
	case SHT_DYNAMIC:		return "DYNAMIC";
	case SHT_NOTE:			return "NOTE";
	case SHT_NOBITS:		return "NOBITS";
	case SHT_REL:			return "REL";
	case SHT_SHLIB:			return "SHLIB";
	case SHT_DYNSYM:		return "DYNSYM";
	case SHT_INIT_ARRAY:		return "INIT_ARRAY";
	case SHT_FINI_ARRAY:		return "FINI_ARRAY";
	case SHT_PREINIT_ARRAY:		return "PREINIT_ARRAY";
	case SHT_GNU_HASH:		return "GNU_HASH";
	case SHT_GROUP:			return "GROUP";
	case SHT_SYMTAB_SHNDX:		return "SYMTAB SECTION INDICIES";
	case SHT_GNU_verdef:		return "VERDEF";
	case SHT_GNU_verneed:		return "VERNEED";
	case SHT_GNU_versym:		return "VERSYM";
	case 0x6ffffff0:		return "VERSYM";
	case 0x6ffffffc:		return "VERDEF";
	case 0x7ffffffd:		return "AUXILIARY";
	case 0x7fffffff:		return "FILTER";
	case SHT_GNU_LIBLIST:		return "GNU_LIBLIST";
	default:			return (0);
	}
}
