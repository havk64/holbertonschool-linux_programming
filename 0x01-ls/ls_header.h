#ifndef LS_HEADER_H
#define LS_HEADER_H
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int _putchar(char c);
int _strlen(char *s);
char f_type(mode_t mode);
char *string_concat(char *s1, char *s2);
#endif /* LS_HEADER_H */
