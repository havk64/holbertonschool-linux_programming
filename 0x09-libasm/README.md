# 0x09. x86 Assembly - libASM

System programming & Algorithm ― Linux programming

## Development environment

The routines/examples were tested/assembled in the following environment:
- Linux, Ubuntu 14.04LTS
- GCC 4.8.8
- Nasm 2.10.09
- GNU Assembler (as) 2.24 X86_64
- GNU Make 3.81

### Task 0 - strlen

The file [0-strlen.asm](0-strlen.asm) has a copycat of the function `strlen(3)`, in
x86-64 Assembly

- Prototype for C: `size_t asm_strlen(const char *str)`;

```
$ make 0-strlen

$ ./0-strlen
All good!

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
```

### Task 1 - strcmp

The file [1-strcmp.asm](1-strcmp.asm) has a copycat of the function `strcmp(3)`, in
X86-64 Assembly

- Prototype for C: `int asm_strcmp(const char *s1, const char *s2);`

```
$ make 1-strcmp

$ ./1-strcmp
All good!

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
```

### Task 2 - strncmp

The file [2-strncmp.asm](2-strncmp.asm) has a copycat of the function `strncmp[3]`, in
X86-64 Assembly

- Prototype for C: `int asm_strncmp(const char *s1, const char s2, 
size_t n);`

```
$ make

$ ./2-strncmp
All good!

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
```

### Task 3 - strchr

The file [3-strchr.asm](3-strchr.asm) has a copycat of the function `strchr[3]` in
X86-64 Assembly

- Prototype for C: `char *asm_strchr(const char *s, int c);`

```
$ make 3-strchr

$ ./3-strchr
All good!

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
```

### Task 4 - strstr

The file [4-strstr.asm](4-strstr.asm) has a copycat of `strstr[3]` in X86-64 Assembly

- Prototype for C: `char *asm_strstr(const char *s, char *sub);`

```
$ make 4-strstr

$ ./4-strstr
All good!

$ cat 4-main.c
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School Socool"
#define S2  "School"
#define S3  "Socool"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strstr(S1, S2) == asm_strstr(S1, S2));
	assert(strstr(S1, S3) == asm_strstr(S1, S3));
	assert(strstr(S1, S1) == asm_strstr(S1, S1));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
```

### Task 5 - memcpy

The file [5-memcpy.asm](5-memcpy.asm) has a copycat of `memcpy[3]` in X86-64 Assembly

- Prototype for C: `void *asm_memcpy(void *dest, const void *src, size_t n);`

```
$ make 5-memcpy

$ ./5-memcpy
......... School
H........ School
Ho....... School
Hol...... School
Holb..... School
Holbe.... School
Holber... School
Holbert.. School
Holberto. School
Holberton School
All good!

$ cat 5-main.c
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	int i;
	char *src = strdup("Holberton");

	for (i = 0; i <= 9; i++)
	{
		char *dest = strdup("......... School");

		assert(asm_memcpy(dest, src, i) == dest);
		printf("%s\n", dest);
		free(dest);
	}
	free(src);
	printf("All good!\n");
	return (EXIT_SUCCESS);
}
```

### Task 6 - putc

The file [100-putc.asm](100-putc.asm) has a function that prints one character at
a time.

- Prototype for C: `size_t asm_putc(int c);`

```
$ make 100-putc

$ ./100-putc
Hbtn
All good!

$ cat 100-main.c
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(asm_putc('H') == 1);
	assert(asm_putc('b') == 1);
	assert(asm_putc('t') == 1);
	assert(asm_putc('n') == 1);
	assert(asm_putc('\n') == 1);

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
```

### Task 7 - puts

The file [101-puts.asm](101-puts.asm) has a function that prints a string of 
characters to the standard output, in x86-64 Assembly

- Prototype for C: `size_t asm_puts(const char *str);`

