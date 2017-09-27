#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BRK_FAILED ((void *)-1)
#define PAGESIZE (1 << 12)
#define MSIZE 8
#define ALIGN(size) ((size + (MSIZE - 1)) & -MSIZE)

void *bootstrap(size_t *unused, size_t *header)
{
	void *brk;

	brk = sbrk(PAGESIZE);
	if (brk == BRK_FAILED)
		return (NULL);

	*unused = PAGESIZE;
	header = (size_t *)brk;
	*header = *unused;
	return (brk);
}

void *naive_malloc_align(size_t size)
{
	static void *start_brk;
	static size_t counter;
	char *ptr, *old_brk;
	size_t i, *header, chunk, hsize, unused;

	counter += 1;
	start_brk = (start_brk == 0) ? bootstrap(&unused, header = NULL) :
		start_brk;
	hsize = sizeof(size_t);
	chunk = ALIGN(size) + hsize;

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

	if (unused <= chunk)
	{
		old_brk = sbrk(PAGESIZE);
		unused += PAGESIZE;
		(void)(old_brk);
	}
	header = (size_t *)ptr;
	*header = unused - chunk;
	return ((void *)(ptr - (chunk - hsize)));
}
