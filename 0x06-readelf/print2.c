#include "readelf.h"

/**
 * print_elf_version - prints the elf version (default to the first one)
 * @elfversion: the byte that represents the current elf version
 * Return: Always void.
 */
void print_file_version(uint32_t elfversion)
{
	char *format = "  %-*s0x%x\n";

	switch (elfversion)
	{
	case EV_NONE:		/* Invalid version */
		printf(format, width, "Version:", elfversion);
		break;
	case EV_CURRENT:	/* Current version */
		printf(format, width, "Version:", elfversion);
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
 * @phoff: the section header table's file offset in bytes
 * Return: Always void.
 */
void print_shoff(uint64_t shoff)
{
	char *title = "Start of section headers:";
	char *format = "  %-*s%lu (bytes into file)\n";

	printf(format, width, title, shoff);
}
