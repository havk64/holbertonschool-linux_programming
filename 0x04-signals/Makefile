CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
T0	:= 0-handler
T0a	:= 0-test
T1	:= 1-current_handler_signal
T2	:= 2-handle_sigaction
T3	:= 3-current_handler_sigaction
T4	:= 4-trace_signal_sender
T5	:= 5-signal_describe
T6	:= 6-suspend
T7	:= 7-signal_send
T7t	:= 7-wait_for_it
T10	:= 10-pid_exist
T10a	:= 10-own_pid
T10b	:= 10-pid_one
T12	:= 100-all_in_one

all: $(T0) $(T1) $(T2) $(T3) $(T4) $(T5) $(T6) $(T7) $(T7t) $(T10) $(T0a) \
$(T10a) $(T10b) $(T12)

$(T0): 0-main.o 0-handle_signal.o
	$(CC) $(CFLAGS) -o $@ $^

$(T0a): main_0.o 0-handle_signal.o
	$(CC) $(CFLAGS) -o $@ $^

$(T1): 1-main.o 1-current_handler_signal.o print_hello.o
	$(CC) $(CFLAGS) -o $@ $^

$(T2): 2-handle_sigaction.o 2-main.o
	$(CC) $(CFLAGS) -o $@ $^

$(T3): 3-current_handler_sigaction.o 3-main.o print_hello.o
	$(CC) $(CFLAGS) -o $@ $^

$(T4): 4-trace_signal_sender.o 4-main.o
	$(CC) $(CFLAGS) -o $@ $^

$(T5): 5-signal_describe.c
	$(CC) $(CFLAGS) -o $@ $^

$(T6): 6-suspend.c
	$(CC) $(CFLAGS) -o $@ $^

$(T7): 7-signal_send.c
	$(CC) $(CFLAGS) -o $@ $^

$(T7t): 7-main.c
	$(CC) $(CFLAGS) -o $@ $^

$(T10): 10-pid_exist.o 10-main.o
	$(CC) $(CFLAGS) -o $@ $^

$(T10a): 10-pid_exist.o 10-main_0.o
	$(CC) $(CFLAGS) -o $@ $^

$(T10b): 10-pid_exist.o 10-main_1.o
	$(CC) $(CFLAGS) -o $@ $^

$(T12): 100-all_in_one.o 100-main.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o all

re:
	clean all
