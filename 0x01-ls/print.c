#include "ls_header.h"

/**
 * print_dir - lists a directory
 * @dir: pointer to a directory stream
 *
 * Return: Void
 */
void print_dir(DIR *dir, int mode)
{
	int count;
	struct dirent *rdir;
	char *end;

	end = (mode == 1) ? "\n" : "  ";
	count = 0;
	while ((rdir = readdir(dir)) != NULL)
	{
		if (count != 0)
			printf("%s", end);

		if (rdir->d_name[0] != '.')
		{
			printf("%s",
			       rdir->d_name);
			count++;
		}
	}
	printf("\n");
}

/**
 * list_dir - list directories
 * @list: linked list of directories to list
 * @stat: variable to check previous listing
 *
 * Return: Void
 */
void list_dir(Dlist *list, int stat, int mode)
{
	Dlist *node;

	node = list;
	while (node != NULL)
	{
		if (stat != 0 || node->next != NULL)
			printf("%s:\n", node->str);
		if (parse_dir(node->str, mode) != 0)
			printf("Ops...\n");
		if (node->next != NULL)
			printf("\n");
		node = node->next;
	}

}
