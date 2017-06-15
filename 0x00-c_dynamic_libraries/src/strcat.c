#include "holberton.h"

char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	return (s);
}
