#ifndef READELF_H
#define READELF_H
#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <unistd.h>
typedef enum
{
	ELF32, ELF64
} ElfClass;
#define width 40
int is_elf(unsigned char *magic);
int get_stat(char *filename);
void parse(int fd);
ElfClass get_class(char c);
void print_identity(unsigned char *header);
#endif /* READELF_H */
