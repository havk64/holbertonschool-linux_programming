CC	:= gcc
CFLAGS	:= -g -O0 -Wall -Wextra -Werror -pedantic
T0	:= 0-strlen

all: $(T0)

$(T0): 0-main.o 0-strlen.o
	$(CC) $(CFLAGS) -o $@ $^

0-strlen.o: 0-strlen.asm
	nasm -f elf64 $<

clean:
	$(RM) *.o

re: clean all
