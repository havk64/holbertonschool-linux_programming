#ifndef SIGNALS_H
#define SIGNALS_H
#include <signal.h>
#include <stdio.h>
typedef void (*sighandler_t)(int);
int handle_signal(void);
void handler(int signum);
void (*current_handler_signal(void))(int);
void print_hello(int);
void set_print_hello(void);
int handle_sigaction(void);
void _sa_handler(int signum);
void (*current_handler_sigaction(void))(int);
#endif /* SIGNALS_H */
