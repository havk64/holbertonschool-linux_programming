#include "ls_header.h"

char f_type(mode_t mode)
{
	char c;

	switch (mode & S_IFMT)
	{
	case S_IFBLK:
		c = 'b';
		break;
	case S_IFCHR:
		c = 'c';
		break;
	case S_IFDIR:
		c = 'd';
		break;
	case S_IFIFO:
		c = 'p';
		break;
	case S_IFLNK:
		c = 'l';
		break;
	case S_IFREG:
		c = '-';
		break;
	case S_IFSOCK:
		c = 's';
		break;
	default:
		c = '?';
		break;
	}
	return (c);
}
