#include "ls_header.h"

/**
 * parse_opt - Parse the options to the command line
 * @max: max size of options
 * @av: command line arguments
 *
 * Return: void
 */
void parse_opt(int max, char **av)
{
	int i, opcount, fcount, avlen;
	char **oplist, **flist;

	oplist = salloc(max);
	flist = salloc(max);
	opcount = 0;
	fcount = 0;
	for (i = 1; i < max; i++)
	{
		avlen = (_strlen(av[i]) + 1);
		if (av[i][0] == '-')
		{
			oplist[opcount] = strcpalloc(av[i], avlen);
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
	for (i = 0; i < opcount; i++)
		printf("Options: %s\n", oplist[i]);
	freemem(oplist, opcount);
	for (i = 0; i < fcount; i++)
		printf("Files: %s\n", flist[i]);
	freemem(flist, fcount);
}

/**
 * parse_dir - Check if file or directory
 * @src: pointer to a array of strings
 * @fcount: counter for files, excluding directories
 * @len: the length of the file/directory name
 *
 * Return: On success 0, On error 1
 */
int parse_dir(char **src, int fcount, char *av, int len)
{

	DIR *dirp;

	dirp = opendir(av);
	if (dirp == NULL)
	{
		src[fcount] = strcpalloc(av, len);
		(void)closedir(dirp);
		return (1);
	}
	printf("%s is a directory\n", av);
	print_dir(dirp);
	(void)(closedir(dirp));
	return (0);
}

