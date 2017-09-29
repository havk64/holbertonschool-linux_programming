#include "readelf.h"

/**
 * parse_elf_header - parses a elf file and fills an internal struct to be used
 * to print/manipulate its attributes
 * @ehdr: a pointer to a ElfN_Ehdr(32/64bits) struct
 * @fd: the file descriptor of the binary file
 * Return: Always Void
 */
FILE *parse_elf_header(ElfN_Ehdr *ehdr, int fd)
{
	FILE *stream;
	void (*fill_Ehdr)(ElfN_Ehdr*, FILE*);
	ssize_t n;

	stream = fdopen(fd, "rb");
	if (stream == NULL)
	{
		perror("Error creating file stream");
		exit(EXIT_FAILURE);
	}

	n = fread(ehdr->e_ident, EI_NIDENT, 1, stream);
	if (!is_elf(ehdr->e_ident) || n != 1)
	{
		printf("Not an ELF file - it has the wrong magic bytes at the start\n");
		fclose(stream);
		exit(EXIT_FAILURE);
	}

	fill_Ehdr = (IS_ELF64(ehdr)) ? &parse_64 : &parse_32;
	(*fill_Ehdr)(ehdr, stream);
	return (stream);
}

/**
 * parse_sheaders - extracts and process the section headers from an elf file
 * @ehdr: a pointer to an Elf header struct
 * @file: a pointer to a file stream
 * Return: a pointer to an array of section header struct
 */
ElfN_Shdr *parse_sheaders(ElfN_Ehdr *ehdr, FILE *file)
{
	ssize_t n;
	ElfN_Shdr *shdr;
	void (*copy_Shdr)(ElfN_Shdr*, ElfN_Ehdr*, FILE *);

	shdr = malloc(sizeof(ElfN_Shdr) * ehdr->e_shnum);
	if (shdr == NULL)
		exit(EXIT_FAILURE);

	n = fseek(file, ehdr->e_shoff, SEEK_SET);
	if (n < 0)
	{
		perror("Fseek error");
		exit(EXIT_FAILURE);
	}

	copy_Shdr = (IS_ELF64(ehdr)) ? &copy_sheader_64 : &copy_sheader_32;
	(*copy_Shdr)(shdr, ehdr, file);
	return (shdr);
}

/**
 * parse_pheader - parse a program (segment) header
 * @ehdr: a pointer to a Elf header struct
 * @file: a pointer to a file stream
 * Return: an array of Elf program header structs if any
 */
ElfN_Phdr *parse_pheader(ElfN_Ehdr *ehdr, FILE *file)
{
	ssize_t n;
	ElfN_Phdr *phdr;
	void (*copy_Phdr)(ElfN_Phdr*, ElfN_Ehdr*, FILE*);

	phdr = malloc(sizeof(ElfN_Phdr) * ehdr->e_phnum);
	if (phdr == NULL)
		exit(EXIT_FAILURE);

	n = fseek(file, ehdr->e_phoff, SEEK_SET);
	if (n < 0)
	{
		perror("Fseek error");
		exit(EXIT_FAILURE);
	}

	copy_Phdr = (IS_ELF64(ehdr)) ? &copy_pheader_64 : &copy_pheader_32;
	(*copy_Phdr)(phdr, ehdr, file);
	return (phdr);
}

ElfN_Sym *parse_symheader(ElfN_Ehdr *ehdr, ElfN_Shdr symhdr, FILE *file)
{
	ssize_t n;
	ElfN_Sym *symtab;
	void (*copy_Symhdr)(ElfN_Sym*, uint16_t, ElfN_Ehdr*, FILE*);
	uint16_t size;

	size = symhdr.sh_size / symhdr.sh_entsize;
	symtab = malloc(size * sizeof(ElfN_Sym));
	if (symtab == NULL)
		exit(EXIT_FAILURE);

	n = fseek(file, symhdr.sh_offset, SEEK_SET);
	if (n < 0)
	{
		perror("Fseek error");
		exit(EXIT_FAILURE);
	}

	copy_Symhdr = (IS_ELF64(ehdr)) ? &copy_sym64 : &copy_sym32;
	(*copy_Symhdr)(symtab, size, ehdr, file);
	return (symtab);
}
