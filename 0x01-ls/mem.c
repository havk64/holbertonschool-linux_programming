#include "ls_header.h"

/**
 * freemem - free an array of strings
 * @s: the array to be freed
 * @len: the length of the array
 *
 * Return: void
 */
void freemem(char **s, int len)
{
	int i;

	for (i = 0; i < len; i++)
		free(s[i]);
	free(s);
}

/**
 * salloc - allocate memory to an array of strings
 * @size: the array's size
 *
 * Return: On success: a pointer to the beggining of newly allocated array
 * On error: Log the error to stderr
 */
char **salloc(int size)
{
	char **s;

	s = malloc(size * sizeof(char *));
	if (s == NULL)
		perror("malloc error: ");
	return (s);
}

char *strcpalloc(char *src, int size)
{
	char *dest;

	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		perror("malloc error: ");
	_strcpy(dest, src);
	return (dest);
}

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
	return (0);
}
