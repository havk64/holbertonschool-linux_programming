#include "signals.h"

/**
 * sigset_print - Prints a signal set
 * @set: Set to be printed
 */
void sigset_print(const sigset_t *set)
{
	int sig;
	int cnt;

	cnt = 0;
	for (sig = 1; sig < NSIG; sig++)
	{
		if (sigismember(set, sig))
		{
			cnt++;
			printf("%d (%s)\n", sig, strsignal(sig));
		}
	}
	if (cnt == 0)
		printf("Empty signal set\n");
}

/**
 * signals_block - blocks a given set of signals from being delivered to the
 * current process
 * @signals: a pointer to a zero terminated array of integers (signals)
 * Return: On success, 0. On failure, -1
 */
int _signals_block(int *signals)
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

/**
 * _signals_unblock - unblocks a given set of signals from being delivered to
 * the current process
 * @signals: a pointer to a zero terminated array of integers (signals)
 * Return: On success, 0. On failure, -1
 */
int _signals_unblock(int *signals)
{
	int i, how;
	sigset_t set;

	how = SIG_UNBLOCK;

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
