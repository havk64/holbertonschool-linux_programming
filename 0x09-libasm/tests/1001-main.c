#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "libasm.h"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(asm_puti_base(98, "0123456789") == 2);
	printf("\n");
	assert(asm_puti_base(-1, "0123456789") == 2);
	printf("\n");
	assert(asm_puti_base(129342, "0123456789abcdef") == 5);
	printf("\n");
	assert(asm_puti_base(781532, "01") == 20);
	printf("\n");
	assert(asm_puti_base(INT_MAX, "abcdefghijklmnopqrstwxyz") == 7);
	printf("\n");
	assert(asm_puti_base(INT_MIN, "0123456789ABCDEF") == 9);
	printf("\n");
	assert(asm_puti_base(0, "01234567") == 1);
	printf("\n");
	printf("\nAll good!\n");
	return (EXIT_SUCCESS);
}
