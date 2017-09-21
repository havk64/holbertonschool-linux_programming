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
	ElfN_Phdr *phdr;
	ElfN_Shdr *shdr;
	FILE *stream;
	char *strtab;

	if (argc != 2)
	{
		printf("Usage: %s <ELF binary file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	fd = get_stat(argv[1]);
	if (fd < 0)
		return (EXIT_FAILURE);

	stream = parse_elf_header(&ehdr, fd);
	if (ehdr.e_phnum == 0)
	{
		printf("\nThere are no program headers in this file.\n");
	} else
	{
		shdr = parse_sheaders(&ehdr, stream);
		strtab = get_strtab(stream, shdr[ehdr.e_shstrndx]);
		phdr = parse_pheader(&ehdr, stream);
		print_pheader(phdr, shdr, &ehdr, strtab, stream);
	}

	fclose(stream);
	close(fd);
	return (0);
}
