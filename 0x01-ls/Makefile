CC	:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pedantic
SRC	:= $(shell find . -maxdepth 1 -name '*.c')
OBJS	:= $(SRC:.c=.o)
TARGET	:= hls

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(TARGET)

re: clean $(TARGET)
