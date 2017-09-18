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
