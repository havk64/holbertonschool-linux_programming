#include "ls_header.h"

int main(int ac, char *av[])
{
	DIR *dirp;
	struct dirent *rdir;
	int count;

	if (ac < 2)
		av[1] = "./";

	/* Open directory stream */
	dirp = opendir(av[1]);
	if (dirp == NULL)
	{
		printf("ls: cannot access %s: No such file or directory\n", av[1]);
		return (2);

	}

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
