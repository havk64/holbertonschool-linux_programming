#include "naive.h"

int print_mem_map(void)
{

	FILE *maps;
	char maps_path[32], *line, buf[bsize];
	pid_t PID;

	PID = getpid();
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


void set_mode(int want_key)
{
	static struct termios old, new;

	if (!want_key)
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &old);
		return;
	}

	tcgetattr(STDIN_FILENO, &old);
	new = old;
	new.c_lflag &= ~(ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
}

