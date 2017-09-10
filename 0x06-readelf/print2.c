#include "readelf.h"

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

