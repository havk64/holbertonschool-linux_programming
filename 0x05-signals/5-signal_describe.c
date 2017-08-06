#include "signals.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Argument vector
 *
 * Return: Exit status
 */
int main(int argc, char *argv[])
{
	int signum;
	char *info;

	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	signum = atoi(argv[1]);
	info = strsignal(signum);
	printf("%d: %s\n", signum, info);
	return (EXIT_SUCCESS);
}
