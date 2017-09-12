#ifndef READELF_H
#define READELF_H
#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <endian.h>
typedef enum
{
	ELF32, ELF64
} ElfClass;
typedef struct
{
	unsigned char	e_ident[EI_NIDENT];	/* ELF "magic number" */
	uint64_t	e_entry;		/* Entry point virtual address */
	uint64_t	e_phoff;		/* Program header table file offset */
	uint64_t	e_shoff;		/* Section header table file offset */
	uint32_t	e_version;		/* Identifies object file version */
	uint32_t	e_flags;		/* Processor-specific flags */
	uint16_t	e_type;			/* Identifies object file type */
	uint16_t	e_machine;		/* Specifies required architecture */
	uint16_t	e_ehsize;		/* ELF header size in bytes */
	uint16_t	e_phentsize;		/* Program header table entry size */
	uint16_t	e_phnum;		/* Program header table entry count */
	uint16_t	e_shentsize;		/* Section header table entry size */
	uint16_t	e_shnum;		/* Section header table entry count */
	uint16_t	e_shstrndx;		/* Section header string table index */
} ElfN_Ehdr; /* Struct to represent headers from both 32 and 64bits files */
#define width 35
#define GET_BYTE(field) get_byte(field, sizeof(field))
_Bool is_elf(unsigned char *magic);
int get_stat(char *filename);
void parse_elf_header(int fd);
void parse_elf_sections(int fd);
ElfClass get_class(char c);
void parse_32(ElfN_Ehdr *ehdr, FILE *file, int ei_data);
void parse_64(ElfN_Ehdr *ehdr, FILE *file, int ei_data);
void parse_section_32(ElfN_Ehdr *ehdr, FILE *file, int ei_data);
void parse_section_64(ElfN_Ehdr *ehdr, FILE *file, int ei_data);
void print_identity(unsigned char *header);
void print_magic(unsigned char *e_ident);
void print_header(ElfN_Ehdr *hptr);
void print_class(unsigned char data);
void print_data(unsigned char data);
void print_version(unsigned char data);
void print_osabi(unsigned char data);
void print_type(uint16_t data);
void print_elf_version(uint32_t data);
void print_phoff(uint64_t phoff);
void print_shoff(uint64_t shoff);
char *get_strtab(FILE *file, ElfN_Ehdr *ehdr);
uint64_t get_byte_big_endian(uint64_t, int);
uint64_t get_byte_host(uint64_t, int);
#endif /* READELF_H */
