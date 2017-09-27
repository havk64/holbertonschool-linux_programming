#include <unistd.h>
#include <stdio.h>
#define BRK_FAILED ((void *)-1)

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
