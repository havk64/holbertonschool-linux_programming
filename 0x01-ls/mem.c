#include "ls_header.h"

/**
 * free_list - deallocate a linked list
 * @list: element of a linked list
 *
 * Return: Void
 */
void free_list(Dlist *list)
{
	Dlist *node;
	Dlist *tmp;

	node = list;
	while (node != NULL)
	{
		free(node->str);
		tmp = node->next;
		free(node);
		node = tmp;
	}
}
