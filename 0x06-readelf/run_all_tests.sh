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
JPGFILE=test_files/jpeg.mod
PYTHONOBJ=test_files/python.obj
SFTPSERVER=test_files/sftp-server
VGPRELOAD=test_files/vgpreload_memcheck-x86-linux.so

define(){
    IFS=$'\n' read -r -d '' "${1}" || true
}

success(){
    printf "\xE2\x9C\x94  Outputs are identical! %s\n" "$1"
}

failure(){
    printf "\u2718  Failed: %s\n" "$1"
    printf "%s" "$2"
}

printf "Cleaning up Obj files... "
define FILES <<EOF
${NETBSD32}
${SOLARIS32}
${SORTIX32}
${SPARCBIGENDIAN32}
${UBUNTU64}
${FILE64}
${OBJFILE}
${LDFILE}
${JPGFILE}
${PYTHONOBJ}
${SFTPSERVER}
${VGPRELOAD}
EOF

printf "Cleaning up Obj files... "
ERROR=$(make clean) && printf "%s" d"\xE2\x9C\x94  OK!\n\n" || printf "%s" "${ERROR}"
echo "Task 0:"
printf "Buiding executable... "
ERROR=$(make 0-hreadelf) && printf "\xE2\x9C\x94  OK!\n\n" || printf "%s" "${ERROR}"

while read -r file; do
    ERROR=$(diff -s <(readelf -W -h "${file}") <(./0-hreadelf "${file}")) &&
	success "${file}" || printf "%s" "${ERROR}"
done <<< "${FILES}"

echo
echo "==============================================="
echo
echo "Task 1:"
printf "Buiding executable... "
ERROR=$(make 1-hreadelf) && printf "\xE2\x9C\x94  OK!\n\n" || printf "%s" "${ERROR}"

while read -r file; do
    ERROR=$(diff -s <(readelf -W -S "${file}") <(./1-hreadelf "${file}")) &&
	success "${file}" || failure "${file}" "${ERROR}\n"
done <<< "${FILES}"

exit
