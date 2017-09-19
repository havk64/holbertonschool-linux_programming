CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
T0OBJS	:= main_0.o stat.o parse.o arch32.o arch64.o print0.o print1.o print2.o bytes.o
T1OBJS	:= main_1.o stat.o parse.o arch32.o arch64.o print_sheader.o bytes.o get_data.o
T2OBJS	:= main_2.o stat.o parse.o arch32.o arch64.o bytes.o get_data.o print_pheader.o print2.o
T0	:= 0-hreadelf
T1	:= 1-hreadelf
T2	:= 2-hreadelf

all: $(T0) $(T1) $(T2)

$(T0): $(T0OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(T1): $(T1OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(T2): $(T2OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(T0OBJS) $(T1OBJS) $(T2OBJS)

re:
	clean all
