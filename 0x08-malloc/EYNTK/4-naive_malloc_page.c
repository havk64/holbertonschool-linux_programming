#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BRK_FAILED ((void *)-1)

void *naive_malloc_page(size_t size)
{
	static void *start_brk;
	static char *ptr;
	void *old_brk;
	size_t *header, chunk, hsize;
	int pagesize;

	if (start_brk == 0)
	{
		start_brk = sbrk(0);
		if (start_brk == BRK_FAILED)
			return (NULL);

		ptr = (char *)start_brk;
	}
	hsize = sizeof(size_t);
	chunk = size + hsize;
	pagesize = sysconf(_SC_PAGESIZE);
	if (pagesize < 0)
	{
		perror("sysconf error");
		return (NULL);
	}

	if ((ptr + chunk) > (char *)sbrk(0))
	{
		old_brk = sbrk(pagesize);
		printf("Old brk: %p\n", old_brk);
	}
	header = (size_t *)ptr;
	*header = chunk;
	ptr += chunk;
	return ((void *)(ptr - size));
}
