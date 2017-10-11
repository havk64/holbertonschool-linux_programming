CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
Ex0	:= add_me
Ex1	:= swap
Ex2	:= alphabet

all: $(Ex0) $(Ex1) $(Ex2)

$(Ex0): add_me_main.o add_me.o
	$(CC) $(CFLAGS) -o $@ $^

$(Ex1): swap_main.o swap.o
	$(CC) $(CFLAGS) -o $@ $^

$(Ex2): alphabet_main.o print_alphabet.o
	$(CC) $(CFLAGS) -o $@ $^

add_me.o: add_me.asm
	nasm -f elf64 $<

swap.o: swap.asm
	nasm -f elf64 $<

print_alphabet.o: print_alphabet.asm
	nasm -f elf64 $<

clean:
	$(RM) *.o

re: clean all
