#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "signals.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	pid_t pid;

	pid = getpid();
	if (pid_exist(pid))
	{
		printf("My process exists\n");
	}
	else
	{
		printf("My process does not exist\n");
	}
	return (EXIT_SUCCESS);
}
