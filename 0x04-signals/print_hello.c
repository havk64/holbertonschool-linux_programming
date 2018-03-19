#include "signals.h"

/**
 * print_hello - Print a message when SIGINT is received
 * @signum: the signal to be handled
 *
 * Return: always void
 */
void print_hello(int __attribute__((unused)) signum)
{
	printf("Hello :)\n");
}

/**
 * set_print_hello - Set a handler to the SIGINT signal
 *
 * Return: always void
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
