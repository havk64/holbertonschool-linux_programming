CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic -fPIC -I.
SRC	:= $(wildcard src/*.c)
OBJS	:= $(SRC:.c=.o)
LIB	:= libholberton.so

$(LIB): $(OBJS)
	$(CC) -shared -o $(LIB) $(OBJS)

clean:
	rm -f $(OBJS) $(LIB)

re: clean $(LIB)
