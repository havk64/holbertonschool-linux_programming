# 0x05. C - Signals

System programming & Algorithm ― Linux programming

### Task 0: Handle signals

The file [0-handle_signal.c](0-handle_signal.c) has a function that handle
a `SIGINT` signal usually triggered by a <kbd>Ctrl-C</kbd> command on most
Unix systems.

It will print the message `Gotcha! [<signum>]` every time the SIGINT command
is received, where `signum` will be replaced by the signal caught.

Note: The `sigaction` function was not allowed

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

### Task 1: Current handler - signal

The file [1-current_handler_signal.c](1-current_handler_signal.c) has a function
that retrieves the current handler of the signal SIGINT

- Prototype: `void (*current_handler_signal(void))(int);`
- The function returns a pointer to the current handler of SIGINT, or NULL on failure
- The handler remains unchanged after calling your function
- The `sigaction` function was not allowed 

Example:

    alex@~/0x05-signals$ make

    alex@~/0x05-signals$ ./1-current_handler_signal
    Address of the current handler: 0
    Address of the 'print_hello' function: 0x4006da
    Address of the current handler: 0x4006da
    [0] Wait for it ...
    [1] Wait for it ...
    ^CHello :)
    [2] Wait for it ...
    ^CHello :)
    [3] Wait for it ...
    [4] Wait for it ...
    ^CHello :)
    [5] Wait for it ...
    ^\Quit (core dumped)
    alex@~/0x05-signals$
