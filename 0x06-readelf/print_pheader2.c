#include "readelf.h"

void print_segment_mapping(ElfN_Phdr *phdr, ElfN_Ehdr *ehdr, char *strtab)
{
	uint16_t i;

	(void)(phdr);
	(void)(strtab);
	printf("\nSection to Segment mapping:\n");
	printf(" Segment Sections...\n");
	for (i = 0; i < ehdr->e_phnum; i++)
	{
		printf("  %2.2u     ", i);
		printf("\n");
	}
}
