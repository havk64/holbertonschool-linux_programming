#ifndef READELF_H
#define READELF_H
#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <unistd.h>
void check(int, char*);
int is_elf(char *magic);
int stat_it(char *filename);
#endif /* READELF_H */
