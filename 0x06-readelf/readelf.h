#ifndef READELF_H
#define READELF_H
#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <endian.h>

/**
 * enum ElfClass - represent an Elf Class(32/64 bits)
 *
 * @ELF32: 32 bits class
 * @ELF64: 64 bits class
 */
typedef enum ElfClass
{
	ELF32, ELF64
} ElfClass;

/**
 * struct elfn_ehdr - Custom internal struct to represent 32/64bits elf headers
 *
 * @e_ident: Elf identity
 * @e_entry: Entry point
 * @e_phoff: Program header table offset
 * @e_shoff: Section header file offset
 * @e_version: Elf file version
 * @e_flags: Processor specific flags
 * @e_type: Object file type
 * @e_machine: Specifies architecture
 * @e_ehsize: Elf header size in bytes
 * @e_phentsize: Program header table entry size
 * @e_phnum: Program header table entry count
 * @e_shentsize: Section header table entry size
 * @e_shnum: Section header table entry count
 * @e_shstrndx: Section header string table index
 */
typedef struct elfn_ehdr
{
	unsigned char	e_ident[EI_NIDENT];
	uint64_t	e_entry;
	uint64_t	e_phoff;
	uint64_t	e_shoff;
	uint32_t	e_version;
	uint32_t	e_flags;
	uint16_t	e_type;
	uint16_t	e_machine;
	uint16_t	e_ehsize;
	uint16_t	e_phentsize;
	uint16_t	e_phnum;
	uint16_t	e_shentsize;
	uint16_t	e_shnum;
	uint16_t	e_shstrndx;
} ElfN_Ehdr;

/**
 * struct ElfN_Shdr - struct to represent 32/64bits section headers
 *
 * @sh_name: Offset to string in .shstrtab section
 * @sh_type: Identify type of section
 * @sh_flags: Attributes of a section
 * @sh_addr: Virtual address of the section
 * @sh_offset: Offset of the section
 * @sh_size: Size of the section
 * @sh_link: Section index of associated section
 * @sh_info: Extra information
 * @sh_addralign: Required alignment section
 * @sh_entsize: Size of each section
 */
typedef struct ElfN_Shdr
{
	uint32_t	sh_name;
	uint32_t	sh_type;
	uint64_t	sh_flags;
	uint64_t	sh_addr;
	uint64_t	sh_offset;
	uint64_t	sh_size;
	uint32_t	sh_link;
	uint32_t	sh_info;
	uint64_t	sh_addralign;
	uint64_t	sh_entsize;
} ElfN_Shdr;

/**
 * struct ElfN_Phdr - Internal Program Header struct
 *
 * @p_type:
 * @p_flags:
 * @p_offset:
 * @p_vaddr:
 * @p_paddr:
 * @p_filesz:
 * @p_memsz:
 * @p_align:
*/
typedef struct ElfN_Phdr
{
	uint32_t   p_type;
	uint32_t   p_flags;
	Elf64_Off  p_offset;
	Elf64_Addr p_vaddr;
	Elf64_Addr p_paddr;
	uint64_t   p_filesz;
	uint64_t   p_memsz;
	uint64_t   p_align;
} ElfN_Phdr;

#define width 35
#define GET_BYTE(field) get_byte(field, sizeof(field))
_Bool is_elf(unsigned char *magic);
int get_stat(char *filename);
FILE *parse_elf_header(ElfN_Ehdr *ehdr, int fd);
ElfClass get_class(char c);
void parse_32(ElfN_Ehdr *ehdr, FILE *file, unsigned char ei_data);
void parse_64(ElfN_Ehdr *ehdr, FILE *file, unsigned char ei_data);
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
void print_phoff(uint64_t phoff);
void print_shoff(uint64_t shoff);
char *get_strtab(FILE *file, ElfN_Ehdr *ehdr);
void get_sizeoff(ElfN_Shdr *shdr, ElfN_Ehdr *ehdr, FILE *file);
void print_sheader(ElfN_Shdr *shdr, ElfN_Ehdr *ehdr, char *sh_strtab);
void print_middle32(ElfN_Shdr *shdr, uint16_t shnum, char *sh_strtab);
void print_middle64(ElfN_Shdr *shdr, uint16_t shnum, char *sh_strtab);
void print_tail(void);
char *get_flags(uint64_t sh_flags);
char *get_type(uint64_t sh_type);
void copy_sheader_32(ElfN_Shdr *shdr, ElfN_Ehdr *ehdr, FILE *file);
void copy_sheader_64(ElfN_Shdr *shdr, ElfN_Ehdr *ehdr, FILE *file);
ElfN_Shdr *parse_sheaders(ElfN_Ehdr *ehdr, FILE *file);
uint64_t get_byte_big_endian(uint64_t, int);
uint64_t get_byte_host(uint64_t, int);
ElfN_Phdr *parse_pheader(ElfN_Ehdr *ehdr, FILE *file);
void copy_pheader_32(ElfN_Phdr *phdr, ElfN_Ehdr *ehdr, FILE *file);
void copy_pheader_64(ElfN_Phdr *phdr, ElfN_Ehdr *ehdr, FILE *file);
#endif /* READELF_H */
