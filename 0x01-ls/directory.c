#include "ls_header.h"

/**
 * parse_opt - Parse the options to the command line
 * @max: max size of options
 * @av: command line arguments
 *
 * Return: void
 */
int parse_opt(int max, char **av)
{
	int i, opcount, fcount, avlen;
	char **oplist, **flist;
	int EXIT_STATUS = 0;

	oplist = salloc(max);
	flist = salloc(max);
	opcount = 0;
	fcount = 0;
	for (i = 1; i < max; i++)
	{
		if (av[i][0] == '-')
		{
			oplist[opcount] = strcpalloc(av[i]);
			opcount++;
		}
		else
		{
			if (parse_dir(flist, fcount, av[i], avlen) == 1)
				fcount++;
		}
	}
	oplist[opcount] = NULL;
	flist[fcount] = NULL;
	for (i = 0; i < fcount; i++)
	{
		if (file_check(flist[i]) != 0)
		{
			EXIT_STATUS = 2;
		}
	}

	freemem(oplist, opcount);
	freemem(flist, fcount);
	return (EXIT_STATUS);
}

/**
 * parse_dir - Check if file or directory
 * @av: the name of the file/directory
 *
 * Return: On success 0, On error 1
 */
int parse_dir(char *av)
{
	DIR *dirp;

	dirp = opendir(av);
	if (dirp == NULL)
	{
		src[fcount] = strcpalloc(av, len);
		(void)closedir(dirp);
		return (1);
	}
	printf("%s:\n", av);
	print_dir(dirp);
	(void)(closedir(dirp));
	return (0);
}

/**
 * open_dir - Open a directory stream
 * @name: name of the directory
 *
 * Return: On success return 0
 * On error return 1 or 2
 */
int open_dir(char *name)
{
	DIR *dirp;
	int count;
	struct dirent *rdir;

	/* Open directory stream */
	dirp = opendir(name);
	if (dirp == NULL)
		return (2);

	count = 0;
	/* Read Directory stream */
	while ((rdir = readdir(dirp)) != NULL)
	{

		if (count != 0)
			printf("  ");

		if (rdir->d_name[0] != '.')
		{
			printf("%s",
			       rdir->d_name);
			count++;
		}

	}
	printf("\n");

	return (closedir(dirp));
}

