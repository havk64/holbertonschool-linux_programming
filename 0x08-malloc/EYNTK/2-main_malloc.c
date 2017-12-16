#include "naive.h"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	char *str;
	int i;
	pid_t pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	printf("Starting break is %p\n", sbrk(0));

	for (i = 0; i < 10; i++)
	{
		str = malloc(10);
		strcpy(str, "Holberton");
		printf("%p: %s, ", (void *)str, str);
		printf("program break: %p\n", sbrk(0));

	}

	printf("Final break is %p\n", sbrk(0));
	return (EXIT_SUCCESS);
}
