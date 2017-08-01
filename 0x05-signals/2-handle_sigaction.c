#include "signals.h"

/**
 * handler - Prints a message when a signal is received
 * @signum: the signal to be handled
 *
 * Return: always void
 */
void _sa_handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}

int handle_sigaction(void)
{
	struct sigaction act, oldact;

	act.sa_handler = _sa_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	return (sigaction(SIGINT, &act, &oldact));
}
