CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
T0	:= 0-hreadelf

all: $(T0)

$(T0): main_0.o print.o data.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o
re:
	clean all
