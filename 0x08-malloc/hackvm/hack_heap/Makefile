CC	= gcc
CFLAGS	= -g -Wall -Werror -Wextra -pedantic
loop	= loop
hack	= hack_heap
sr	= search_replace

.PHONY: all clean re
all: $(loop) $(hack) $(sr)

$(loop): loop.o
	$(CC) $(CFLAGS) -o $@ $<

$(hack): write_heap.o
	$(CC) $(CFLAGS) -o $@ $<
	sudo setcap cap_sys_ptrace+pe $@

$(sr): search_replace.o
	$(CC) $(CFLAGS) -o $@ $<
	sudo setcap cap_sys_ptrace+ep $@

clean:
	$(RM) *.o

re: all clean
