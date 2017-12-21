#ifndef NAIVE_H
#define NAIVE_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/time.h>
#define BRK_FAILED ((void *)-1)
#define bsize 128
int print_mem_map(void);
void set_mode(int want_key);
int get_key(int no_timeout);
int prompt_mem_map(pid_t pid);
void *naive_malloc(size_t size);
void *naive_malloc_header(size_t size);
void *naive_malloc_page(size_t size);
void *naive_malloc_extend(size_t size);
#define BRK_FAILED ((void *)-1)
#define PAGESIZE (1 << 12)
#endif /*NAIVE_H */
