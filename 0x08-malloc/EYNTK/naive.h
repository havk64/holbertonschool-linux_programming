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
#endif /*NAIVE_H */
