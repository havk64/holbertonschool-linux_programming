CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
T0	:= 0-hreadelf

all: $(T0)

$(T0): main_0.o print.o arch32.o arch64.o data1.o data2.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o
re:
	clean all
