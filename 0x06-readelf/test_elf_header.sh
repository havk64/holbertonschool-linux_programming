#!/bin/bash
# Compile and test the output of 0-hreadelf binary agains the output of readelf -h
FILE32=file32
FILE64=0-hreadelf
OBJFILE=main_0.o
LDFILE=/lib64/ld-linux-x86-64.so.2

make clean
make 0-hreadelf

diff -s <(readelf -W -h ${FILE32}) <(./0-hreadelf ${FILE32})
diff -s <(readelf -W -h ${FILE64}) <(./0-hreadelf ${FILE64})
diff -s <(readelf -W -h ${OBJFILE}) <(./0-hreadelf ${OBJFILE})
diff -s <(readelf -W -h ${LDFILE}) <(./0-hreadelf ${LDFILE})

make 1-hreadelf

echo "Printing ${FILE32}"
diff -s <(readelf -W -S ${FILE32}) <(./1-hreadelf ${FILE32})
echo "Printing ${FILE64}"
diff -s <(readelf -W -S ${FILE64}) <(./1-hreadelf ${FILE64})
echo "Printing ${LDFILE}"
diff -s <(readelf -W -S ${LDFILE}) <(./1-hreadelf ${LDFILE})

exit
