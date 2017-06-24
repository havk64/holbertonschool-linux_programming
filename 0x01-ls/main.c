#include "ls_header.h"

int main(int ac, char *av[])
{
	if (ac < 2)
	{
		open_dir(".");
	} else
		parse_opt(ac, av);

	return (0);
}
