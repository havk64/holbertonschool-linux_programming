#include "readelf.h"

/**
 * get_flags2 - Alternative way to get bit sets/flags
 * @sh_flags: a sh_flags member of a elf header
 * Return: a character representing section header attributes
 */
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
	return (buff);
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

/**
 * get_flags - retrieves the enabled attributes on a section header
 * @sh_flags: a sh_flags member of a elf section header struct
 * Return: The characters that identify the enabled attributes of an elf file
 */
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
