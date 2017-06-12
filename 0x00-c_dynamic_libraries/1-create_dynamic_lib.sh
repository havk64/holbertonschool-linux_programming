#!/bin/bash
# Creates a dynamic library from all the source files in the current directory
# shellcheck disable=SC2086

SRC=$(find . -name '*.c' -printf '%P\n')
CFLAGS="-Wall -Wextra -Werror -pedantic -fPIC"

while read -r source; do
    gcc ${CFLAGS} -c "$source"
done <<< "$SRC"

OBJS=$(find . -name '*.o' -printf "%P ")

gcc -shared -o liball.so ${OBJS}
