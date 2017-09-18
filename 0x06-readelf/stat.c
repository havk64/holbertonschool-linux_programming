#include "readelf.h"

/**
 * check_error - verify return value of system calls
 * @n: return value
 * @error: constant string to be printed in case of error
 *
 * Return, always Void
 */
static void check_error(int n, char *error)
{
	if (n < 0)
	{
		perror(error);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_elf - verify the first bytes of an elf file
 * @magic: the first bytes of an elf file
 * Return: 1 to true and 0 to false
 */
_Bool is_elf(unsigned char *magic)
{
	return (magic[0] == 0x7f &&
		magic[1] == 0x45 &&
		magic[2] == 0x4c &&
		magic[3] == 0x46);
}

/**
 * get_stat - verify attributes of a file
 * @filename: the name of the file to be checked
 * Return: the file descriptor related to the open file
 */
int get_stat(char *filename)
{
	int fd, st;
	struct stat sbuf;

	fd = open(filename, O_RDONLY);
	check_error(fd, "Error opening file");

	st = stat(filename, &sbuf);
	check_error(st, "Stat error");

	if ((sbuf.st_mode & S_IFMT) != S_IFREG)
	{
		printf("%s is not a regular file\n", filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * get_class - check the class of a elf file
 * @c: the byte to be checked
 * Return: a ElfClass enum object
 */
ElfClass get_class(char c)
{
	return ((c == ELFCLASS64) ? ELF64 : ELF32);
}
