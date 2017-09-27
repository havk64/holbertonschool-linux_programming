#include <unistd.h>
#include <stdio.h>

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
