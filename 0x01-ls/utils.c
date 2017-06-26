#include "ls_header.h"

/**
 * _strlen - counts the number of characters of a string
 * @s: The string to be counted
 *
 * Return: the length of the string
 */
size_t _strlen(char *s)
{

	size_t i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * string_concat - concatenates two strings in a newly allocated
 * space in memory
 * @s1: The first string
 * @s2: The second string
 *
 * Return: On success: a pointer to the new string
 * On error, NULL
 */
char *string_concat(char *s1, char *s2)
{
	int i, sum;
	char *s;

	i = 0;
	sum = _strlen(s1) + _strlen(s2);

	s = malloc(sizeof(char) * (sum + 1));
	if (s != NULL)
	{
		while ((s[i] = s1[i]))
			i++;

		while ((s[i] = s2[i - _strlen(s1)]))
			i++;

		s[i] = 0;
		return (s);
	}
	return (NULL);
}

/**
 * _strcpy - concatenate two strings into a new one
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a new string resulting of the concatenation of dest + src
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	char *s;

	s = dest;
	i = 0;
	while ((dest[i] = src[i]))
		i++;

	dest[i] = 0;
	return (s);
}
