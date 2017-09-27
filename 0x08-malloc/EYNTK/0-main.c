#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define BRK_FAILED ((void *)-1)

/**
 * main - entry point
 *
 * Return: On succes, EXIT_SUCCESS. On failure, EXIT_FAILURE.
 */
int main(void)
{
	char *h;
	void *ptr;

	/* Check program break */
	ptr = sbrk(0);
	if (ptr == BRK_FAILED)
	{
		perror("sbrk error");
		return (EXIT_FAILURE);
	}

	printf("Program break is: %p\n", ptr);
	/* 'h' variable now gets the old program break address */
	h = sbrk(1);
	/* Get new program break, after the increment. */
	ptr = sbrk(0);
	printf("Break now is: %p\n", ptr);
	*h = 'H';
	printf("Value at this address is: '%c'\n", *h);
	printf("\nOpen another terminal window and type:\n");
	printf("$ cat /proc/%d/maps\n", getpid());
	printf("...to inspect the Heap\n");
	getchar();
	return (EXIT_SUCCESS);
}
