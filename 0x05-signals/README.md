# 0x05. C - Signals

System programming & Algorithm ― Linux programming

### Task 0: Handle signals

The file [0-handle_signal.c](0-handle_signal.c) has a function that handle
a `SIGINT` signal usually triggered by a <kbd>Ctrl-C</kbd> command on most
Unix systems.

It will print the message `Gotcha! [<signum>]` every time the SIGINT command
is received.

Example:

    alex@~/0x05-signals$ make

    alex@~/0x05-signals$ ./0-handler 
    [0] Wait for it ...
    [1] Wait for it ...
    [2] Wait for it ...
    ^CGotcha! [2]
    [3] Wait for it ...
    ^CGotcha! [2]
    [4] Wait for it ...
    [5] Wait for it ...
    ^CGotcha! [2]
    [6] Wait for it ...
    [7] Wait for it ...
    ^CGotcha! [2]
    [8] Wait for it ...
    [9] Wait for it ...
    ^\Quit (core dumped)
    alex@~/0x05-signals$
