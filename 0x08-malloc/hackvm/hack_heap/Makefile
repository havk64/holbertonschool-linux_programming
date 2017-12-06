CC	= gcc
CFLAGS	= -g -Wall -Werror -Wextra -pedantic
loop	= loop
hack	= hack_heap

.PHONY: all clean re
all: $(loop) $(hack)

$(loop): loop.o
	$(CC) $(CFLAGS) -o $@ $<

$(hack): write_heap.o
	$(CC) $(CFLAGS) -o $@ $<
	sudo setcap cap_sys_ptrace+pe $@

clean:
	$(RM) *.o

re: all clean
