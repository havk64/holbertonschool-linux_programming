# 0x06. C - ELF: readelf

System programming & Algorithm ― Linux programming

### Task 0: ELF file header

The program `0-hreadelf` display the information contained in the header of
a given Elf binary file

It's output is exactly the same as the output of the command `$ readelf -W -h <elf file>`

The `Makefile` compile and creates this executable as follows:

```
$ make 1-hreadelf

$ ./0-hreadelf test_files/netbsd32

ELF Header:
  Magic:   7f 45 4c 46 01 01 01 02 00 00 00 00 00 00 00 00
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - NetBSD
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           Intel 80386
  Version:                           0x1
  Entry point address:               0x80484c0
  Start of program headers:          52 (bytes into file)
  Start of section headers:          2752 (bytes into file)
  Flags:                             0x0
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         6
  Size of section headers:           40 (bytes)
  Number of section headers:         24
  Section header string table index: 21


$ .0-hreadelf test_files/sparcbigendian32

ELF Header:
  Magic:   7f 45 4c 46 01 02 01 00 00 00 00 00 00 00 00 00
  Class:                             ELF32
  Data:                              2's complement, big endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           Sparc
  Version:                           0x1
  Entry point address:               0x10d20
  Start of program headers:          52 (bytes into file)
  Start of section headers:          84560 (bytes into file)
  Flags:                             0x0
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         6
  Size of section headers:           40 (bytes)
  Number of section headers:         24
  Section header string table index: 23

$ ./0-hreadelf /test_files/ubuntu64

ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x400600
  Start of program headers:          64 (bytes into file)
  Start of section headers:          6936 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         9
  Size of section headers:           64 (bytes)
  Number of section headers:         31
  Section header string table index: 28
```

### Task 1: ELF sections' headers

The program `1-hreadelf` displays the information about the `Sections Header Table` of a
given Elf binary file

It's output is exactly the same as the output of the command `$ readelf -W -S <elf file>`

The `Makefile` compile and creates this executable as follows:

```
$ make 1-hreadelf

$ ./1-hreadelf test_files/netbsd32

There are 24 section headers, starting at offset 0xac0:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .interp           PROGBITS        080480f4 0000f4 000017 00   A  0   0  1
  [ 2] .note.netbsd.ident NOTE            0804810c 00010c 000034 00   A  0   0  4
  [ 3] .hash             HASH            08048140 000140 0000a0 04   A  4   0  4
  [ 4] .dynsym           DYNSYM          080481e0 0001e0 000150 10   A  5   1  4
  [ 5] .dynstr           STRTAB          08048330 000330 0000bf 00   A  0   0  1
  [ 6] .rel.got          REL             080483f0 0003f0 000030 08   A  4  16  4
  [ 7] .rel.plt          REL             08048420 000420 000020 08   A  4   9  4
  [ 8] .init             PROGBITS        08048440 000440 000030 00  AX  0   0  4
  [ 9] .plt              PROGBITS        08048470 000470 000050 04  AX  0   0  4
  [10] .text             PROGBITS        080484c0 0004c0 000304 00  AX  0   0  4
  [11] .fini             PROGBITS        080487c4 0007c4 00001d 00  AX  0   0  4
  [12] .rodata           PROGBITS        08048800 000800 0000a7 00   A  0   0 32
  [13] .data             PROGBITS        080498a8 0008a8 000014 00  WA  0   0  4
  [14] .ctors            PROGBITS        080498bc 0008bc 000008 00  WA  0   0  4
  [15] .dtors            PROGBITS        080498c4 0008c4 000008 00  WA  0   0  4
  [16] .got              PROGBITS        080498cc 0008cc 000034 04  WA  0   0  4
  [17] .dynamic          DYNAMIC         08049900 000900 000088 08  WA  5   0  4
  [18] .bss              NOBITS          08049988 000988 00000c 00  WA  0   0  4
  [19] .note             NOTE            08049994 000988 000050 00      0   0  1
  [20] .ident            PROGBITS        080499e4 0009d8 000035 00      0   0  1
  [21] .shstrtab         STRTAB          00000000 000a0d 0000b1 00      0   0  1
  [22] .symtab           SYMTAB          00000000 000e80 000390 10     23  27  4
  [23] .strtab           STRTAB          00000000 001210 000125 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings)
  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)

$ ./1-hreadelf test_files/sparcbigendian32

There are 24 section headers, starting at offset 0x14a50:

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .interp           PROGBITS        000100f4 0000f4 000013 00   A  0   0  1
  [ 2] .note.ABI-tag     NOTE            00010108 000108 000020 00   A  0   0  4
  [ 3] .hash             HASH            00010128 000128 00019c 04   A  4   0  4
  [ 4] .dynsym           DYNSYM          000102c4 0002c4 000400 10   A  5   1  4
  [ 5] .dynstr           STRTAB          000106c4 0006c4 00025a 00   A  0   0  1
  [ 6] .gnu.version      VERSYM          0001091e 00091e 000080 02   A  4   0  2
  [ 7] .gnu.version_r    VERNEED         000109a0 0009a0 000060 00   A  5   2  4
  [ 8] .rela.dyn         RELA            00010a00 000a00 000054 0c   A  4   0  4
  [ 9] .rela.plt         RELA            00010a54 000a54 00027c 0c   A  4  20  4
  [10] .init             PROGBITS        00010ce0 000ce0 000038 00  AX  0   0 32
  [11] .text             PROGBITS        00010d20 000d20 01226c 00  AX  0   0 32
  [12] .fini             PROGBITS        00022fa0 012fa0 000030 00  AX  0   0 32
  [13] .rodata           PROGBITS        00022fd0 012fd0 0013a0 00   A  0   0  8
  [14] .data             PROGBITS        00034370 014370 000270 00  WA  0   0  4
  [15] .eh_frame         PROGBITS        000345e0 0145e0 000004 00   A  0   0  4
  [16] .dynamic          DYNAMIC         000345e4 0145e4 0000d0 08  WA  5   0  4
  [17] .ctors            PROGBITS        000346b4 0146b4 000008 00  WA  0   0  4
  [18] .dtors            PROGBITS        000346bc 0146bc 000008 00  WA  0   0  4
  [19] .jcr              PROGBITS        000346c4 0146c4 000004 00  WA  0   0  4
  [20] .plt              PROGBITS        000346c8 0146c8 0002b0 0c WAX  0   0  4
  [21] .got              PROGBITS        00034978 014978 000020 04  WA  0   0  4
  [22] .bss              NOBITS          00034998 014998 0442e0 00  WA  0   0  8
  [23] .shstrtab         STRTAB          00000000 014998 0000b7 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings)
  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)

```
