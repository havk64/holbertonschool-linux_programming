#include "naive.h"

/**
 * naive_malloc_align - a naive malloc-like function, version 6
 * @size: the size to be allocated
 *
 * Return: On success, a void pointer to beginning of allocated space on memory
 * On failure, it returns NULL
 */
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
