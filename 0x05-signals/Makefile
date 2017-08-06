CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
T0	:= 0-handler
T1	:= 1-current_handler_signal
T2	:= 2-handle_sigaction
T3	:= 3-current_handler_sigaction
T4	:= 4-trace_signal_sender

all: $(T0) $(T1) $(T2) $(T3) $(T4)

$(T0): 0-main.o 0-handle_signal.o
	$(CC) $(CFLAGS) -o $@ $^

$(T1): 1-main.o 1-current_handler_signal.o print_hello.o
	$(CC) $(CFLAGS) -o $@ $^

$(T2): 2-handle_sigaction.o 2-main.o
	$(CC) $(CFLAGS) -o $@ $^

$(T3): 3-current_handler_sigaction.o 3-main.o print_hello.o
	$(CC) $(CFLAGS) -o $@ $^

$(T4): 4-trace_signal_sender.o 4-main.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o all

re:
	clean all
