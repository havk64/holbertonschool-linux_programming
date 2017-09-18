#!/bin/bash
# Compile and test the output of 0-hreadelf binary agains the output of readelf -h
NETBSD32=test_files/netbsd32
SOLARIS32=test_files/solaris32
SORTIX32=test_files/sortix32
SPARCBIGENDIAN32=test_files/sparcbigendian32
UBUNTU64=test_files/ubuntu64
FILE64=0-hreadelf
OBJFILE=main_0.o
LDFILE=/lib64/ld-linux-x86-64.so.2


diff -s <(readelf -W -h ${NETBSD32}) <(./0-hreadelf ${NETBSD32})
diff -s <(readelf -W -h ${SOLARIS32}) <(./0-hreadelf ${SOLARIS32})
diff -s <(readelf -W -h ${SORTIX32}) <(./0-hreadelf ${SORTIX32})
diff -s <(readelf -W -h ${SPARCBIGENDIAN32}) <(./0-hreadelf ${SPARCBIGENDIAN32})
diff -s <(readelf -W -h ${UBUNTU64}) <(./0-hreadelf ${UBUNTU64})
diff -s <(readelf -W -h ${FILE64}) <(./0-hreadelf ${FILE64})
diff -s <(readelf -W -h ${OBJFILE}) <(./0-hreadelf ${OBJFILE})
diff -s <(readelf -W -h ${LDFILE}) <(./0-hreadelf ${LDFILE})
ERROR=$(make clean) && printf "\xE2\x9C\x94  Cleaning up Obj files\n" || echo ${ERROR}
ERROR=$(make 0-hreadelf) && printf "\xE2\x9C\x94  Buiding executable\n\n" || echo ${ERROR}


echo "Printing ${FILE32}"
diff -s <(readelf -W -S ${FILE32}) <(./1-hreadelf ${FILE32})
echo "Printing ${FILE64}"
ERROR=(make 1-hreadelf) && printf "\xE2\x9C\x94  Buiding executable\n\n" || echo ${ERROR}
diff -s <(readelf -W -S ${FILE64}) <(./1-hreadelf ${FILE64})
echo "Printing ${LDFILE}"
diff -s <(readelf -W -S ${LDFILE}) <(./1-hreadelf ${LDFILE})

exit
