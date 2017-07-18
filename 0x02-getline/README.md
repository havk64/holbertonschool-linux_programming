# 0x02. C - Static variables, getline

System programming & Algorithm ― Linux programming

### Task 0 - _getline

- The function [`_getline`](_getline.c) reads an entire line of a `fd`(file descriptor).

Prototype : `char *_getline(const int fd)`

#### Features:

- `fd` is the file descriptor to read from
- If there are no more lines to return, or if there is an error, the function returns NULL
- The function returns a null-terminated string that does not include the newline character
- The header file [_getline.h](_getline.h) defines a macro called READ_SIZE.  
This macro defines the number of bytes is read each time we call `read`:  

        read(fd, buffer, READ_SIZE)

#### Test file:

        #include <fcntl.h>
        #include <stdio.h>
        #include <unistd.h>
        #include <stdlib.h>

        #include "_getline.h"

        /**
         * main - entry point.
         *
         * Return: always 0.
         */
        int main()
        {
            int fd;
            char *line;
        
            fd = open("main.c", 0);
            while ((line = _getline(fd)))
            {
                printf("%s\n", line);
                free(line);
            }
            close(fd);
            return (0);
        }
