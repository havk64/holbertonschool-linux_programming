CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
Ex0	:= a.out

all: $(Ex0)

$(Ex0): add_me_main.o add_me.o
	$(CC) $(CFLAGS) -o $@ $^

add_me.o: add_me.asm
	nasm -f elf64 $<
