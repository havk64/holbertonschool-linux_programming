CC	:= gcc
CFLAGS	:= -g3 -O0 -Wall -Wextra -Werror -pedantic
SRC	:= $(wildcard *.c)
OBJS	:= $(SRC:.c=.o)
TARGET	:= hls

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(TARGET)

re: clean $(TARGET)
