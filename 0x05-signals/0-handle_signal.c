#include "signals.h"

void handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}

int handle_signal(void)
{
	if (signal(SIGINT, handler) == SIG_ERR)
		return (-1);

	return (0);
}
