CC	:= gcc
CFLAGS	:= -g -Wall -Werror -Wextra -pedantic
T0	:= brk
T1	:= mmap
T2	:= naive
T2a	:= naive_malloc
T3	:= header_malloc
T4	:= page_malloc
T4a	:= test_malloc
T5	:= extend_malloc
T6	:= aligned_malloc

all: $(T0) $(T1) $(T2) $(T2a) $(T3) $(T4) $(T4a) $(T5) $(T6)

$(T0): 0-main.o
	$(CC) $(CFLAGS) $^ -o $@

$(T1): 1-main.o
	$(CC) $(CFLAGS) $^ -o $@

$(T2): 2-main.o 2-naive_malloc.o
	$(CC) $(CFLAGS) $^ -o $@

$(T2a): 2-main_malloc.o
	$(CC) $(CFLAGS) $^ -o $@

$(T3): 3-main.o 3-naive_malloc_header.o
	$(CC) $(CFLAGS) $^ -o $@

$(T4): 4-main.o 4-naive_malloc_page.o
	$(CC) $(CFLAGS) $^ -o $@

$(T4a): 4-main_beyond.o 4-naive_malloc_page.o
	$(CC) $(CFLAGS) $^ -o $@

$(T5): 5-main.o 5-naive_malloc_extend.o
	$(CC) $(CFLAGS) $^ -o $@

$(T6): 6-main.o 6-naive_malloc_align.o
	$(CC) $(CFLAGS) $^ -o $@
