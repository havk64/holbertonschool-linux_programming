#include "signals.h"

/**
 * handle_pending - sets up a handler for all the pending signals of the
 * current process
 * @handler: a pointer to a handler function
 * Return: On success, 0. On failure, -1
 */
int handle_pending(void (*handler)(int))
{
	int i, ismember;
	sigset_t set;
	struct sigaction action;

	if (sigemptyset(&set) < 0)
		return (EXIT_FAILURE);

	action.sa_handler = handler;
	action.sa_flags = 0;
	action.sa_mask = set;

	if (sigpending(&set) < 0)
		return (EXIT_FAILURE);

	for (i = 1; i < NSIG; i++)
	{
		ismember = sigismember(&set, i);
		if (ismember)
		{
			if (sigaction(i, &action, NULL) < 0)
				return (EXIT_FAILURE);
		}
		else if (ismember < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
