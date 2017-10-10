CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
Ex0	:= add_me
Ex1	:= swap

all: $(Ex0) $(Ex1)

$(Ex0): add_me_main.o add_me.o
	$(CC) $(CFLAGS) -o $@ $^

$(Ex1): swap_main.o swap.o
	$(CC) $(CFLAGS) -o $@ $^

add_me.o: add_me.asm
	nasm -f elf64 $<

swap.o: swap.asm
	nasm -f elf64 $<
