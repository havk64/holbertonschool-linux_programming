#include "signals.h"

/**
 * handler - Prints a message when a signal is received
 * @signum: the signal to be handled
 *
 * Return: always void
 */
void handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
	fsync(1);
}

/**
 * handle_signal - set a handler for the signal SIGINT
 *
 * Return: On Success 0, On Error -1
 */
int handle_signal(void)
{
	if (signal(SIGINT, handler) == SIG_ERR)
		return (-1);

	return (0);
}
