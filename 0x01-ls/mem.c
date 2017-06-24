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
