#include "readelf.h"

/**
 * parse_elf_header - parses a elf file to print its reader
 * @fd: the file descriptor of the binary file
 * Return: Always Void
 */
void parse_elf_header(int fd)
{
	FILE *stream;
	ElfN_Ehdr ehdr;
	void (*fill_Ehdr)(ElfN_Ehdr*, FILE*, int);
	ssize_t n;
	ElfClass elfclass;

	stream = fdopen(fd, "rb");
	if (stream == NULL)
	{
		perror("Error creating file stream");
		exit(EXIT_FAILURE);
	}

	n = fread(ehdr.e_ident, EI_NIDENT, 1, stream);
	if (!is_elf(ehdr.e_ident) || n != 1)
	{
		printf("Not an ELF file - it has the wrong magic bytes at the start\n");
		exit(EXIT_FAILURE);
	}

	elfclass = get_class(ehdr.e_ident[EI_CLASS]);
	fill_Ehdr = (elfclass == ELF32) ? &parse_32 : &parse_64;
	(*fill_Ehdr)(&ehdr, stream, ehdr.e_ident[EI_DATA]);
	print_header(&ehdr);
	fclose(stream);
}

/**
 * machine_name - returns a const string with the the machine name
 * @e_machine: the byte representing the system architecture
 * Return: a constant string of the machine name
 */
static char *machine_name(uint16_t e_machine)
{
	static char buf[64];

	switch (e_machine)
	{
	case EM_NONE:		return "None";
	case EM_M32:		return "WE32100";
	case EM_SPARC:		return "Sparc";
	case EM_386:		return "Intel 80386";
	case EM_860:		return "Intel 80860";
	case EM_68K:		return "MC68000";
	case EM_88K:		return "MC88000";
	case EM_MIPS:		return "MIPS R3000";
	case EM_PARISC:		return "HPPA";
	case EM_SPARC32PLUS:	return "Sparc v8+";
	case EM_PPC:		return "PowerPC";
	case EM_PPC64:		return "PowerPC64";
	case EM_ARM:		return "ARM";
	case EM_SH:		return "Renesas / SuperH SH";
	case EM_S390:		return "IBM S/390";
	case EM_SPARCV9:	return "Sparc v9";
	case EM_IA_64:		return "Intel IA-64";
	case EM_X86_64:		return "Advanced Micro Devices X86-64";
	case EM_VAX:		return "Digital VAX";
	default:
		snprintf(buf, sizeof(buf), "<unknown>: 0x%x", e_machine);
		return (buf);
	}
}

/**
 * print_magic - print the elf magic number
 * @e_ident: the pointer to the elf identity header
 * Return: Always Void
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%2.2x ", e_ident[i]);
	}
	printf("\n");
}

/**
 * print_header - prints the whole header of the elf binary file
 * @header: the pointer to a elf binary struct representing its header
 * Return: Always Void.
 */
void print_header(ElfN_Ehdr *header)
{
	print_identity(header->e_ident);
	print_type(header->e_type);
	printf("  %-*s%s\n", width, "Machine:", machine_name(header->e_machine));
	printf("  %-*s0x%x\n", width, "Version:", header->e_version);
	printf("  %-*s0x%lx\n", width, "Entry point address:",
	       header->e_entry);
	print_phoff(header->e_phoff);
	print_shoff(header->e_shoff);
	printf("  %-*s0x%x\n", width, "Flags:", header->e_flags);
	printf("  %-*s%d (bytes)\n", width, "Size of this header:", header->e_ehsize);
	printf("  %-*s%d (bytes)\n", width, "Size of program headers:",
	       header->e_phentsize);
	printf("  %-*s%d\n", width, "Number of program headers:", header->e_phnum);
	printf("  %-*s%d (bytes)\n", width, "Size of section headers:",
	       header->e_shentsize);
	printf("  %-*s%d\n", width, "Number of section headers:", header->e_shnum);
	printf("  %-*s%d\n", width, "Section header string table index:",
	       header->e_shstrndx);
}
