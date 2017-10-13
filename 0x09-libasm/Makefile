CC	:= gcc
CFLAGS	:= -g -O0 -Wall -Wextra -Werror -pedantic
T0	:= 0-strlen
T1	:= 1-strcmp

.PHONY	: all clean re

all: $(T0) $(T1)

$(T0): 0-main.o 0-strlen.o
	$(CC) $(CFLAGS) -o $@ $^

$(T1): 1-main.o 1-strcmp.o
	$(CC) $(CFLAGS) -o $@ $^

0-strlen.o: 0-strlen.asm
	nasm -f elf64 $<

1-strcmp.o: 1-strcmp.asm
	nasm -f elf64 $<

clean:
	$(RM) *.o

re: clean all
