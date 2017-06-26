#include "ls_header.h"

/**
 * parse_opt - Parse the options to the command line
 * @max: max size of options
 * @av: command line arguments
 *
 * Return: On success: 0, On error, error code
 */
int parse_opt(int max, char **av)
{
	int i, opcount, stat, ft;
	char **oplist;
	Dlist *flist, *dlist;

	stat = ft = 0;
	dlist = flist = NULL;
	oplist = salloc(max);
	opcount = 0;
	for (i = 1; i < max; i++)
	{
		if (av[i][0] == '-')
		{
			oplist[opcount] = strcpalloc(av[i]);
			opcount++;
		} else
		{
			stat = check_dir(&dlist, &flist, av[i]);
		}
	}
	oplist[opcount] = NULL;
	if (flist != NULL)
	{
		print_list(flist);
		ft = 1;
		if (dlist != NULL)
			printf("\n");
	}
	if (stat != 0)
		ft = 1;
	list_dir(dlist, ft);
	free_list(dlist);
	free_list(flist);
	freemem(oplist, opcount);
	return (stat);
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
		(void)closedir(dirp);
		return (1);
	}
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
