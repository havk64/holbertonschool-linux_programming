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
	int i, c, status = EXIT_SUCCESS;
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
	fflush(stdout);
	while (1)
	{
		set_mode(1);

		c = get_key(1);
		if (c == 'y' || c == 'Y')
		{
			printf("\n");
			status = print_mem_map();
			break;
		}

		if (c == 'n' || c == 'N')
		{
			printf("\nDone!\n");
			break;
		}
		printf("Yes or no? (y/n)\n");
	}
	return (status);
}
