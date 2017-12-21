#include "naive.h"

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
