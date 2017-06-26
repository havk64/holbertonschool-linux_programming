#include "ls_header.h"

/**
 * add_node - add a node to the end of a linked list
 * @list: pointer to a linked list
 * @str: string to be added
 *
 * Return: On success: 0, On error: 1
 */
int add_node(Dlist **list, char *str)
{
	char *s;
	Dlist *p, *node;

	node = malloc(sizeof(Dlist));
	if (node == NULL)
		return (1);

	s = alloclist(str);
	if (s == NULL)
		return (1);

	node->str = s;
	node->next = NULL;
	p = *list;
	if (*list == NULL)
	{
		*list = node;
	} else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = node;
	}
	return (0);
}
