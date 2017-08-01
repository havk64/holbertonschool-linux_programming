#include "signals.h"

void print_hello(int __attribute__((unused)) signum)
{
	printf("Hello :)\n");
}

void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
