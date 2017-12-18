#include "naive.h"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	char *str;
	int i, status;
	pid_t pid;

	pid = getpid();
	printf("Starting break is %p\n", sbrk(0));

	for (i = 0; i < 10; i++)
	{
		void *chunk;

		str = naive_malloc_header(10);
		strcpy(str, "Holberton");
		printf("%p: %s, ", (void *)str, str);
		chunk = (void *)(str - sizeof(size_t));
		printf("chunk starting at address %p, ", (void *)chunk);
		printf("chunk size is %lu\n", *((size_t *)chunk));
	}

	printf("Final break is %p\n", sbrk(0));
	status = prompt_mem_map(pid);
	return (status);
}
