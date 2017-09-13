#include "readelf.h"

/**
 * main - entry point
 * @argc: number of positional arguments
 * @argv: the vector string
 * Return: On success, EXIT_SUCCESS. On Error, EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	int fd;
	ElfN_Ehdr ehdr;

	if (argc != 2)
	{
		printf("Usage: %s <ELF binary file>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	fd = get_stat(argv[1]);
	parse_elf_header(&ehdr, fd);
	print_header(&ehdr);

	close(fd);
	return (0);
}
