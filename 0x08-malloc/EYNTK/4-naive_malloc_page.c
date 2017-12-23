#include "naive.h"

/**
 * naive_malloc_page - a naive malloc-like function
 * @size: the size to be allocated
 *
 * Return: On success, a void pointer to beginning of allocated space on memory
 * On failure, it returns NULL
 */
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
		perror("sysconf");
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
