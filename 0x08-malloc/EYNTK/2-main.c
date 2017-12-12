#include "naive.h"

void *naive_malloc(size_t size);

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	char *str;
	int i;

	printf("PID: %d\n", getpid());
	printf("Starting break is %p\n", sbrk(0));

	for (i = 0; i < 10; i++)
	{
		str = naive_malloc(10);
		strcpy(str, "Holberton");
		str[9] = '\0';
		printf("%p: %s\n", (void *)str, str);
	}

	printf("Final break is %p\n", sbrk(0));
	/*
	 * Check the output of
	 * $ cat proc/{pid}/maps
	 * ...to inspect the Heap
	 */
	getchar();
	return (EXIT_SUCCESS);
}
