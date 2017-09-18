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

msg(){
    printf "\xE2\x9C\x94  Outputs are identical! $@\n"
}

printf "Cleaning up Obj files... "
ERROR=$(make clean) && printf "\xE2\x9C\x94  OK!\n\n" || echo ${ERROR}
echo "Task 0:"
printf "Buiding executable... "
ERROR=$(make 0-hreadelf) && printf "\xE2\x9C\x94  OK!\n" || echo ${ERROR}

while read -r file; do
    ERROR=$(diff -s <(readelf -W -h ${file}) <(./0-hreadelf ${file})) &&
	msg "${file}" || echo ${ERROR}
done <<EOF
${NETBSD32}
${SOLARIS32}
${SORTIX32}
${SPARCBIGENDIAN32}
${UBUNTU64}
${FILE64}
${OBJFILE}
${LDFILE}
EOF

echo
echo "==============================================="
echo
echo "Task 1:"
printf "Buiding executable... "
ERROR=(make 1-hreadelf) && printf "\xE2\x9C\x94  OK!\n\n" || echo ${ERROR}

echo "Printing ${NETBSD32}:"
diff -s <(readelf -W -S ${NETBSD32}) <(./1-hreadelf ${NETBSD32})
echo "Printing ${FILE64}:"
diff -s <(readelf -W -S ${FILE64}) <(./1-hreadelf ${FILE64})
echo "Printing ${LDFILE}:"
diff -s <(readelf -W -S ${LDFILE}) <(./1-hreadelf ${LDFILE})

exit
