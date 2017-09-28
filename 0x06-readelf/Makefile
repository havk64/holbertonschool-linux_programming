CC	:= gcc
CFLAGS	:= -g -Wall -Wextra -Werror -pedantic -Iinc/
SRC	:= src/
OBJDIR	:= objs/
T0OBJS	:= $(addprefix $(OBJDIR), 0-main.o stat.o parse.o arch32.o arch64.o print0.o \
	   print1.o print2.o bytes.o)
T1OBJS	:= $(addprefix $(OBJDIR), 1-main.o stat.o parse.o arch32.o arch64.o \
	   print_sheader.o bytes.o get_data.o)
T2OBJS	:= $(addprefix $(OBJDIR), 2-main.o stat.o parse.o arch32.o arch64.o bytes.o \
	   get_data.o print_pheader.o print_pheader2.o print2.o)
T3OBJS	:= $(addprefix $(OBJDIR), 3-main.o stat.o parse.o arch32.o arch64.o bytes.o \
	   get_data.o print_symtables.o)
T0	:= 0-hreadelf
T1	:= 1-hreadelf
T2	:= 2-hreadelf
T3	:= 100-hreadelf

all: $(T0) $(T1) $(T2) $(T3)

$(T0): $(T0OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(T1): $(T1OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(T2): $(T2OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(T3): $(T3OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)%.o: $(SRC)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJDIR)*.o

cleanall: clean
	$(RM) $(T0) $(T1) $(T2) $(T3)

re:
	clean all
