#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BRK_FAILED ((void *)-1)

void *bootstrap(size_t *unused, size_t *header, int pagesize)
{
	void *brk;

	brk = sbrk(pagesize);
	if (brk == BRK_FAILED)
		return (NULL);

	*unused = pagesize;
	header = (size_t *)brk;
	*header = *unused;
	return (brk);
}

void *naive_malloc_extend(size_t size)
{
	static void *start_brk;
	static size_t counter;
	char *ptr, *old_brk;
	size_t i, *header, chunk, hsize, unused;
	int pagesize;

	counter += 1;
	pagesize = sysconf(_SC_PAGESIZE);
	if (pagesize < 0)
	{
		perror("sysconf error");
		return (NULL);
	}
	start_brk = (start_brk == 0) ? bootstrap(&unused, header = NULL, pagesize) :
		start_brk;
	hsize = sizeof(size_t);
	chunk = size + hsize;

	ptr = (char *)start_brk;
	for (i = 0; i < counter; i++)
	{
		header = (size_t *)ptr;
		if (i == (counter - 1))
		{
			unused = *header;
			*header = chunk;
		}
		ptr += *header;
	}

	if (unused > chunk)
	{
		old_brk = sbrk(pagesize);
		unused += pagesize;
		(void)(old_brk);
	}
	header = (size_t *)ptr;
	*header = unused - chunk;
	return ((void *)(ptr - size));
}
