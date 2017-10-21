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
T9	:= 103-strncasecmp
T10	:= 104-strspn
T11	:= 105-strcspn
T12	:= 106-strpbrk
T13	:= 1000-puti

.PHONY	: all clean re

all: $(T0) $(T1) $(T2) $(T3) $(T4) $(T5) $(T6) $(T7) $(T8) $(T9) $(T10) $(T11) \
$(T12) $(T13)

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

$(T9): 103-main.o 103-strncasecmp.o
	$(CC) $(CFLAGS) -o $@ $^

$(T10): 104-main.o 104-strspn.o
	$(CC) $(CFLAGS) -o $@ $^

$(T11): 105-main.o 105-strcspn.o
	$(CC) $(CFLAGS) -o $@ $^

$(T12): 106-main.o 106-strpbrk.o
	$(CC) $(CFLAGS) -o $@ $^

$(T13): 1000-main.o 1000-puti.o 100-putc.o
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

103-strncasecmp.o: 103-strncasecmp.asm
	nasm -f elf64 $<

104-strspn.o: 104-strspn.asm
	nasm -f elf64 $<

105-strcspn.o: 105-strcspn.asm
	nasm -f elf64 $<

106-strpbrk.o: 106-strpbrk.asm
	nasm -f elf64 $<

1000-puti.o: 1000-puti.asm
	nasm -f elf64 $<

clean:
	$(RM) *.o

re: clean all
