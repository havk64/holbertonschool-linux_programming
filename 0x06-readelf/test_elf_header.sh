#!/bin/bash
# Compile and test the output of 0-hreadelf binary agains the output of readelf -h
FILE32=file32
FILE64=0-hreadelf
OBJFILE=main_0.o
LD=/lib64/ld-linux-x86-64.so.2

make clean
make 0-hreadelf

diff -s <(readelf -h ${FILE32}) <(./0-hreadelf ${FILE32})
diff -s <(readelf -h ${FILE64}) <(./0-hreadelf ${FILE64})
diff -s <(readelf -h ${OBJFILE}) <(./0-hreadelf ${OBJFILE})
diff -s <(readelf -h ${LD}) <(./0-hreadelf ${LD})

exit
