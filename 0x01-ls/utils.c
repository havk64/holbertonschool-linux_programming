#include "ls_header.h"

/**
 * _strlen - counts the number of characters of a string
 * @s: The string to be counted
 *
 * Return: the length, in bytes, of the string
 */
int _strlen(char *s)
{

	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
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
		while (i < _strlen(s1))
		{
			s[i] = s1[i];
			i++;
		}
		while (i < sum)
		{
			s[i] = s2[i - _strlen(s1)];
			i++;
		}
		s[i] = 0;
		return (s);
	}
	return (NULL);
}
