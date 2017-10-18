#ifndef LIBASM_H
#define LIBASM_H
#include <sys/types.h>
size_t asm_strlen(const char *str);
int asm_strcmp(const char *s1, const char *s2);
int asm_strncmp(const char *s1, const char *s2, size_t n);
char *asm_strchr(const char *s, int c);
#endif /* LIBASM_H */
