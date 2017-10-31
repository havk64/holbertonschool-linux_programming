# 0x09. x86 Assembly - libASM

System programming & Algorithm ― Linux programming

### Task 0 - Strlen

The file [0-strlen](0-strlen) has a copycat of the function `strlen(3)`, in
x86-64 Assembly

- Prototype when used in C: `size_t asm_strlen(const char *str)`;

```
$ cat 0-main.c
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  ""
#define S3  "\0"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    assert(strlen(S1) == asm_strlen(S1));
    assert(strlen(S2) == asm_strlen(S2));
    assert(strlen(S3) == asm_strlen(S3));

    printf("All good!\n");
    return (EXIT_SUCCESS);
}

$ make

$ ./0-strlen

All good!

```
