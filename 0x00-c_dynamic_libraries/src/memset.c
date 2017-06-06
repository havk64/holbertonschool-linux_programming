#include "holberton.h"

char *_memset(char *s, char b, __attribute__((unused)) unsigned int n)
{
	*s = b;
	return (s);
}
