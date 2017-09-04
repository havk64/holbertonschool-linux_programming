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
void check(int, char*);
int is_elf(char *magic);
int get_stat(char *filename);
#endif /* READELF_H */
