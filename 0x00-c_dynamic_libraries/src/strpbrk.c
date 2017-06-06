#include "holberton.h"

char *_strpbrk(char *s, __attribute__((unused)) char *accept)
{
	*s = *accept;
	return (s);
}
