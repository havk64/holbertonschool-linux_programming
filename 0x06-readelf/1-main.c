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
	ElfN_Shdr *shdr;
	FILE *stream;
	char *strtab;

	shdr = NULL;
	if (argc != 2)
	{
		printf("Usage: %s <ELF binary file>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	fd = get_stat(argv[1]);
	stream = parse_elf_header(&ehdr, fd);
	shdr = parse_sheaders(&ehdr, stream);
	strtab = get_strtab(stream, shdr[ehdr.e_shstrndx]);
	print_sheader(shdr, &ehdr, strtab);

	fclose(stream);
	close(fd);
	return (EXIT_SUCCESS);
}
