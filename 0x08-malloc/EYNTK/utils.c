#include "naive.h"

/**
 * print_mem_map - prints the file /proc/<pid>/maps of runnin process
 *
 * Return: On success, 0. On failure, 1:
 */
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

/**
 * set_mode - set/get terminal attributes
 * @want_key: an integer representing true/false to get/set attributes
 *
 * Return: always void.
 */
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
	new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
}

/**
 * get_key - get user input keypress y/n
 * @no_timeout: an integer representing true/false to timeout
 *
 * Return: the user input character
 */
int get_key(int no_timeout)
{
	int c = 0;
	struct timeval tv;
	fd_set fs;

	tv.tv_usec = tv.tv_sec = 0;

	FD_ZERO(&fs);
	FD_SET(STDIN_FILENO, &fs);

	select(STDIN_FILENO + 1, &fs, 0, 0, no_timeout ? 0 : &tv);
	if (FD_ISSET(STDIN_FILENO, &fs))
	{
		c = getchar();
		set_mode(0);
	}
	return (c);
}
