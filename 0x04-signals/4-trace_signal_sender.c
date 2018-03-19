#include "signals.h"

/**
 * sigquit_handler - the handler
 * @signum: the signal to be handled
 * @info: pointer to a siginfo_t struct
 * @context: pointer to a ucontext_t struct
 */
void sigquit_handler(int signum, siginfo_t *info, void *context)
{
	UNUSED(signum);
	UNUSED(context);
	printf("SIGQUIT sent by %d\n", info->si_pid);
}

/**
 * trace_signal_sender - defines a handler for the signal SIGQUIT (Control-\ in
 * a shell)
 *
 * Return: On success, 0. On error, -1
 */
int trace_signal_sender(void)
{
	struct sigaction act;

	act.sa_sigaction = sigquit_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	return (sigaction(SIGQUIT, &act, NULL));
}
