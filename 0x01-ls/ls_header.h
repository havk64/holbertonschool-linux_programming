#ifndef LS_HEADER_H
#define LS_HEADER_H
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
int _putchar(char c);
size_t _strlen(char *s);
char *string_concat(char *s1, char *s2);
char f_type(mode_t mode);
char *f_perm(mode_t mode);
char *_strcpy(char *dest, char *src);
void freemem(char **s, int len);
char **salloc(int size);
char *strcpalloc(char *src, int size);
int parse_opt(int max, char **av);
int parse_dir(char **src, int fcount, char *av, int len);
int file_check(char *path);
void print_dir(DIR *dir);
int open_directory(char *name);
int open_dir(char *name);
#endif /* LS_HEADER_H */
