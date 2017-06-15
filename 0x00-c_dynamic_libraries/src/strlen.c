#include "holberton.h"

int _strlen(char *s)
{

	int len, i;

	len = 0;
	for (i = 0; *(s + i) != '\0'; i++)
	{
		len++;
	}
	return (len++);
}
