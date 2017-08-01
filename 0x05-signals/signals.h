#ifndef SIGNALS_H
#define SIGNALS_H
#include <signal.h>
#include <stdio.h>
typedef void (*sighandler_t)(int);
int handle_signal(void);
void (*current_handler_signal(void))(int);
void print_hello(int);
void set_print_hello(void);
#endif /* SIGNALS_H */
