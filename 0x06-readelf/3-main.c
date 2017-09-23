#include "readelf.h"

int main(int argc, char *argv[])
{
	int fd;
	ElfN_Ehdr ehdr;
	ElfN_Shdr *shdr, *section;
	ElfN_Sym *symtab;
	FILE *stream;
	uint16_t i;
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
	shdr = parse_sheaders(&ehdr, stream);
	strtab = get_strtab(stream, shdr[ehdr.e_shstrndx]);
	for (i = 0; i < ehdr.e_shnum; i++)
	{
		section = (shdr + i);
		if (section->sh_type == SHT_DYNSYM || section->sh_type == SHT_SYMTAB)
		{
			symtab = parse_symheader(&ehdr, shdr[i], stream);
			/* print */
			free(symtab);
		}
	}

	free(strtab);
	free(shdr);
	fclose(stream);
	close(fd);
	return (EXIT_SUCCESS);
}
