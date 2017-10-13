#include "holberton.h"

/**
 * _strcmp = compare two strings
 * @s1: The first string to be compared
 * @s2: The second string to be compared
 * Return: an integer less than, equal to, or greater than zero if s1 (or the
 * first n bytes thereof) is found, respectively, to be less than, to match, or
 * be greater than s2.
 */
int _strcmp(char *s1,  char *s2)
{
	int n, i = 0;

	while (s1[i] != 0 || s2[i] != 0)
	{
		n = s1[i] - s2[i];
		if (n != 0)
			break;
		i++;
	}
	return (n);
}
