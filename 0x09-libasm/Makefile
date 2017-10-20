CC	:= gcc
CFLAGS	:= -g -O0 -Wall -Wextra -Werror -pedantic
T0	:= 0-strlen
T1	:= 1-strcmp
T2	:= 2-strncmp
T3	:= 3-strchr
T4	:= 4-strstr
T5	:= 5-memcpy
T6	:= 100-putc
T7	:= 101-puts
T8	:= 102-strcasecmp

.PHONY	: all clean re

all: $(T0) $(T1) $(T2) $(T3) $(T4) $(T5) $(T6) $(T7) $(T8)

$(T0): 0-main.o 0-strlen.o
	$(CC) $(CFLAGS) -o $@ $^

$(T1): 1-main.o 1-strcmp.o
	$(CC) $(CFLAGS) -o $@ $^

$(T2): 2-main.o 2-strncmp.o
	$(CC) $(CFLAGS) -o $@ $^

$(T3): 3-main.o 3-strchr.o
	$(CC) $(CFLAGS) -o $@ $^

$(T4): 4-main.o 4-strstr.o
	$(CC) $(CFLAGS) -o $@ $^

$(T5): 5-main.o 5-memcpy.o
	$(CC) $(CFLAGS) -o $@ $^

$(T6): 100-main.o 100-putc.o
	$(CC) $(CFLAGS) -o $@ $^

$(T7): 101-main.o 101-puts.o 0-strlen.o
	$(CC) $(CFLAGS) -o $@ $^

$(T8): 102-main.o 102-strcasecmp.o
	$(CC) $(CFLAGS) -o $@ $^

0-strlen.o: 0-strlen.asm
	nasm -f elf64 $<

1-strcmp.o: 1-strcmp.asm
	nasm -f elf64 $<

2-strncmp.o: 2-strncmp.asm
	nasm -f elf64 $<

3-strchr.o: 3-strchr.asm
	nasm -f elf64 $<

4-strstr.o: 4-strstr.asm
	nasm -f elf64 $<

5-memcpy.o: 5-memcpy.asm
	nasm -f elf64 $<

100-putc.o: 100-putc.asm
	nasm -f elf64 $<

101-puts.o: 101-puts.asm
	nasm -f elf64 $<

102-strcasecmp.o: 102-strcasecmp.asm
	nasm -f elf64 $<

clean:
	$(RM) *.o

re: clean all
