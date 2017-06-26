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
 * @mode: a number representing the options
 *
 * Return: Void
 */
void print_list(Dlist *list, int mode)
{
	Dlist *node;
	char *end;

	end = (mode == 1) ? "\n" : "  ";

	node = list;
	while (node != NULL)
	{
		printf("%s", node->str);
		if (node->next != NULL)
			printf("%s", end);

		node = node->next;
	}
	printf("\n");
}
/**
 * list_size - Return the size of a linked list
 * @list: the linked list to be measured
 *
 * Return: The size of the linked list
 */
int list_size(Dlist *list)
{
	int i  = 0;

	if (list == NULL)
	{
		return (i);
	}

	i++;
	while ((list = list->next))
		i++;

	return (i);
}

/**
 * print_long - print more details about a file
 * @str: the path to file
 *
 * Return: Void
 */
void print_long(char *str)
{

	struct stat buf;
	struct passwd *uid;
	struct group *gid;
	char *path, *perm, *time;

	path = string_concat("./", str);
	if (lstat(path, &buf) < 0)
		perror("lstat error");

	uid = getpwuid(buf.st_uid);
	gid = getgrgid(buf.st_gid);
	perm = f_perm(buf.st_mode);
	time = ctime(&buf.st_mtime);
	printf("%c%s %1ld %s %s %*ld %.*s %s",
	       f_type(buf.st_mode), perm, buf.st_nlink, uid->pw_name,
	       gid->gr_name, 5, buf.st_size, 12, &time[4], str);

	free(perm);
	free(path);
}
