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

void parse_section_32(ElfN_Ehdr *ehdr, ElfN_Shdr *shdr, FILE *file)
{
	ssize_t n;
	uint64_t shnum;
	Elf32_Shdr *xhdr;

	shnum = ehdr->e_shnum;
	xhdr = malloc(ehdr->e_shentsize * shnum);
	if (xhdr == NULL)
		exit(EXIT_FAILURE);

	n = fseek(file, ehdr->e_shoff, SEEK_SET);
	if (n < 0)
	{
		perror("Fseek error");
		exit(EXIT_FAILURE);
	}

	n = fread(xhdr, sizeof(Elf32_Shdr), ehdr->e_shnum, file);
	if (n != ehdr->e_shnum)
		exit(EXIT_FAILURE);

	copy_sheader32(shdr, xhdr, shnum, ehdr->e_ident[EI_DATA]);

	free(xhdr);
	fclose(file);
}

void
copy_sheader32(ElfN_Shdr *shdr, Elf32_Shdr *xhdr, uint64_t shnum, int ei_data)
{
	uint64_t i;
	uint64_t (*get_byte)(uint64_t, int);

	get_byte = (ei_data == ELFDATA2MSB) ? get_byte_big_endian : get_byte_host;
	for (i = 0; i < shnum; i++)
	{
		(shdr + i)->sh_name		= GET_BYTE((xhdr + i)->sh_name);
		(shdr + i)->sh_type		= GET_BYTE((xhdr + i)->sh_type);
		(shdr + i)->sh_flags		= GET_BYTE((xhdr + i)->sh_flags);
		(shdr + i)->sh_addr		= GET_BYTE((xhdr + i)->sh_addr);
		(shdr + i)->sh_offset		= GET_BYTE((xhdr + i)->sh_offset);
		(shdr + i)->sh_size		= GET_BYTE((xhdr + i)->sh_size);
		(shdr + i)->sh_link		= GET_BYTE((xhdr + i)->sh_link);
		(shdr + i)->sh_info		= GET_BYTE((xhdr + i)->sh_info);
		(shdr + i)->sh_addralign	= GET_BYTE((xhdr + i)->sh_addralign);
		(shdr + i)->sh_entsize		= GET_BYTE((xhdr + i)->sh_entsize);
	}
}
