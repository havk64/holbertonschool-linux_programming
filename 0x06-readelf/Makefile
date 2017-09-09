CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
T0	:= 0-hreadelf

all: $(T0)

$(T0): main_0.o parse.o arch32.o arch64.o print1.o print2.o bytes.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o
re:
	clean all
