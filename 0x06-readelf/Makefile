CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
T0OBJS	:= main_0.o stat.o parse.o arch32.o arch64.o print0.o print1.o print2.o \
	   bytes.o
T1OBJS	:= main_1.o stat.o parse.o arch32.o arch64.o print_sheader.o bytes.o \
	   get_data.o
T2OBJS	:= main_2.o stat.o parse.o arch32.o arch64.o bytes.o get_data.o \
	   print_pheader.o print_pheader2.o print2.o
T3OBJS	:= 3-main.o stat.o parse.o arch32.o arch64.o bytes.o get_data.o
T0	:= 0-hreadelf
T1	:= 1-hreadelf
T2	:= 2-hreadelf
T3	:= 100-hreadelf

all: $(T0) $(T1) $(T2) $(T3)

$(T0): $(T0OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(T1): $(T1OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(T2): $(T2OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(T3): $(T3OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(T0OBJS) $(T1OBJS) $(T2OBJS) $(T3OBJS)

re:
	clean all
