CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
T0OBJS	:= main_0.o stat.o parse.o arch32.o arch64.o print0.o print1.o print2.o bytes.o
T1OBJS	:= main_1.o stat.o parse.o arch32.o arch64.o print_sheader.o bytes.o get_data.o
T0	:= 0-hreadelf
T1	:= 1-hreadelf

all: $(T0) $(T1)

$(T0): $(T0OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(T1): $(T1OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(T0OBJS) $(T1OBJS)
re:
	clean all
