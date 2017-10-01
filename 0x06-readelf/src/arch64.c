#include "readelf.h"

/**
 * parse_64 - extracts and process a elf header
 * @ehdr: a pointer to an Elf header struct
 * @file: a pointer to a file stream
 * Return: Always void.
 */
void parse_64(ElfN_Ehdr *ehdr, FILE *file)
{
	uint64_t (*get_byte)(uint64_t, int);
	ssize_t n;
	Elf64_Ehdr header;

	get_byte = (IS_BIGENDIAN(ehdr)) ? get_byte_big_endian : get_byte_host;
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

/**
 * copy_sheader_64 - copy a section header array to a custom struct observing
 * endianess
 * @shdr: a pointer to an array of section headers struct
 * @ehdr: a pointer to an Elf header struct
 * @file: a pointer to a file stream
 * Return: Always void
 */
void copy_sheader_64(ElfN_Shdr *shdr, ElfN_Ehdr *ehdr, FILE *file)
{
	Elf64_Shdr *source;
	uint64_t (*get_byte)(uint64_t, int);
	uint16_t i;
	ssize_t n;

	get_byte = (IS_BIGENDIAN(ehdr)) ? get_byte_big_endian : get_byte_host;
	source = malloc(ehdr->e_shentsize * ehdr->e_shnum);
	if (source == NULL)
		exit(EXIT_FAILURE);

	n = fread(source, ehdr->e_shentsize, ehdr->e_shnum, file);
	if (n != ehdr->e_shnum)
		exit(EXIT_FAILURE);

	for (i = 0; i < ehdr->e_shnum; i++)
	{
		(shdr + i)->sh_name		= GET_BYTE((source + i)->sh_name);
		(shdr + i)->sh_type		= GET_BYTE((source + i)->sh_type);
		(shdr + i)->sh_flags		= GET_BYTE((source + i)->sh_flags);
		(shdr + i)->sh_addr		= GET_BYTE((source + i)->sh_addr);
		(shdr + i)->sh_offset		= GET_BYTE((source + i)->sh_offset);
		(shdr + i)->sh_size		= GET_BYTE((source + i)->sh_size);
		(shdr + i)->sh_link		= GET_BYTE((source + i)->sh_link);
		(shdr + i)->sh_info		= GET_BYTE((source + i)->sh_info);
		(shdr + i)->sh_addralign	= GET_BYTE((source + i)->sh_addralign);
		(shdr + i)->sh_entsize		= GET_BYTE((source + i)->sh_entsize);
	}
	free(source);
}

/**
 * copy_pheader_64 - read and fill an ElfN_Phdr struct
 * @phdr: a pointer to an array of segment header struct
 * @ehdr: a pointer to an elf header struct
 * @file: a pointer to a file stream
 * Return: Always void.
 */
void copy_pheader_64(ElfN_Phdr *phdr, ElfN_Ehdr *ehdr, FILE *file)
{
	Elf64_Phdr *source;
	uint64_t (*get_byte)(uint64_t, int);
	uint16_t i, phnum, phsize;
	ssize_t n;

	phnum = ehdr->e_phnum;
	phsize = ehdr->e_phentsize;
	get_byte = (IS_BIGENDIAN(ehdr)) ? get_byte_big_endian :
		get_byte_host;

	source = malloc(phsize * phnum);
	if (source == NULL)
		exit(EXIT_FAILURE);

	n = fread(source, phsize, phnum, file);
	if (n != phnum)
		exit(EXIT_FAILURE);

	for (i = 0; i < phnum; i++)
	{
		(phdr + i)->p_type		= GET_BYTE((source + i)->p_type);
		(phdr + i)->p_flags		= GET_BYTE((source + i)->p_flags);
		(phdr + i)->p_offset		= GET_BYTE((source + i)->p_offset);
		(phdr + i)->p_vaddr		= GET_BYTE((source + i)->p_vaddr);
		(phdr + i)->p_paddr		= GET_BYTE((source + i)->p_paddr);
		(phdr + i)->p_filesz		= GET_BYTE((source + i)->p_filesz);
		(phdr + i)->p_memsz		= GET_BYTE((source + i)->p_memsz);
		(phdr + i)->p_align		= GET_BYTE((source + i)->p_align);
	}
	free(source);
}

void
copy_sym64(ElfN_Sym *symtab, uint16_t size, ElfN_Ehdr *ehdr, FILE *file)
{
	ssize_t n;
	Elf64_Sym *source;
	uint64_t (*get_byte)(uint64_t, int);
	uint16_t i;

	get_byte = (IS_BIGENDIAN(ehdr)) ? get_byte_big_endian : get_byte_host;

	source = malloc(size * sizeof(Elf64_Sym));
	if (source == NULL)
		exit(EXIT_FAILURE);

	n = fread(source, size * sizeof(Elf64_Sym), 1, file);
	if (n != 1)
		exit(EXIT_FAILURE);


	for (i = 0; i < size; i++)
	{
		(symtab + i)->st_name		= GET_BYTE((source + i)->st_name);
		(symtab + i)->st_value		= GET_BYTE((source + i)->st_value);
		(symtab + i)->st_size		= GET_BYTE((source + i)->st_size);
		(symtab + i)->st_info		= GET_BYTE((source + i)->st_info);
		(symtab + i)->st_other		= GET_BYTE((source + i)->st_other);
		(symtab + i)->st_shndx		= GET_BYTE((source + i)->st_shndx);
	}
	free(source);
}
