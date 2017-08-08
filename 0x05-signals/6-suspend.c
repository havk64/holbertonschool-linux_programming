#include "signals.h"

void single_time(int signum)
{
	printf("Caught %d\n", signum);
}

int main(void)
{
	struct sigaction act;

	act.sa_handler = single_time;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if (sigaction(SIGINT, &act, NULL) < 0)
		return (EXIT_FAILURE);

	pause();
	printf("Signal received\n");
	return (EXIT_SUCCESS);
}
