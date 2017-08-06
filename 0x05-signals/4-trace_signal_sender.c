#include "signals.h"

void sigquit_handler(int __attribute__((unused)) signum, siginfo_t *info,
		     void __attribute__((unused)) *context)
{
	printf("SIGQUIT sent by %d\n", info->si_pid);
}

int trace_signal_sender(void)
{
	struct sigaction act;

	act.sa_sigaction = sigquit_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	return (sigaction(SIGQUIT, &act, NULL));
}
