#include "signals.h"

int handle_pending(void (*handler)(int))
{
	int i;
	sigset_t set;

	if (sigemptyset(&set) < 0)
		return (EXIT_FAILURE);

	if (sigpending(&set) < 0)
		return (EXIT_FAILURE);

	for (i = 1; i < NSIG; i++)
		if (sigismember(&set, i))
			handler(i);

	return (EXIT_SUCCESS);
}
