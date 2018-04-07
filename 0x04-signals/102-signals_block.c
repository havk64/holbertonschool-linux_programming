#include "signals.h"

/**
 * signals_block - blocks a given set of signals from being delivered to the
 * current process
 * @signals: a pointer to a zero terminated array of integers (signals)
 * Return: On success, 0. On failure, -1
 */
int signals_block(int *signals)
{
	int i, how;
	sigset_t set;

	how = SIG_SETMASK;

	if (sigemptyset(&set) < 0)
		return (EXIT_FAILURE);

	for (i = 0; signals[i] != 0; i++)
	{
		if (sigaddset(&set, signals[i]) < 0)
			return (EXIT_FAILURE);
	}

	if (sigprocmask(how, &set, NULL) < 0)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
