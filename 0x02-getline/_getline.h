#ifndef GETLINE_H
#define GETLINE_H
#define READ_SIZE 1
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 256
char *_getline(const int fd);
int read_fd(int fd, char *buf);
#endif /* GETLINE_H */