```
$ make ./101-puts

$ ./101-puts 
Holberton School
All good!

$ cat 101-main.c
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(asm_puts("H") == 1);
	assert(asm_puts("olberton") == 8);
	assert(asm_puts(" School\n") == 8);

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
```

### Task 8 - strcasecmp

The file [102-strcasecmp.asm](102-strcasecmp.asm) has a copycat of `strcasecmp(3)`
function in X86-64 Assembly

- Prototype for C: `int asm_strcasecmp(const char *s1, const char *s2);`

```
$ make 102-strcasecmp

$ ./102-strcasecmp
All good!

$ cat 102-main.c
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  "HOLBERTON SCHOOL"
#define S3  "Holberton SchooL"
#define S4  "holberton socool"
#define S5  "@ABCDEFGHIJKLMNOPQRSTXYZ[]"
#define S6  "@abcdefghijklmnopqrstxyz[]"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strcasecmp(S1, S1) == asm_strcasecmp(S1, S1));
	assert(strcasecmp(S1, S2) == asm_strcasecmp(S1, S2));
	assert(strcasecmp(S1, S3) == asm_strcasecmp(S1, S3));
	assert(strcasecmp(S1, S4) == asm_strcasecmp(S1, S4));
	assert(strcasecmp(S4, S1) == asm_strcasecmp(S4, S1));
	assert(strcasecmp(S5, S6) == asm_strcasecmp(S5, S6));
	assert(strcasecmp(S6, S6) == asm_strcasecmp(S6, S6));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
```

### Task 9 - strncasecmp

The file [103-strncasecmp.asm](103-strncasecmp.asm) has a copycat of `strncasecmp(3)`
function in X86-64 Assembly

- Prototype for C: `int asm_strncasecmp(const char *s1, const char *s2, size_t n);`

```
$ make 103-strncasecmp

$ ./103-strncasecmp
All good!

$ cat 103-main.c
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  "HOLBERTON SCHOOL"
#define S3  "Holberton SchooL"
#define S4  "holberton socool"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strncasecmp(S1, S3, 1) == asm_strncasecmp(S1, S3, 1));
	assert(strncasecmp(S1, S2, 11) == asm_strncasecmp(S1, S2, 11));
	assert(strncasecmp(S1, S3, 11) == asm_strncasecmp(S1, S3, 11));
	assert(strncasecmp(S1, S2, 16) == asm_strncasecmp(S1, S2, 16));
	assert(strncasecmp(S1, S3, 16) == asm_strncasecmp(S1, S3, 16));
	assert(strncasecmp(S1, S4, 11) == asm_strncasecmp(S1, S4, 11));
	assert(strncasecmp(S1, S4, 16) == asm_strncasecmp(S1, S4, 16));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
```

### Task 10 - strspn

The file [104-strspn.asm](104-strspn.asm) has a copycat of `strspn(3)` in 
X86-64 Assembly

- Prototype for C: `size_t asm_strspn(const char *s, const char *accept);`

```
$ make 104-strspn

$ ./104-strspn
All good!

$ cat 104-main.c
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton"
#define S2  "holberton"
#define S3  "HOLBERTON"

#define A1  "abcdefghijklmnopqrstuvwxyz"
#define A2  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strspn(S2, A1) == asm_strspn(S2, A1));
	assert(strspn(S2, A2) == asm_strspn(S2, A2));
	assert(strspn(S3, A1) == asm_strspn(S3, A1));
	assert(strspn(S3, A2) == asm_strspn(S3, A2));
	assert(strspn(S1, A1) == asm_strspn(S1, A1));
	assert(strspn(S1, A2) == asm_strspn(S1, A2));
	assert(strspn(S1, A1 A2) == asm_strspn(S1, A1 A2));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
```

### Task 11 - strcspn

The file [105-strcspn.asm](105-strcspn.asm) has a copycat of `strcspn(3)` function
in X86-64 Assembly

