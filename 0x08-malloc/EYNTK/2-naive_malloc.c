#include "naive.h"

/**
 * naive_malloc - a naive malloc-like function, version 2
 * @size: the size to be allocated
 *
 * Return: On success, a void pointer to beginning of allocated space on memory
 * On failure, it returns NULL
 */
void *naive_malloc(size_t size)
{
	void *ptr;

	ptr = sbrk(size);
	if (ptr == BRK_FAILED)
	{
		perror("sbrk error");
		return (NULL);
	}
	return (ptr);
}
