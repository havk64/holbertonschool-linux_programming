CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
T0	:= 0-handler
T1	:= 1-current_handler_signal

all: $(T0) $(T1)

$(T0): 0-main.o 0-handle_signal.o
	$(CC) $(CFLAGS) -o $@ $^

$(T1): 1-main.o 1-current_handler_signal.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o all

re:
	clean all
