CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic
OBJS	:= objs/
LST	:= listing/
SSE	:= sse/
NASM	:= nasm
NFLAGS	:= -f elf64 -g
T0	:= 0-strlen
T1	:= 1-strcmp
T2	:= 2-strncmp
T3	:= 3-strchr
T4	:= 4-strstr
T5	:= 5-memcpy
T6	:= 100-putc
T7	:= 101-puts
T8	:= 102-strcasecmp
T9	:= 103-strncasecmp
T10	:= 104-strspn
T11	:= 105-strcspn
T12	:= 106-strpbrk
T13	:= 1000-puti
T14	:= 1001-puti_base
S0	:= strlen_sse
S1	:= strcmp_sse
U0	:= cpuid
G0	:= strlen_gas
G1	:= strcmp_gas
G2	:= strncmp_gas
G3	:= strchr_gas
G4	:= strstr_gas
G5	:= memcpy_gas
G100	:= putc_gas
G101	:= puts_gas
G102	:= strcasecmp_gas
G103	:= strncasecmp_gas
G104	:= strspn_gas
G105	:= strcspn_gas
GAS	:= gas/

vpath %.asm $(SSE)

all	:= subdir $(T0) $(T1) $(T2) $(T3) $(T4) $(T5) $(T6) $(T7) $(T8) $(T9) $(T10) \
	$(T11) $(T12) $(T13) $(T14) $(S0) $(S1) $(U0) $(G0) $(G1) $(G2) $(G3) \
	$(G4) $(G5) $(G100) $(G101) $(G102) $(G103) $(G104) $(G105)

.PHONY	: all clean re subdir $(GAS)

all: $(all)

subdir: $(GAS)

$(GAS):
	$(MAKE) -C $@

$(OBJS)%.o: %.asm | $(OBJS)
	$(NASM) $(NFLAGS) -o $@ $< -l $(LST)$(<:.asm=.lst)

$(OBJS):
	@mkdir -p $(LST)$(SSE) $@

$(OBJS)%.o: c_interface/%.c
	$(CC) -c $(CFLAGS) -I. -o $@ $^

$(T0): $(addprefix $(OBJS), 0-main.o 0-strlen.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T1): $(addprefix $(OBJS), 1-main.o 1-strcmp.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T2): $(addprefix $(OBJS), 2-main.o 2-strncmp.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T3): $(addprefix $(OBJS), 3-main.o 3-strchr.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T4): $(addprefix $(OBJS), 4-main.o 4-strstr.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T5): $(addprefix $(OBJS), 5-main.o 5-memcpy.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T6): $(addprefix $(OBJS), 100-main.o 100-putc.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T7): $(addprefix $(OBJS), 101-main.o 101-puts.o 0-strlen.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T8): $(addprefix $(OBJS), 102-main.o 102-strcasecmp.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T9): $(addprefix $(OBJS), 103-main.o 103-strncasecmp.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T10): $(addprefix $(OBJS), 104-main.o 104-strspn.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T11): $(addprefix $(OBJS), 105-main.o 105-strcspn.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T12): $(addprefix $(OBJS), 106-main.o 106-strpbrk.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T13): $(addprefix $(OBJS), 1000-main.o 1000-puti.o 100-putc.o)
	$(CC) $(CFLAGS) -o $@ $^

$(T14): $(addprefix $(OBJS), 1001-main.o 1001-puti_base.o 100-putc.o 0-strlen.o)
	$(CC) $(CFLAGS) -o $@ $^

$(S0): $(addprefix $(OBJS), 0-main.o strlen_sse.o)
	$(CC) $(CFLAGS) -o $@ $^

$(S1): $(addprefix $(OBJS), 1-main.o strcmp_sse.o)
	$(CC) $(CFLAGS) -o $@ $^

$(U0): $(addprefix $(OBJS), 1001-puti_base.o 100-putc.o 0-strlen.o) utils/cpuid.c
	$(CC) $(CFLAGS) -I. -o $@ $^

$(G0): $(OBJS)0-main.o $(GAS)0-strlen.o
	$(CC) $(CFLAGS) -I. -o $@ $^

$(G1): $(OBJS)1-main.o $(GAS)1-strcmp.o
	$(CC) $(CFLAGS) -I. -o $@ $^

$(G2): $(OBJS)2-main.o $(GAS)2-strncmp.o
	$(CC) $(CFLAGS) -I. -o $@ $^

$(G3): $(OBJS)3-main.o $(GAS)3-strchr.o
	$(CC) $(CFLAGS) -I. -o $@ $^

$(G4): $(OBJS)4-main.o $(GAS)4-strstr.o
	$(CC) $(CFLAGS) -I. -o $@ $^

$(G5): $(OBJS)5-main.o $(GAS)5-memcpy.o
	$(CC) $(CFLAGS) -I. -o $@ $^

$(G100): $(OBJS)100-main.o $(GAS)100-putc.o
	$(CC) $(CFLAGS) -I. -o $@ $^

$(G101): $(addprefix $(OBJS), 101-main.o 0-strlen.o) $(GAS)101-puts.o
	$(CC) $(CFLAGS) -I. -o $@ $^

$(G102): $(OBJS)102-main.o $(GAS)102-strcasecmp.o
	$(CC) $(CFLAGS) -I. -o $@ $^

$(G103): $(OBJS)103-main.o $(GAS)103-strncasecmp.o
	$(CC) $(CFLAGS) -I. -o $@ $^

$(G104): $(OBJS)104-main.o $(GAS)104-strspn.o
	$(CC) $(CFLAGS) -I. -o $@ $^

$(G105): $(OBJS)105-main.o $(GAS)105-strcspn.o
	$(CC) $(CFLAGS) -I. -o $@ $^

clean:
	$(RM) $(OBJS)*.o

cleanall: clean
	$(RM) $(all) $(LST)*.lst

re: clean all
