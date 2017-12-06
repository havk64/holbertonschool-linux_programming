#include "lcap.h"

int main(int ac, char *argv[])
{
	int fd, mem, n;
	char s[64];

	if (ac < 3)
	{
		printf("Usage: %s <pid> <offset>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	sprintf(s, "/proc/%s/mem", argv[1]);

	fd = open(s, O_RDWR);
	if (fd < 0)
		perror("Error opening file");

	mem = atoi(argv[2]);
	lseek(fd, mem, SEEK_SET);
	n = write(fd, "Alexandro", 10);
	if (n == 10)
		printf("Hacked!\n");

	close(fd);
	return (EXIT_SUCCESS);
}
