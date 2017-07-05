#include "_getline.h"

int read_fd(int fd, char *buf)
{
	int i;
	char c;

	c = 0;
	for (i = 0; c != '\n'; i++)
	{
		if (read(fd, &c, READ_SIZE) == 0)
		{
			free(buf);
			return (1);
		}
		buf[i] = c;
	}
	buf[i - 1] = 0;
	return (0);
}

char *_getline(int fd)
{
	char *buf;

	buf = malloc((BUF_SIZE) * sizeof(char));
	if (buf == NULL)
		return (NULL);

	if (read_fd(fd, buf) != 0)
		return (NULL);

	return (buf);
}
