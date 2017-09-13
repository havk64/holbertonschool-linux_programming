#include "readelf.h"

char *get_strtab(FILE *file, ElfN_Ehdr *ehdr)
{
	char *name;
	ssize_t n;
	Elf32_Shdr shdr;

	n = fseek(file, ehdr->e_shoff + (ehdr->e_shstrndx * ehdr->e_shentsize),
		  SEEK_SET);
	if (n < 0)
	{
		perror("fseek error");
		exit(EXIT_FAILURE);
	}

	n = fread(&shdr, sizeof(Elf32_Shdr), 1, file);
	if (n != 1)
		exit(EXIT_FAILURE);

	name = malloc(shdr.sh_size);
	if (name == NULL)
		exit(EXIT_FAILURE);

	n = fseek(file, shdr.sh_offset, SEEK_SET);
	if (n < 0)
	{
		perror("fseek error");
		exit(EXIT_FAILURE);
	}

	n = fread(name, 1, shdr.sh_size, file);
	if (n != shdr.sh_size)
		exit(EXIT_FAILURE);

	return (name);
}
