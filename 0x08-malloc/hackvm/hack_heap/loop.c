#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char *s;
	unsigned long int i;
	pid_t pid;

	pid = getpid();
	s = strdup("Holberton");
	if (s == NULL)
	{
		fprintf(stderr, "Can't allocate mem with malloc\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (s)
	{
		printf("PID: %d [%lu] %s (%p)\n", pid, i, s, (void *)s);
		sleep(1);
		i++;
	}
	return (EXIT_SUCCESS);
}
