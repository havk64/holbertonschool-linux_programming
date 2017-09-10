CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
T0OBJS	:= main_0.o print.o
T0	:= hnm

all: $(T0)

$(T0): $(T0OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(T0OBJS)
re:
	clean all
