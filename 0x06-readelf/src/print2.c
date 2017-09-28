#include "readelf.h"

/**
 * print_type - prints the type of binary object file
 * @type: the byte representing the type of the binary file
 * Return: Always void.
 */
void print_type(uint16_t type)
{
	char *format = "  %-*s%s\n";

	switch (type)
	{
	case ET_NONE:
		/* An unknown type. */
		printf(format, width, "Type:", "NONE (None)");
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

/**
 * print_phoff - prints the program header offset
 * @phoff: the program header table's file offset in bytes
 * Return: Always void.
 */
void print_phoff(uint64_t phoff)
{
	char *title = "Start of program headers:";
	char *format = "  %-*s%lu (bytes into file)\n";

	printf(format, width, title, phoff);
}

/**
 * print_shoff - prints the section header offset
 * @shoff: the section header table's file offset in bytes
 * Return: Always void.
 */
void print_shoff(uint64_t shoff)
{
	char *title = "Start of section headers:";
	char *format = "  %-*s%lu (bytes into file)\n";

	printf(format, width, title, shoff);
}
