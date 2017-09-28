#!/bin/bash
# Compile and test the output of 0-hreadelf binary agains the output of readelf -h

NETBSD32=test/netbsd32
SOLARIS32=test/solaris32
SORTIX32=test/sortix32
SPARCBIGENDIAN32=test/sparcbigendian32
UBUNTU64=test/ubuntu64
FILE64=test/0-hreadelf
OBJFILE=test/main_0.o
JPGFILE=test/jpeg.mod
PYTHONOBJ=test/python.obj
SFTPSERVER=test/sftp-server
LIBPERL=test/libperl.so.5.18
VGPRELOAD=test/vgpreload_memcheck-x86-linux.so

define(){
    IFS=$'\n' read -r -d '' "${1}" || true
}

success(){
    printf "\xE2\x9C\x94  Outputs are identical! %s\n" "$1"
}

failure(){
    printf "\u2718  Failed: %s\n" "$1"
    printf "%s\n\n" "$2"
}

define FILES <<EOF
${NETBSD32}
${SOLARIS32}
${SORTIX32}
${SPARCBIGENDIAN32}
${UBUNTU64}
${FILE64}
${OBJFILE}
${JPGFILE}
${PYTHONOBJ}
${SFTPSERVER}
${LIBPERL}
${VGPRELOAD}
EOF

printf "Cleaning up Obj files... "
ERROR=$(make clean) && printf "\xE2\x9C\x94  OK!\n\n" || printf "%s\n" "${ERROR}"
echo "Task 0:"
printf "Buiding executable... "
ERROR=$(make 0-hreadelf) && printf "\xE2\x9C\x94  OK!\n\n" || printf "%s\n" "${ERROR}"
while read -r file; do
    ERROR=$(diff -s <(readelf -W -h "${file}") <(./0-hreadelf "${file}")) &&
	success "${file}" || printf "%s" "${ERROR}"
done <<< "${FILES}"

echo
echo "==============================================="
echo
echo "Task 1:"
printf "Buiding executable... "
ERROR=$(make 1-hreadelf) && printf "\xE2\x9C\x94  OK!\n\n" || printf "%s\n" "${ERROR}"
while read -r file; do
    ERROR=$(diff -s <(readelf -W -S "${file}") <(./1-hreadelf "${file}")) &&
	success "${file}" || failure "${file}" "${ERROR}\n"
done <<< "${FILES}"

echo
echo "==============================================="
echo
echo "Task 2:"
printf "Buiding executable... "
ERROR=$(make 2-hreadelf) && printf "\xE2\x9C\x94  OK!\n\n" || printf "%s\n" "${ERROR}"
while read -r file; do
    ERROR=$(diff -s <(readelf -W -l "${file}") <(./2-hreadelf "${file}")) &&
	success "${file}" || failure "${file}" "${ERROR}\n"
done <<< "${FILES}"

echo
echo "==============================================="
echo
echo "Task 3:"
printf "Buiding executable... "
ERROR=$(make 100-hreadelf) && printf "\xE2\x9C\x94  OK!\n\n" || printf "%s\n" "${ERROR}"
while read -r file; do
    ERROR=$(diff -s <(readelf -W -s "${file}") <(./100-hreadelf "${file}")) &&
	success "${file}" || failure "${file}" "${ERROR}\n"
done <<< "${FILES}"
exit
