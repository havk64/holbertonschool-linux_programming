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
typedef struct
{
	uint32_t	sh_name;		/* Offset to a string in .shstrtab section */
	uint32_t	sh_type;		/* Identify the type of the header */
	uint64_t	sh_flags;		/* Identify the attributes of a section */
	uint64_t	sh_addr;		/* Virtual address of the section */
	uint64_t	sh_offset;		/* Offset of section in the image file */
	uint64_t	sh_size;		/* Size of the section */
	uint32_t	sh_link;		/* Section index of associated section */
	uint32_t	sh_info;		/* Extra info */
	uint64_t	sh_addralign;		/* Required alignment of the section */
	uint64_t	sh_entsize;		/* Size of each section */
} ElfN_Shdr; /* Struct to represent section headers from 32 and 64 bits */
#define width 35
#define GET_BYTE(field) get_byte(field, sizeof(field))
_Bool is_elf(unsigned char *magic);
int get_stat(char *filename);
void parse_elf_header(ElfN_Ehdr *ehdr, int fd);
FILE *parse_elf_sections(ElfN_Ehdr *ehdr, int fd);
ElfClass get_class(char c);
void parse_32(ElfN_Ehdr *ehdr, FILE *file, int ei_data);
void parse_64(ElfN_Ehdr *ehdr, FILE *file, int ei_data);
void parse_section_32(ElfN_Ehdr *ehdr, ElfN_Shdr *shdr, FILE *file);
void parse_section_64(ElfN_Ehdr *ehdr, ElfN_Shdr *shdr, FILE *file);
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
void print_sheader(ElfN_Shdr *shdr, ElfN_Ehdr *ehdr, char *sh_strtab);
char *get_flags(uint64_t sh_flags);
char *get_flags2(uint64_t sh_flags);
char *get_type(uint64_t sh_type);
char get_letter(uint64_t flag);
void copy_sheader32(ElfN_Shdr *shdr, Elf32_Shdr *xhdr, uint64_t shnum,
		  int ei_data);
ElfN_Shdr *parse_test(FILE *stream, ElfN_Ehdr *ehdr);
uint64_t get_byte_big_endian(uint64_t, int);
uint64_t get_byte_host(uint64_t, int);
#endif /* READELF_H */
