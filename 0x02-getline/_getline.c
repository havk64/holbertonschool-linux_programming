#include "_getline.h"

/**
 * _realloc - Extends a heap memory block
 * @str: the original memory block to be extended
 * @size: the requested new size
 *
 * Return: On success, a new extended heap memory block
 * On error, return NULL
 */
void *_realloc(char *str, size_t size)
{
	char *new;

	new = malloc(sizeof(char) * size);
	if (new)
	{
		memcpy(new, str, (size - BUF_SIZE));
		free(str);
		return (new);
	}
	return (NULL);
}

/**
 * read_fd - Reads a file descriptor and writes to a string
 * @fd: the file descriptor
 * @buf: the string to be written
 *
 * Return: On success, 0. On error, 1
 */
int read_fd(int fd, char **buf)
{
	int i, read_status;
	char c;
	size_t size = BUF_SIZE;

	*buf = malloc(sizeof(char) * size);
	if (*buf == NULL)
		return (1);
	c = 0;
	for (i = 0; c != '\n'; i++)
	{
		read_status = read(fd, &c, READ_SIZE);
		if (read_status == -1)
		{
			write(1, "Nothing was read\n", 17);
			return (1);
		}

		if (read_status == 0)
		{
			if (i > 0)
			{
				i++;
				break;
			}
			free(*buf);
			return (1);
		}
		if (i >= (int)size)
		{
			size += BUF_SIZE;
			*buf = _realloc(*buf, size);
			if (*buf == NULL)
				return (1);
		}
		(*buf)[i] = c;
	}
	(*buf)[i - 1] = 0;
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
