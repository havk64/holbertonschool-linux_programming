#include "ls_header.h"

char f_type(mode_t mode)
{
	char c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '?';
	return (c);
}
