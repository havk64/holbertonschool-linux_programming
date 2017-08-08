#include "signals.h"

/**
 * single_time - Prints a message when a signal is received
 * @signum: the signal to be handled
 *
 * Return: always void
 */
void single_time(int signum)
{
	printf("Caught %d\n", signum);
}

/**
 * main - Entry point
 *
 * Return: always void
 */
int main(void)
{
	struct sigaction act;

	act.sa_handler = single_time;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if (sigaction(SIGINT, &act, NULL) < 0)
		return (EXIT_FAILURE);

	pause();
	printf("Signal received\n");
	return (EXIT_SUCCESS);
}
