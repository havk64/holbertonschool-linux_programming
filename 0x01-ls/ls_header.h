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
#include <errno.h>

/**
 * struct Dlist - Directory linked list
 * @str: the path to dir/file
 * @next: pointer to next element
 */
typedef struct Dlist
{
	char *str;
	struct Dlist *next;
} Dlist;

size_t _strlen(char *s);
char *string_concat(char *s1, char *s2);
char f_type(mode_t mode);
char *f_perm(mode_t mode);
char *_strcpy(char *dest, char *src);
int parse_opt(int max, char **av);
int parse_dir(char *av, int mode);
int file_check(char *path);
void print_dir(DIR *dir, int mode);
int open_dir(char *name);
int add_node(Dlist **list, char *str);
void free_list(Dlist *list);
void print_list(Dlist *list, int mode);
char *alloclist(char *str);
int check_dir(Dlist **dlist, Dlist **flist, char *str);
void list_dir(Dlist *list, int stat, int mode);
int list_size(Dlist *list);
void print_long(char *str);
#endif /* LS_HEADER_H */
