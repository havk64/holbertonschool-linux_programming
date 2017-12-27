#include "naive.h"

void *getbrk(void *ptr)
{
	int i;
	char *h;

	printf("Before: %p\n", ptr);
	ptr = sbrk(10);
	printf("After: %p\n", ptr);
	h = sbrk(0);
	printf("New break(h): %p\n", (void *)h);
	for (i = 0; i < 26; i++)
		*(h + i) = 'a' + i;
	*(h + i) = '\0';
	return (sbrk(0));
}

/**
 * print_heap - print the heap info from a /prov/<pid>/maps file
 *
 * Return: On success, EXIT_SUCCESS. On failure, EXIT_FAILURE
 */
int print_heap(void)
{

	FILE *maps;
	char maps_path[32], *line, buf[bsize];
	pid_t PID;

	PID = getpid();
	printf("The heap of this process ");
	printf("as stated in the /proc/%d/maps file is:\n\n", PID);
	sprintf(maps_path, "/proc/%d/maps", PID);
	maps = fopen(maps_path, "r");
	if (maps == NULL)
	{
		perror("fopen");
	}
	else
		while ((line = fgets(buf, bsize, maps)))
			if (strstr(line, "[heap]"))
			{
				printf("%s", line);
				return (EXIT_SUCCESS);
			}
	return (EXIT_FAILURE);
}

/**
 * main - entry point
 *
 * Return: On succes, EXIT_SUCCESS. On failure, EXIT_FAILURE.
 */
int main(void)
{
	char *h;
	void *ptr;
	int n;

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

	n = print_heap();
	if (n != 0)
	{
		perror("print_heap");
		return (EXIT_FAILURE);
	}

	printf("\nTo confirm this info, open another terminal window and type:\n");
	printf("$ cat /proc/%d/maps\n", getpid());
	printf("...to see the whole memory map of this process\n");
	printf("(Press ENTER to quit)\n");
	getchar();
	return (EXIT_SUCCESS);
}
