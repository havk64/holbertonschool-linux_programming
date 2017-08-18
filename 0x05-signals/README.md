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

    $ make

    $ ./0-handler 
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
    $

### Task 1: Current handler - signal

The file [1-current_handler_signal.c](1-current_handler_signal.c) has a function
that retrieves the current handler of the signal SIGINT

- Prototype: `void (*current_handler_signal(void))(int);`
- The function returns a pointer to the current handler of SIGINT, or NULL on failure
- The handler remains unchanged after calling your function
- The `sigaction` function was not allowed 

Example:

    $ make

    $ ./1-current_handler_signal
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
    $

### Task 2: Gotta catch them all

The file [2-handle_sigaction.c](2-handle_sigaction.c) has a function that set a
handler for the signal `SIGINT`

- Prototype: `int handle_sigaction(void);`
- The program print `Gotcha! [<signum>]` followed by a new line, every time
Control-C is pressed  where `<signum>` is replaced with the signal number that
was caught
- `signal(2)` is not allowed

Example:

    $ make

    $ ./2-handle_sigaction 
    [0] Wait for it ...
    [1] Wait for it ...
    ^CGotcha! [2]
    [2] Wait for it ...
    [3] Wait for it ...
    ^CGotcha! [2]
    [4] Wait for it ...
    ^CGotcha! [2]
    [5] Wait for it ...
    ^CGotcha! [2]
    [6] Wait for it ...
    [7] Wait for it ...
    ^CGotcha! [2]
    [8] Wait for it ...
    ^\Quit (core dumped)
    $
 
### Task 3: Current handler - sigaction

The file [3-current_handler_sigaction.c](3-current_handler_sigaction.c) has a
function that retrieves the current handler of the signal `SIGINT`

- Prototype: `void (*current_handler_sigaction(void))(int);`
- It returns a pointer to the current handler of SIGINT, or NULL on failure
- We used the function sigaction (signal was not allowed)
- The handler is unchanged after calling your function

Example:

    $ make
	
    $ ./3-current_handler_sigaction 
    Address of the current handler: 0
    Address of the 'print_hello' function: 0x4006ea
    Address of the current handler: 0x4006ea
    [0] Wait for it ...
    [1] Wait for it ...
    ^CHello :)
    [2] Wait for it ...
    ^CHello :)
    [3] Wait for it ...
    [4] Wait for it ...
    ^CHello :)
    [5] Wait for it ...
    ^CHello :)
    [6] Wait for it ...
    ^\Quit (core dumped)
    $

### Task 4: Who said that?!

The file [4-trace_signal_sender.c](4-trace_signal_sender.c) has a function that
defines a handler for the signal SIGQUIT (Control-\ in a shell)

- Prototype: `int trace_signal_sender(void);`
- The `handler` must print `SIGQUIT sent by <pid>` each time a `SIGQUIT` (and only a SIGQUIT) is caught
- Where `<pid>` is replaced by the PID of the process that sent the signal
- It returns 0 on success, or -1 on error

```
$ make

$ ./4-trace_signal_sender
[0] Wait for it ...
[1] Wait for it ...
^\SIGQUIT sent by 0
[2] Wait for it ...
^\SIGQUIT sent by 0
[3] Wait for it ...
^\SIGQUIT sent by 0
[4] Wait for it ...
[5] Wait for it ...
^\SIGQUIT sent by 0
[6] Wait for it ...
[7] Wait for it ...
[8] Wait for it ...
SIGQUIT sent by 95337
[9] Wait for it ...
^C
```
