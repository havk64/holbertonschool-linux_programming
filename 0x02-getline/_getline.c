#include "_getline.h"

/**
 * read_fd - Reads a file descriptor and writes to a string
 * @fd: the file descriptor
 * @buf: the string to be written
 *
 * Return: On success, 0. On error, 1
 */
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

/**
 * _getline - Reads an entire line from a file descriptor
 * @fd: the file descriptor to read from
 *
 * Return: On success, one line from the file descriptor
 * On error, NULL
 */
char *_getline(int fd)
{
	char *buf;

	if (read_fd(fd, &buf) != 0)
		return (NULL);

	return (buf);
}
