#include "holberton.h"

/**
 * _strcat - concatenate two strings
 * @dest: the destination string
 * @src: the source string
 *
 * Return: the new string concatenated
 */
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
