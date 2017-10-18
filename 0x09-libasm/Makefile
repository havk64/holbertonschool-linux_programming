CC	:= gcc
CFLAGS	:= -g -O0 -Wall -Wextra -Werror -pedantic
T0	:= 0-strlen
T1	:= 1-strcmp
T2	:= 2-strncmp
T3	:= 3-strchr

.PHONY	: all clean re

all: $(T0) $(T1) $(T2) $(T3)

$(T0): 0-main.o 0-strlen.o
	$(CC) $(CFLAGS) -o $@ $^

$(T1): 1-main.o 1-strcmp.o
	$(CC) $(CFLAGS) -o $@ $^

$(T2): 2-main.o 2-strncmp.o
	$(CC) $(CFLAGS) -o $@ $^

$(T3): 3-main.o 3-strchr.o
	$(CC) $(CFLAGS) -o $@ $^

0-strlen.o: 0-strlen.asm
	nasm -f elf64 $<

1-strcmp.o: 1-strcmp.asm
	nasm -f elf64 $<

2-strncmp.o: 2-strncmp.asm
	nasm -f elf64 $<

3-strchr.o: 3-strchr.asm
	nasm -f elf64 $<

clean:
	$(RM) *.o

re: clean all
