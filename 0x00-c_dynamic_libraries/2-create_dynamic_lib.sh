#!/usr/bin/env bash
# Creates a dynamic library from all the source files in the current directory

cat <<\EOF > Makefile
CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic -fPIC
SRC	:= $(shell find . -name "*.c")
OBJS	:= $(SRC:.c=.o)
LIB	:= liball.so

$(LIB): $(OBJS)
	$(CC) -shared -o $(LIB) $(OBJS)

clean:
	rm -f $(OBJS) $(LIB)

re: clean $(LIB)
EOF

make
