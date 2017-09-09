#include "readelf.h"

void print_machine(uint16_t data)
{
	switch (data)
	{
	case EM_NONE:		/* An unknown machine */
		printf("(None)\n");
		break;
	case EM_M32:		/* AT&T WE 32100 */
		printf("WE32100\n");
		break;
	case EM_SPARC:		/* Sun Microsystems SPARC */
		printf("Sparc\n");
		break;
	case EM_386:		/* Intel 80386 */
		printf("Intel 80386\n");
		break;
	case EM_68K:		/* Motorola 68000 */
		printf("MC68000\n");
		break;
	case EM_88K:		/* Motorola 88000 */
		printf("MC88000\n");
		break;
	case EM_860:		/* Intel 80860 */
		printf("Intel 80860\n");
		break;
	case EM_MIPS:		/* MIPS RS3000 (big-endian only) */
		printf("MIPS R3000\n");
		break;
	case EM_PARISC:		/* HP/PA */
		printf("HPPA\n");
		break;
	case EM_SPARC32PLUS:	/* SPARC with enhanced instruction set */
		printf("Sparc v8+\n");
		break;
	case EM_PPC:		/* PowerPC */
		printf("PowerPC\n");
		break;
	case EM_PPC64:		/* PowerPC 64-bit */
		printf("PowerPC64\n");
		break;
	}
}

void print_file_version(uint32_t data)
{
	char *format = "  %-*s0x%x\n";

	switch (data)
	{
	case EV_NONE:		/* Invalid version */
		printf(format, width, "Version:", data);
		break;
	case EV_CURRENT:	/* Current version */
		printf(format, width, "Version:", data);
		break;
	}
}

void print_phoff(uint64_t e_phoff)
{
	char *title = "Start of program headers:";
	char *format = "  %-*s%lu (bytes into file)\n";

	printf(format, width, title, e_phoff);
}

void print_shoff(uint64_t e_shoff)
{
	char *title = "Start of section headers:";
	char *format = "  %-*s%lu (bytes into file)\n";

	printf(format, width, title, e_shoff);
}

