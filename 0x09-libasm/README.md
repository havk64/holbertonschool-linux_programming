# 0x09. x86 Assembly - libASM

System programming & Algorithm ― Linux programming

### Task 0 - Strlen

The file [0-strlen.asm](0-strlen.asm) has a copycat of the function `strlen(3)`, in
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

$ make 0-strlen

$ ./0-strlen

All good!

```

### Task 1 - strcmp

The file [1-strcmp.asm](1-strcmp.asm) has a copycat of the function `strcmp(3)`, in
X86-64 Assembly

- Prototype when called from C: `int asm_strcmp(const char *s1, const char *s2);`

```
$ cat 2-main.c 
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  ""
#define S3  "Holberton Socool"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    assert(strcmp(S1, S1) == asm_strcmp(S1, S1));
    assert(strcmp(S1, S2) == asm_strcmp(S1, S2));
    assert(strcmp(S1, S3) == asm_strcmp(S1, S3));

    printf("All good!\n");
    return (EXIT_SUCCESS);
}

$ make 1-strcmp

$ ./1-strcmp

All good!
```

### Task 2 - strncmp

The file [2-strncmp.asm](2-strncmp.asm) has a copycat of the function `strncmp[3]`, in
X86-64 Assembly

- Prototype when called from C: `int asm_strncmp(const char *s1, const char s2, 
size_t n);`

```
$ cat 2-main.c

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  ""
#define S3  "Holberton Socool"
#define S4  "H"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strncmp(S1, S3, 1) == asm_strncmp(S1, S3, 1));
	assert(strncmp(S1, S3, 11) == asm_strncmp(S1, S3, 11));
	assert(strncmp(S1, S3, 15) == asm_strncmp(S1, S3, 15));
	assert(strncmp(S2, S1, 10) == asm_strncmp(S2, S1, 10));
	assert(strncmp(S2, S4, 2) == asm_strncmp(S2, S4, 2));
	assert(strncmp(S1, S2, 1) == asm_strncmp(S1, S2, 1));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}

$ make

$ ./2-strncmp

All good!
```

### Task 3 - strchr

The file [3-strchr.asm](3-strchr.asm) has a copycat of the function `strchr[3]` in
X86-64 Assembly

- Prototype when called from C: `char *asm_strchr(const char *s, int c);`

```
$ cat 3-main.c

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define C1  'n'
#define C2  'S'
#define C3  's'

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strchr(S1, C1) == asm_strchr(S1, C1));
	assert(strchr(S1, C2) == asm_strchr(S1, C2));
	assert(strchr(S1, C3) == asm_strchr(S1, C3));
	assert(strchr(S1, 0) == asm_strchr(S1, 0));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}

$ make 3-strchr

$ ./3-strchr

All good!
```
