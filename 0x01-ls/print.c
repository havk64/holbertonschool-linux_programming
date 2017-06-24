#include "ls_header.h"

/**
 * print_dir - lists a directory
 * @dir: pointer to a directory stream
 *
 * Return: Void
 */
void print_dir(DIR *dir)
{
	int count;
	struct dirent *rdir;

	count = 0;
	while ((rdir = readdir(dir)) != NULL)
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
}