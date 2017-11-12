libasm	:= 0-strlen.o 1-strcmp.o 2-strncmp.o 3-strchr.o 4-strstr.o 5-memcpy.o \
	100-putc.o
LST	:= listing/
ASFLAGS	:= -g -aghls

.PHONY	: all
all: $(libasm)

%.o: %.s
	$(AS) $(ASFLAGS)=$(LST)$(<:.s=.lst) -o $@ $<
