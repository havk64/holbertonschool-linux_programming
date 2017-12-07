#include "lcap.h"
#define msize 128

int main(int argc, char *argv[])
{
	pid_t pid;
	char maps_path[64], maps_line[lsize], mem_path[64], *line;
	FILE *maps;

	if (argc < 4)
	{
		printf("Usage: %s <pid> <search_string> <replace_string>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	pid = atoi(argv[1]);
	sprintf(maps_path, "/proc/%d/maps", pid);
	sprintf(mem_path, "/proc/%d/mem", pid);
	printf("[*] maps: %s\n", maps_path);
	printf("[*] mem: %s\n", mem_path);
	maps = fopen(maps_path, "r");
	if (maps == NULL)
	{
		perror("fopen");
		return (EXIT_FAILURE);
	}

	while ((line = fgets(maps_line, lsize, maps)))
	{
		if (strstr(line, "[heap]") != NULL)
			printf("%s", line);
	}
	fclose(maps);
	return (EXIT_SUCCESS);
}
