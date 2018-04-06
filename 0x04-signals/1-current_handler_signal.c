#include "signals.h"

/**
 * current_handler_signal - Retrieves the current handler of the signal SIGINT
 *
 * Return: On success, pointer to the current handler of SIGINT
 * On failure, NULL
 */
void (*current_handler_signal(void))(int)
{
	sighandler_t handler;

	handler = signal(SIGINT, print_hello);
	if (handler == SIG_ERR)
		return (NULL);

	return (handler);
}
