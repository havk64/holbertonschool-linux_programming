#ifndef SIGNALS_H
#define SIGNALS_H
#include <signal.h>
#include <stdio.h>
typedef void (*sighandler_t)(int);
int handle_signal(void);
#endif /* SIGNALS_H */
