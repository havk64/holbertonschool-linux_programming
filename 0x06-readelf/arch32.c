#include "readelf.h"

void parse_32(ElfN_Ehdr *ehdr, FILE *file, int ei_data)
{
	uint64_t (*get_byte)(uint64_t, int);
	ssize_t n;
	Elf32_Ehdr header;

	get_byte = (ei_data == ELFDATA2MSB) ? get_byte_big_endian : get_byte_host;
	n = fread(&header.e_type, sizeof(header) - EI_NIDENT, 1, file);
	if (n != 1)
		exit(EXIT_FAILURE);

	ehdr->e_type		= GET_BYTE(header.e_type);
	ehdr->e_machine		= GET_BYTE(header.e_machine);
	ehdr->e_version		= GET_BYTE(header.e_version);
	ehdr->e_entry		= GET_BYTE(header.e_entry);
	ehdr->e_phoff		= GET_BYTE(header.e_phoff);
	ehdr->e_shoff		= GET_BYTE(header.e_shoff);
	ehdr->e_flags		= GET_BYTE(header.e_flags);
	ehdr->e_ehsize		= GET_BYTE(header.e_ehsize);
	ehdr->e_phentsize	= GET_BYTE(header.e_phentsize);
	ehdr->e_phnum		= GET_BYTE(header.e_phnum);
	ehdr->e_shentsize	= GET_BYTE(header.e_shentsize);
	ehdr->e_shnum		= GET_BYTE(header.e_shnum);
	ehdr->e_shstrndx	= GET_BYTE(header.e_shstrndx);
}

void parse_section_32(ElfN_Ehdr *ehdr, FILE *file, int ei_data)
{
	uint64_t (*get_byte)(uint64_t, int);
	ssize_t i, n;
	uint64_t shnum = ehdr->e_shnum;
	Elf32_Shdr *shdr;
	char *sh_strtab;

	shdr = malloc(ehdr->e_shentsize * shnum);
	if (shdr == NULL)
		exit(EXIT_FAILURE);

	get_byte = (ei_data == ELFDATA2MSB) ? get_byte_big_endian : get_byte_host;
	(void)(get_byte);
	n = fseek(file, ehdr->e_shoff, SEEK_SET);
	if (n < 0)
	{
		perror("Fseek error");
		exit(EXIT_FAILURE);
	}

	n = fread(shdr, sizeof(Elf32_Shdr), ehdr->e_shnum, file);
	if (n != ehdr->e_shnum)
		exit(EXIT_FAILURE);

	sh_strtab = get_strtab(file, ehdr);
	printf("There are %d section headers, starting at offset 0x%lx\n\n",
	       (int)shnum, ehdr->e_shoff);
	printf("Section Headers:\n");
	printf("  [Nr] %-*s%s %s\n", 25, "Name", "Type", "Addr");
	for (i = 0; i < (int)shnum; i++)
	{
		printf("  [%2d] %-*s%s %08x\n",
		       (int)i, 25, sh_strtab + shdr[i].sh_name, "PROGBITS", shdr[i].sh_addr);
	}
	free(sh_strtab);
	free(shdr);
}

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
