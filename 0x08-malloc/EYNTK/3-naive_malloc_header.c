#include "naive.h"

/**
 * naive_malloc_header - naive malloc, version 3
 * @size: the size of block memory to be allocated
 *
 * Return: always void.
 */
void *naive_malloc_header(size_t size)
{
	char *ptr;
	size_t *header, hsize, chunk;

	hsize = sizeof(size_t);
	chunk = size + hsize;

	ptr = sbrk(chunk);
	if (ptr == (void *)-1)
	{
		perror("sbkr error");
		return (NULL);
	}

	header = (size_t *)ptr;
	*header = chunk;
	return ((void *)(ptr + hsize));
}
