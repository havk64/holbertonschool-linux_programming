#include "readelf.h"

void parse_64(ElfN_Ehdr *ehdr, FILE *file, int ei_data)
{
	uint64_t (*get_byte)(uint64_t, int);
	ssize_t n;
	Elf64_Ehdr header;

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
