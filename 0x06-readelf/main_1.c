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
	stream = parse_elf_sections(&ehdr, fd);
	strtab = get_strtab(stream, &ehdr);
	shdr = parse_sheaders(&ehdr, stream);
	print_sheader(shdr, &ehdr, strtab);

	close(fd);
	return (0);
}
