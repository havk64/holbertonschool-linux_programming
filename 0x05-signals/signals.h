#ifndef SIGNALS_H
#define SIGNALS_H
#define UNUSED(x) (void)(x)
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef void (*sighandler_t)(int);
int handle_signal(void);
void handler(int signum);
void (*current_handler_signal(void))(int);
void print_hello(int);
void set_print_hello(void);
int handle_sigaction(void);
void _sa_handler(int signum);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
void sigquit_handler(int signum, siginfo_t *info, void *);
int pid_exist(pid_t pid);
#endif /* SIGNALS_H */
