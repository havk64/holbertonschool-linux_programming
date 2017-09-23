#include "readelf.h"

/**
  * get_strtab - retrieves the section header string table of an elf file
  * @file: a file stream to read from
  * @shdr: the section header of the String Table index
  * Return: the whole string table
 */
char *get_strtab(FILE *file, ElfN_Shdr shdr)
{
	char *name;
	ssize_t n;

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
 * get_flags - retrieves the enabled attributes on a section header
 * @sh_flags: a sh_flags member of a elf section header struct
 * Return: The characters that identify the enabled attributes of an elf file
 */
char *get_flags(uint64_t sh_flags)
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
	return (buff);
}

/**
 * get_type - retrieves the type of a given section
 * @sh_type: a sh_type member of a section header struct
 * Return: a string representing the type of a section
 */
char *get_type(uint64_t sh_type)
{
	static char buff[8];

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
	default:
		if (sh_type >= SHT_LOOS)
		{
			sprintf(buff, "LOOS+%lx", sh_type - SHT_LOOS);
			return (buff);
		}
		return (0);
	}
}

/**
 * get_interp - retrieves a interp content section
 * @file: a file stream to read from
 * @phdr: a ElfN_Phdr struct of type .interp
 * Return: a string with the interpreter's name
 */
char *get_interp(FILE *file, ElfN_Phdr phdr)
{
	ssize_t n;
	char *interp;

	interp = malloc(phdr.p_filesz);
	if (interp == NULL)
		exit(EXIT_FAILURE);

	n = fseek(file, phdr.p_offset, SEEK_SET);
	if (n < 0)
	{
		perror("Fseek error");
		exit(EXIT_FAILURE);
	}

	n = fread(interp, phdr.p_filesz, 1, file);
	if (n != 1)
		exit(EXIT_FAILURE);

	return (interp);
}
