#include "signals.h"

/**
 * sigset_init - Initializes a sigset_t struct
 * @set: a pointer to a sigset_t struct
 * @signals: a zero terminated array of integers (signals)
 * Return: On success, 0. On failure, -1
 */
int sigset_init(sigset_t *set, int *signals)
{
	int i;

	if (sigemptyset(set) < 0)
		return (EXIT_FAILURE);

	for (i = 0; signals[i] != 0; i++)
	{
		if (sigaddset(set, signals[i]) < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
