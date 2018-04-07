#include "signals.h"

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