- Prototype for C: `size_t asm_strcspn(const char *s, const char *reject);`

```
$ make 105-strcspn

$ ./105-strcspn
All good!

$ cat 105-main.c
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton"
#define S2  "holberton"
#define S3  "HOLBERTON"

#define A1  "abcdefghijklmnopqrstuvwxyz"
#define A2  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strcspn(S2, A1) == asm_strcspn(S2, A1));
	assert(strcspn(S2, A2) == asm_strcspn(S2, A2));
	assert(strcspn(S3, A1) == asm_strcspn(S3, A1));
	assert(strcspn(S3, A2) == asm_strcspn(S3, A2));
	assert(strcspn(S1, A1) == asm_strcspn(S1, A1));
	assert(strcspn(S1, A2) == asm_strcspn(S1, A2));
	assert(strcspn(S1, A1 A2) == asm_strcspn(S1, A1 A2));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
```

### Task 12 - strpbrk

The file [106-strpbrk.asm](106-strpbrk.asm) has a copycat of `strpbrk(3)` function
in X86-64 Assembly.

- Prototype for C: `char *asm_strpbrk(const char *s, const char *accept);`

```
$ make 106-strpbrk

$ ./106-strpbrk
All good!

$ cat 106-main.c
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton"
#define S2  "holberton"
#define S3  "HOLBERTON"

#define A1  "abcdefghijklmnopqrstuvwxyz"
#define A2  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define A3  "()[]{}<>n"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strpbrk(S2, A1) == asm_strpbrk(S2, A1));
	assert(strpbrk(S2, A2) == asm_strpbrk(S2, A2));
	assert(strpbrk(S3, A1) == asm_strpbrk(S3, A1));
	assert(strpbrk(S3, A2) == asm_strpbrk(S3, A2));
	assert(strpbrk(S1, A3) == asm_strpbrk(S1, A3));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
```

### Task 13 - puti

The file [1000-puti.asm](1000-puti.asm) has a function that prints a signed
integer on the standard output, in x86-64 Assembly.

- Prototype for C: `size_t asm_puti(int n);`

```
$ make 1000-puti

$ ./1000-puti
98
-1
-1024
2147483647
-2147483648
0

$ cat 1000-main.c
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "libasm.h"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(asm_puti(98) == 2);
	printf("\n");
	assert(asm_puti(-1) == 2);
	printf("\n");
	assert(asm_puti(-1024) == 5);
	printf("\n");
	assert(asm_puti(INT_MAX) == 10);
	printf("\n");
	assert(asm_puti(INT_MIN) == 11);
	printf("\n");
	assert(asm_puti(0) == 1);
	printf("\n");
	return (EXIT_SUCCESS);
}
```

### Task 14 - puti_base

The file [1001-puti_base.asm](1001-puti_base.asm) has a function that prints
a signed integer in a given base on the standard output, in x86-64 Assembly

- Prototype for C: `size_t asm_puti_base(int n, const char *base);`

```
$ make 10001-puti_base

$ ./1001-puti_base
98
-1
1f93e
10111110110011011100
lfqqofh
-80000000
0

All good!

$ cat 1001-puti_base
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "libasm.h"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(asm_puti_base(98, "0123456789") == 2);
	printf("\n");
	assert(asm_puti_base(-1, "0123456789") == 2);
	printf("\n");
	assert(asm_puti_base(129342, "0123456789abcdef") == 5);
	printf("\n");
	assert(asm_puti_base(781532, "01") == 20);
	printf("\n");
	assert(asm_puti_base(INT_MAX, "abcdefghijklmnopqrstwxyz") == 7);
	printf("\n");
	assert(asm_puti_base(INT_MIN, "0123456789ABCDEF") == 9);
	printf("\n");
	assert(asm_puti_base(0, "01234567") == 1);
	printf("\n");
	printf("\nAll good!\n");
	return (EXIT_SUCCESS);
}
```
