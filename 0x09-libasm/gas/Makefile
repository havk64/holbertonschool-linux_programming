libasm	:= 0-strlen.o 1-strcmp.o 2-strncmp.o 3-strchr.o 4-strstr.o 5-memcpy.o \
	100-putc.o 101-puts.o 102-strcasecmp.o 103-strncasecmp.o 104-strspn.o \
	105-strcspn.o 106-strpbrk.o 1000-puti.o 1001-puti_base.o
LST	:= listing/
ASFLAGS	:= -g -aghls

.PHONY	: all
all: $(libasm)

%.o: %.s
	$(AS) $(ASFLAGS)=$(LST)$(<:.s=.lst) -o $@ $<
