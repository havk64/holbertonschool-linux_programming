#include "signals.h"

void (*current_handler_signal(void))(int)
{
	void (*handler)(int);

	handler = signal(SIGINT, print_hello);
	if (handler == SIG_ERR)
		return (NULL);

	return (handler);
}
