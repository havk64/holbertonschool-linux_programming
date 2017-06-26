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

/**
 * alloclist - allocate and copy a string to a str field of a linked list
 * @str: the string to be copied
 *
 * Return: On Success, pointer to the string, On error: NULL
 */
char *alloclist(char *str)
{
	int i, len;
	char *s;

	len = 0;
	while (str[len])
		len++;

	s = malloc(sizeof(s) * len + 1);
	if (s == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		s[i] = str[i];
	s[i] = str[i];

	return (s);
}

/**
 * print_list - prints a linked list
 * @list: list to be printed
 *
 * Return: Void
 */
void print_list(Dlist *list)
{
	Dlist *node;

	node = list;
	while (node != NULL)
	{
		printf("%s", node->str);
		if (node->next != NULL)
			printf("  ");
		node = node->next;
	}
	printf("\n");
}

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
