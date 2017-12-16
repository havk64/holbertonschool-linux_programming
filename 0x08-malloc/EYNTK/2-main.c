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
	printf("PID: %d\n", pid);
	printf("Starting break is %p\n", sbrk(0));

	for (i = 0; i < 10; i++)
	{
		str = naive_malloc(10);
		strcpy(str, "Holberton"); /* NULL terminated string */
		printf("%p: %s\n", (void *)str, str);
	}

	printf("Final break is %p\n", sbrk(0));

	status = prompt_mem_map(pid);
	return (status);
}
