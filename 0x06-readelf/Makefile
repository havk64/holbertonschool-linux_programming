CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
T0OBJS	:= main_0.o stat.o parse.o arch32.o arch64.o print0.o print1.o print2.o bytes.o
T0	:= 0-hreadelf

all: $(T0)

$(T0): $(T0OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(T0OBJS)
re:
	clean all
