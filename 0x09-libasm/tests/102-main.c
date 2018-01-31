#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  "HOLBERTON SCHOOL"
#define S3  "Holberton SchooL"
#define S4  "holberton socool"
#define S5  "@ABCDEFGHIJKLMNOPQRSTXYZ[]"
#define S6  "@abcdefghijklmnopqrstxyz[]"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strcasecmp(S1, S1) == asm_strcasecmp(S1, S1));
	assert(strcasecmp(S1, S2) == asm_strcasecmp(S1, S2));
	assert(strcasecmp(S1, S3) == asm_strcasecmp(S1, S3));
	assert(strcasecmp(S1, S4) == asm_strcasecmp(S1, S4));
	assert(strcasecmp(S5, S6) == asm_strcasecmp(S5, S6));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
