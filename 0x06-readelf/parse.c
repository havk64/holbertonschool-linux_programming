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
	void (*fill_Ehdr)(ElfN_Ehdr*, FILE*, unsigned char);
	ssize_t n;
	ElfClass elfclass;

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
		exit(EXIT_FAILURE);
	}

	elfclass = get_class(ehdr->e_ident[EI_CLASS]);
	fill_Ehdr = (elfclass == ELF32) ? &parse_32 : &parse_64;
	(*fill_Ehdr)(ehdr, stream, ehdr->e_ident[EI_DATA]);
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
	ElfClass ei_class;
	ElfN_Shdr *shdr;
	void (*copy_Shdr)(ElfN_Shdr*, ElfN_Ehdr*, FILE *);

	ei_class	= get_class(ehdr->e_ident[EI_CLASS]);
	shdr = malloc(sizeof(ElfN_Shdr) * ehdr->e_shnum);
	if (shdr == NULL)
		exit(EXIT_FAILURE);

	n = fseek(file, ehdr->e_shoff, SEEK_SET);
	if (n < 0)
	{
		perror("Fseek error");
		exit(EXIT_FAILURE);
	}

	copy_Shdr = (ei_class == ELF32) ? &copy_sheader_32 : &copy_sheader_64;
	(*copy_Shdr)(shdr, ehdr, file);
	return (shdr);
}

ElfN_Phdr *parse_pheader(ElfN_Ehdr *ehdr, FILE *file)
{
	ssize_t n;
	ElfClass ei_class;
	ElfN_Phdr *phdr;
	void (*copy_Phdr)(ElfN_Phdr*, ElfN_Ehdr*, FILE*);

	ei_class = get_class(ehdr->e_ident[EI_CLASS]);
	phdr = malloc(sizeof(ElfN_Phdr) * ehdr->e_phnum);
	if (phdr == NULL)
		exit(EXIT_FAILURE);

	n = fseek(file, ehdr->e_phoff, SEEK_SET);
	if (n < 0)
	{
		perror("Fseek error");
		exit(EXIT_FAILURE);
	}

	copy_Phdr = (ei_class == ELF32) ? &copy_pheader_32 : &copy_pheader_64;
	(*copy_Phdr)(phdr, ehdr, file);
	return (phdr);
}
