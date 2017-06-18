#include "ls_header.h"

void freemem(char **s, int len)
{
	int i;

	for (i = 0; i < len; i++)
		free(s[i]);
	free(s);
}

char **salloc(int size)
{
	char **s;

	s = malloc(size * sizeof(char *));
	if (s == NULL)
		exit(1);
	return (s);
}

char *strcpalloc(char *src, int size)
{
	char *dest;

	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		exit(1);
	_strcpy(dest, src);
	return (dest);
}

