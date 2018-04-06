#include "signals.h"

/**
 * _sa_handler - Prints a message when a signal is received
 * @signum: the signal to be handled
 *
 * Return: always void
 */
void _sa_handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
	fflush(stdout);
}

/**
 * handle_sigaction - set a handler for the signal SIGINT (using sigaction)
 *
 * Return: On Success 0, On Error -1
 */
int handle_sigaction(void)
{
	struct sigaction action;

	action.sa_handler = _sa_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return (sigaction(SIGINT, &action, NULL));
}
