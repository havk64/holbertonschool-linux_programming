CC	= gcc
CFLAGS	= -g -Wall -Werror -Wextra -pedantic
hack	= hack_heap
loop	= loop

.PHONY: all
all: $(hack) $(loop)

$(hack): write_heap.o
	$(CC) $(CFLAGS) -o $@ $<
	sudo setcap cap_sys_ptrace=pe $@

$(loop): loop.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) *.o

re: all clean
