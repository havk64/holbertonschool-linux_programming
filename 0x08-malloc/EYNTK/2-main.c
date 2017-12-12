#include "naive.h"

void *naive_malloc(size_t size);

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	char *str, x;
	int i, status = EXIT_SUCCESS;
	pid_t pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	printf("Starting break is %p\n", sbrk(0));

	for (i = 0; i < 10; i++)
	{
		str = naive_malloc(10);
		strcpy(str, "Holberton"); /* NULL terminated string */
		printf("%p: %s\n", (void *)str, str);
	}

	printf("Final break is %p\n", sbrk(0));
	printf("Print content of /proc/%d/maps? (y/n)\n",
	       pid);
	x = getchar();
	if (x == 'y')
		status = print_mem_map();

	return (status);
}
