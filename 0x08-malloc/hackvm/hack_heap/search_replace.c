#include "lcap.h"
#define msize 128

int main(int argc, char *argv[])
{
	pid_t pid;
	char maps_file[msize], *line;
	FILE *maps;

	if (argc < 4)
	{
		printf("Usage: %s <pid> <search_string> <replace_string>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	pid = atoi(argv[1]);
	sprintf(maps_file, "/proc/%d/maps", pid);
	maps = fopen(maps_file, "r");
	if (maps == NULL)
	{
		perror("fopen");
		return (EXIT_FAILURE);
	}

	while ((line = fgets(maps_file, msize, maps)))
	{
		if (strstr(line, "[heap]") != NULL)
			printf("%s", line);
	}
	fclose(maps);
	return (EXIT_SUCCESS);
}
