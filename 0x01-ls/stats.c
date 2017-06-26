#include "ls_header.h"

/**
 * f_type - Check the type of a file/directory
 * @mode: stat st_mode field
 *
 * Return: a character describing the type of the file/directory
 */
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

/**
 * f_perm - Check the permissions of a file/directory
 * @mode: stat st_mode field
 *
 * Return: a string describing the permissions of the file/directory
 */
char *f_perm(mode_t mode)
{
	char *p;

	p = malloc(9 * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);

	p[0] = (mode & S_IRUSR) ? 'r' : '-';
	p[1] = (mode & S_IWUSR) ? 'w' : '-';
	p[2] = (mode & S_IXUSR) ? 'x' : '-';
	p[3] = (mode & S_IRGRP) ? 'r' : '-';
	p[4] = (mode & S_IWGRP) ? 'w' : '-';
	p[5] = (mode & S_IXGRP) ? 'x' : '-';
	p[6] = (mode & S_IROTH) ? 'r' : '-';
	p[7] = (mode & S_IWOTH) ? 'w' : '-';
	p[8] = (mode & S_IXOTH) ? 'x' : '-';
	p[9] = 0;

	return (p);
}

/**
 * file_check - Check if file exists and is accessible
 * @path: the name of the file
 *
 * Return: On success: 0, On error: 1 or 2
 */
int file_check(char *path)
{
	struct stat buf;

	if (lstat(path, &buf) < 0)
	{
		switch (errno)
		{
			case 2:
				printf("hls: cannot access %s: No such file or directory\n", path);
				return (2);

			case 13:
				printf("hls: cannot access %s: Permission denied\n", path);
				return (1);

			default:
				printf("Whatever...%d\n", errno);
		}
		return (1);
	}
	if (f_type(buf.st_mode) == 'd')
		return (4);

	return (0);
}

/**
 * check_dir - Verify if file/dir exist and return information
 * @dlist: linked list of directories
 * @flist: linked list of files
 * @str: path to file/directory
 *
 * Return: integer with information about stats
 */
int check_dir(Dlist **dlist, Dlist **flist, char *str)
{
	int check, status;

	status = 0;
	check = file_check(str);
	if (check != 0)
	{
		if (check == 4)
		{
			if (add_node(dlist, str) == 1)
				status = 1;
		} else
			status = check;
	} else
	{
		if (add_node(flist, str) == 1)
			status = 1;
	}
	return (status);
}
