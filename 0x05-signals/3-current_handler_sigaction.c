#include "signals.h"

void (*current_handler_sigaction(void))(int)
{
	struct sigaction oldact;

	if (sigaction(SIGINT, NULL, &oldact) < 0)
		return (NULL);

	return (oldact.sa_handler);
}

