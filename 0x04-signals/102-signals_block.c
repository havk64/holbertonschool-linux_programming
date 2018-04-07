#include "signals.h"

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
