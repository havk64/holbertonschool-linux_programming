#include "readelf.h"

void print_class(unsigned char class)
{
	char *format = "  %-*s%s\n";

	/* printf("  %-*s", width, "Class:"); */
	switch (class)
	{
	case ELFCLASS32:
		printf(format, width, "Class:", "ELF32");
		break;
	case ELFCLASS64:
		printf(format, width, "Class:", "ELF64");
		break;
	case ELFCLASSNONE:
		printf(format, width, "Class:", "Other");
		break;
	}
}

void print_data(unsigned char data)
{
	char *format = "  %-*s%s\n";

	/* printf("  %-*s", width, "Data:"); */
	switch (data)
	{
	case ELFDATANONE:
		printf(format, width, "Data:", "Unknown");
		break;
	case ELFDATA2LSB:
		printf(format, width, "Data:", "2's complement, little endian");
		break;
	case ELFDATA2MSB:
		printf(format, width, "Data:", "2's complement, big endian");
		break;
	}
}

void print_version(unsigned char version)
{
	char *format = "  %-*s%s\n";

	switch (version)
	{
	case EV_NONE:
		printf(format, width, "Version:", "Invalid version");
		break;
	case EV_CURRENT:
		printf(format, width, "Version:", "1 (current)");
		break;
	}
}

void print_osabi(unsigned char osabi)
{
	char *format = "  %-*s%s\n";

	switch (osabi)
	{
	case ELFOSABI_SYSV:		/* Alias to ELFOSABI_NONE */
		printf(format, width, "OS/ABI:", "UNIX - System V");
		break;
	case ELFOSABI_HPUX:		/* HP-UX ABI; */
		printf(format, width, "OS/ABI:", "HP-UX");
		break;
	case ELFOSABI_NETBSD:		/* NetBSD ABI; */
		printf(format, width, "OS/ABI:", "NetBSD");
		break;
		printf(format, width, "OS/ABI:", "Linux ABI");
	case ELFOSABI_LINUX:		/* Compatibility alias to ELFOSABI_GNU */
		break;
	case ELFOSABI_SOLARIS:		/* Solaris ABI; */
		printf(format, width, "OS/ABI:", "Solaris");
		break;
	case ELFOSABI_IRIX:		/* IRIX ABI; */
		printf(format, width, "OS/ABI:", "IRIX ABI");
		break;
	case ELFOSABI_FREEBSD:		/* FreeBSD ABI; */
		printf(format, width, "OS/ABI:", "FreeBSD ABI");
		break;
	case ELFOSABI_TRU64:		/* TRU64 UNIX ABI; */
		printf(format, width, "OS/ABI:", "TRU64 UNIX ABI");
		break;
	case ELFOSABI_ARM:		/* ARM architecture ABI; */
		printf(format, width, "OS/ABI:", "ARM ABI");
		break;
	case ELFOSABI_STANDALONE:	/* Stand-alone (embedded) ABI; */
		printf(format, width, "OS/ABI:", "STANDALONE ABI");
		break;
	}
}

void print_type(uint16_t data)
{
	char *format = "  %-*s%s\n";

	switch (data)
	{
	case ET_NONE:
		/* An unknown type. */
		printf(format, width, "Type:", "unknown");
		break;
	case ET_REL:
		/* A relocatable file. */
		printf(format, width, "Type:", "REL (Relocatable file)");
		break;
	case ET_EXEC:
		/* An executable file. */
		printf(format, width, "Type:", "EXEC (Executable file)");
		break;
	case ET_DYN:
		/* A shared object. */
		printf(format, width, "Type:", "DYN (Shared object file)");
		break;
	case ET_CORE:
		/* A core file. */
		printf(format, width, "Type:", "CORE (Core file)");
		break;
	}
}
