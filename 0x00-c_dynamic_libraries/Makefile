CC	:= gcc
CFLAGS	:= -g -c -Wall -Wextra -Werror -pedantic -fPIC -I.
SRC	:= $(shell find src/ -name "*.c")
OBJS	:= $(SRC:.c=.o)
LIB	:= libholberton.so

$(LIB): $(OBJS)
	$(CC) -shared -o $(LIB) $(OBJS)

clean:
	rm -f $(OBJS) $(LIB)

re: clean $(LIB)
