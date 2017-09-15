#include "readelf.h"

/**
 * parse_elf_header - parses a elf file to print its reader
 * @ehdr: a pointer to a ElfN_Ehdr(32/64bits) struct
 * @fd: the file descriptor of the binary file
 * Return: Always Void
 */
void parse_elf_header(ElfN_Ehdr *ehdr, int fd)
{
	FILE *stream;
	void (*fill_Ehdr)(ElfN_Ehdr*, FILE*, int);
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
	fclose(stream);
}

/**
 * parse_elf_sections - parses a elf file to print its reader
 * @fd: the file descriptor of the binary file
 * Return: Always Void
 */
FILE *parse_elf_sections(ElfN_Ehdr *ehdr, int fd)
{
	FILE *stream;
	/* ElfN_Ehdr ehdr; */
	void (*fill_Ehdr)(ElfN_Ehdr*, FILE*, int);
	/* void (*fill_Shdr)(ElfN_Ehdr*, FILE*, int); */
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
	/* TODO define a macro to choose between functions */
	fill_Ehdr = (elfclass == ELF32) ? &parse_32 : &parse_64;
	(*fill_Ehdr)(ehdr, stream, ehdr->e_ident[EI_DATA]);
	return (stream);
}

ElfN_Shdr *parse_test(FILE *stream, ElfN_Ehdr *ehdr)
{
	ElfClass elfclass;
	ElfN_Shdr *shdr;
	void (*fill_Shdr)(ElfN_Ehdr*, ElfN_Shdr*, FILE*);

	shdr = malloc(sizeof(ElfN_Shdr) * ehdr->e_shnum);
	if (shdr == NULL)
		exit(EXIT_FAILURE);

	elfclass = get_class(ehdr->e_ident[EI_CLASS]);
	fill_Shdr = (elfclass == ELF32) ? &parse_section_32 : &parse_section_64;
	(*fill_Shdr)(ehdr, shdr, stream);
	return (shdr);
}
