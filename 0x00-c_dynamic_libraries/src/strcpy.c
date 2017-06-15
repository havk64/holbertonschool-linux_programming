#include "holberton.h"

/**
 * _strcpy - concatenate two strings into a new one
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a new string resulting of the concatenation of dest + src
 */
char *_strcpy(char *dest, char *src)
{
	char *s;

	s = dest;
	while ((*dest++ = *src++))
		;
	*dest = 0;
	return (s);
}
