#ifndef GETLINE_H
#define GETLINE_H
#define READ_SIZE 1
#define BUF_SIZE 256
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
char *_getline(const int fd);
int read_fd(int fd, char **buf);
void *_realloc(char *ptr, size_t size);
#endif /* GETLINE_H */
