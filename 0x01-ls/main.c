#include "ls_header.h"

/**
 * main - entry point
 * @ac: number of command line arguments
 * @av: array of strings representing command line arguments
 *
 * Return: On success 0, on error 1 or 2
 */
int main(int ac, char *av[])
{
	int EXIT_STATUS;

	EXIT_STATUS = 0;
	if (ac < 2)
	{
		open_dir(".");
	} else
		EXIT_STATUS = parse_opt(ac, av);

	return (EXIT_STATUS);
}
