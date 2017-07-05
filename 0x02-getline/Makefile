CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
SRC	:= _getline.c main.c
BIN	:= getline

$(BIN): $(SRC) _getline.h
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN)

re: clean $(BIN)
