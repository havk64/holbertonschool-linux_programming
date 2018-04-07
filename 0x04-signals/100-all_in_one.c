#include "signals.h"

/**
 * sigaction_handler - act as handler for sigaction syscall
 * @signum: an integer representing a signal
 * @info: a pointer to a siginfo_t with info about the signal
 * @context: a void pointer to a user context (getcontext(3))
 * Return: Always void
 */
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
