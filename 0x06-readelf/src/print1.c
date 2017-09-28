#include "readelf.h"

/**
 * print_identity - prints the elf identity header
 * @e_ident: the first 16 bytes of the elf binary file
 * Return: Always Void.
 */
void print_identity(unsigned char *e_ident)
{
	print_magic(e_ident);
	print_class(e_ident[EI_CLASS]);
	print_data(e_ident[EI_DATA]);
	print_version(e_ident[EI_VERSION]);
	print_osabi(e_ident[EI_OSABI]);
	printf("  %-*s%d\n", width, "ABI Version:",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_class - prints the elf class
 * @class: the byte representing the elf class
 * Return: Always void.
 */
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

/**
 * print_data - prints the elf's endianess
 * @data: the byte representing the endianess of an elf file
 * Return: Always void.
 */
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

/**
 * print_version - prints the elf version
 * @version: the byte representing the elf version
 * Return: Always void.
 */
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

/**
 * print_osabi - prints the target OS ABI
 * @osabi: the byte representing the OSABI
 * Return: Always void.
 */
void print_osabi(unsigned char osabi)
{
	char *format = "  %-*s%s\n";

	switch (osabi)
	{
	case ELFOSABI_SYSV:		/* Alias to ELFOSABI_NONE */
		printf(format, width, "OS/ABI:", "UNIX - System V");
		break;
	case ELFOSABI_HPUX:		/* HP-UX ABI; */
		printf(format, width, "OS/ABI:", "UNIX - HP-UX");
		break;
	case ELFOSABI_NETBSD:		/* NetBSD ABI; */
		printf(format, width, "OS/ABI:", "UNIX - NetBSD");
		break;
	case ELFOSABI_LINUX:		/* Compatibility alias to ELFOSABI_GNU */
		printf(format, width, "OS/ABI:", "UNIX - GNU");
		break;
	case ELFOSABI_SOLARIS:		/* Solaris ABI; */
		printf(format, width, "OS/ABI:", "UNIX - Solaris");
		break;
	case ELFOSABI_IRIX:		/* IRIX ABI; */
		printf(format, width, "OS/ABI:", "UNIX - IRIX");
		break;
	case ELFOSABI_FREEBSD:		/* FreeBSD ABI; */
		printf(format, width, "OS/ABI:", "UNIX - FreeBSD");
		break;
	case ELFOSABI_TRU64:		/* TRU64 UNIX ABI; */
		printf(format, width, "OS/ABI:", "UNIX - TRU64");
		break;
	case ELFOSABI_ARM:		/* ARM architecture ABI; */
		printf(format, width, "OS/ABI:", "ARM");
		break;
	case ELFOSABI_STANDALONE:	/* Stand-alone (embedded) ABI; */
		printf(format, width, "OS/ABI:", "Standalone App");
		break;
	default:
		printf("  %-*s<unknown: %x>\n", width, "OS/ABI:", osabi);
	}
}
