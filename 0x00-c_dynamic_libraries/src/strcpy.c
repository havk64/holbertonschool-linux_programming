#include "holberton.h"

char *_strcpy(char *dest, char *src)
{
	char *s;

	s = dest;
	while ((*dest++ = *src++))
		;
	*dest = 0;
	return (s);
}
