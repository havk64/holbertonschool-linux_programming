#include "naive.h"

int print_mem_map(void)
{

	FILE *maps;
	char maps_path[32], *line, buf[bsize];
	pid_t PID;

	PID = getpid();
	printf("Content of /proc/%d/maps file at this time is:\n", PID);
	sprintf(maps_path, "/proc/%d/maps", PID);
	maps = fopen(maps_path, "r");
	if (maps == NULL)
	{
		perror("fopen");
		return (EXIT_FAILURE);
	}
	while ((line = fgets(buf, bsize, maps)))
		printf("%s", line);

	return (EXIT_SUCCESS);
}
