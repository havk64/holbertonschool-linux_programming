#include "readelf.h"

void
print_segment_mapping(ElfN_Phdr *phdr, ElfN_Shdr *shdr, ElfN_Ehdr *ehdr,
		      char *strtab)
{
	uint16_t i, j;
	ElfN_Phdr segment;
	ElfN_Shdr section;

	printf("\n Section to Segment mapping:\n");
	printf("  Segment Sections...\n");
	for (i = 0; i < ehdr->e_phnum; i++)
	{
		printf("   %2.2u     ", i);
		for (j = 0; j < ehdr->e_shnum; j++)
		{
			segment = *(phdr + i);
			section = *(shdr + j);
			if (section.sh_name != 0 &&
			    section.sh_offset >= segment.p_offset &&
			    section.sh_offset + section.sh_size <=
			    segment.p_offset + segment.p_memsz)
				printf("%s ", strtab + section.sh_name);
		}
		printf("\n");
	}
}
