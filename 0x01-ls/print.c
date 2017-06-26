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

/**
 * list_dir - list directories
 * @list: linked list of directories to list
 * @stat: variable to check previous listing
 *
 * Return: Void
 */
void list_dir(Dlist *list, int stat)
{
	Dlist *node;

	node = list;
	while (node != NULL)
	{
		if (stat != 0 || node->next != NULL)
			printf("%s:\n", node->str);
		if (parse_dir(node->str) != 0)
			printf("Ops...\n");
		if (node->next != NULL)
			printf("\n");
		node = node->next;
	}

}
