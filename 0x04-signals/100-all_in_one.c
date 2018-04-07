#include "signals.h"

void sigaction_handler(int signum, siginfo_t *info, void *context)
{
	char *msg = "Caught";

	UNUSED(signum);
	UNUSED(context);
	psiginfo(info, msg);
	fflush(stdout);
}

/**
 * all_in_one - it sets up a single handler for all the signals
 * Return: Always void
 */
void all_in_one(void)
{
	int i;
	struct sigaction action;

	for (i = 1; i < SIGNUM; i++)
	{
		if (i != 9 && i != 19)
		{
			action.sa_sigaction = sigaction_handler;
			sigemptyset(&action.sa_mask);
			action.sa_flags = SA_SIGINFO;
			if (sigaction(i, &action, NULL) < 0)
				continue;
		}
	}

}
