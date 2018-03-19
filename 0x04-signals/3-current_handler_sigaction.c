#include "signals.h"

/**
 * current_handler_sigaction - retrieves the current handler of signal SIGINT
 *
 * Return: On success, pointer to the current handler
 * On error, NULL
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction oldact;

	if (sigaction(SIGINT, NULL, &oldact) < 0)
		return (NULL);

	return (oldact.sa_handler);
}

