# Hack the Virtual Memory

### Exercise 1 - Hack the Heap

Using `/proc` virtual file system to find and modify an ASCII string
contained inside the virtual memory of a running process.

- Target process:

```
$ cat loop.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char *s;
	unsigned long int i;
	pid_t pid;

	pid = getpid();
	s = strdup("Holberton");
	if (s == NULL)
	{
		fprintf(stderr, "Can't allocate mem with malloc\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (s)
	{
		printf("PID: %d, [%lu] %s (%p)\n", pid, i, s, (void *)s);
		sleep(1);
		i++;
	}
	return (EXIT_SUCCESS);
}
```

- Simple Program to overwrite the string "Holberton" of the above running program:

```
$ cat write_heap.c
#include "lcap.h"

int main(int ac, char *argv[])
{
	int n, fd, mem;
	char s[64];

	if (ac < 3)
	{
		printf("Usage: ./%s <pid> <offset>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	sprintf(s, "/proc/%s/mem", argv[1]);

	fd = open(s, O_RDWR);
	if (fd < 0)
		perror("Error opening file");

	mem = atoi(argv[2]);
	lseek(fd, mem, SEEK_SET);
	n = write(fd, "Alexandro", 10);
	if (n == 10)
		printf("Hacked!\n");

	close(fd);
	return (EXIT_SUCCESS);
}
```

To be able to modify the heap of the target program we need to call it using sudo or
better we can just Linux [Capabilities](https://linux.die.net/man/7/capabilities)
to give just the access needed that in this case is `CAP_SYS_PTRACE` with the 
following command:

```
$ sudo setcap cap_sys_ptrace <name_of_the_program>
```

But the Makefile already has a rule to do this, so we just need:

```
$ make
$ ./loop
PID: 1234 [0] Holberton (0xcc0010)
PID: 1234 [1] Holberton (0xcc0010)
...
```

And in another terminal:

```
$ ./hack_heap 1234 $((0xcc0010))
```

Back to first terminal the output should be:

```
PID: 1234 [0] Holberton (0xcc0010)
PID: 1234 [1] Holberton (0xcc0010)
PID: 1234 [2] Holberton (0xcc0010)
PID: 1234 [3] Alexandro (0xcc0010) # <= it has changed from here...
PID: 1234 [4] Alexandro (0xcc0010)
PID: 1234 [1] Holberton (0xcc0010)
```

- A more elaborated/automated program to overwrite the heap of the target program
can be found in the file [search_replace.c](search_replace.c) which output would
be as follows:

```
$ make

$ ./search_replace 12345 Holberton Alexandro
[*] maps: /proc/12345/maps
[*] mem: /proc/12345/mem
[*] Found [heap]:
    pathname = [heap]
    adressesses = 022b2000-022d3000
    permissions = rw-p
    offset = 00000000
    inode = 0
    Addr start [022b2000] | end [022d3000]
[*] Found 'Holberton' at 10
[*] Writing 'Alexandro' at 0x22b2010
```
