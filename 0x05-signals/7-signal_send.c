#include "signals.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Argument vector
 *
 * Return: On success, EXIT_SUCCESS. On error, EXIT FAILURE
 */
int main(int argc, char *argv[])
{
	pid_t pid;

	if (argc != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	pid = atoi(argv[1]);

	if (kill(pid, SIGINT) < 0)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
