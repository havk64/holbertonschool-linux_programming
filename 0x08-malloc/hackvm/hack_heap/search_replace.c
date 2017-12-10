#include "lcap.h"

/*
 * tokenize - split a string in tokens separated by specified delimiter
 * @str: the string to be tokenized
 *
 * Return: a pointer to an array of strings or NULL on failure
 */
static char **tokenize(char *str)
{
	char **s;
	int i;
	char *delim = " ";

	s = malloc(sizeof(char *) * 6);
	if (s == NULL)
		return (NULL);

	s[0] = strtok(str, delim);
	for (i = 1; i < 6; i++)
		s[i] = strtok(NULL, delim);

	return (s);
}

/*
 * parse_line - parses the line that contain heap info
 * @line: a pointer to the string
 *
 * Return: On success it return the a pointer to an array of strings
 * On failure it return NULL
 */
static char *parse_line(char *line)
{
	int n;
	char **s, *addr, *perm, *offset, *inode, *pathname, *range;

	s = tokenize(line);
	printf("[*] Found [heap]:\n");
	addr = s[0];
	perm = s[1];
	offset = s[2];
	inode = s[4];
	pathname = s[5];
	printf("\tpathname = %s", pathname);
	printf("\tadressesses = %s\n", addr);
	printf("\tpermissions = %s\n", perm);
	printf("\toffset = %s\n", offset);
	printf("\tinode = %s\n", inode);
	if (perm[0] != 'r' || perm[1] != 'w')
	{
		printf("[*] %s does not have read/write permission", pathname);
		free(s);
		return (NULL);
	}

	n = strlen(addr);
	range = malloc(n + 1);
	if (range == NULL)
	{
		free(s);
		return (NULL);
	}

	strcpy(range, addr);
	free(s);
	return (range);
}

/*
 * read_heap - read the heap of the executable and find the address of given
 * string
 * @fd: a file descriptor of the /proc/<pid>/mem file
 * @start: the start address of the heap
 * @search_string: the string to be searched
 * @hsize: the size the heap
 *
 * Return: On success the offset from the start of the heap where the string is
 * found. On failure, -1
 */
static
int read_heap(int fd, long int start, char *search_string, long int hsize)
{
	char *buf;
	int i, n;

	lseek(fd, start, SEEK_SET);
	buf = malloc(hsize + 1);
	n = read(fd, buf, hsize);
	if (n != hsize)
		perror("read");

	for (i = 0; i < hsize; i++)
	{
		if (strstr((buf + i), search_string) != NULL)
			break;
		if (i == (hsize - 1))
		{
			printf("Can't find '%s'\n", search_string);
			free(buf);
			return (-1);
		}
	}
	printf("[*] Found '%s' at %x\n", (buf + i), i);
	free(buf);
	return (i);
}

static int write_heap(char *mem_path, char *addr, char *search_string,
	       char *replace_string)
{
	int fd, n, offset, len;
	char *addr_begin, *addr_end;
	long int start, end, hsize;

	addr_begin = strtok(addr, "-");
	addr_end = strtok(NULL, "-");
	printf("\tAddr start [%s] | end [%s]\n", addr_begin, addr_end);
	start = strtol(addr_begin, NULL, 16);
	end = strtol(addr_end, NULL, 16);
	hsize = end - start;
	free(addr);
	fd = open(mem_path, O_RDWR);
	if (fd < 0)
	{
		perror("Cannot open file");
		return (EXIT_FAILURE);
	}

	offset = read_heap(fd, start, search_string, hsize);
	if (offset < 0)
	{
		close(fd);
		return (EXIT_FAILURE);
	}

	len = strlen(replace_string);
	lseek(fd, (start + offset), SEEK_SET);
	printf("[*] Writing '%s' at %p\n", replace_string, (void *)(start + offset));
	n = write(fd, replace_string, len + 1);
	close(fd);
	if (n < len + 1)
	{
		printf("Number of bytes written don't match string size\n");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	pid_t pid;
	char maps_path[64], maps_line[lsize], mem_path[64], *line, *range;
	FILE *maps;
	int status;

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
		if (strstr(line, "[heap]") != NULL)
		{
			range = parse_line(line);
			if (range == NULL)
			{
				fclose(maps);
				return (EXIT_FAILURE);
			}
		}
	status = write_heap(mem_path, range, argv[2], argv[3]);
	fclose(maps);
	if (status != 0)
		return (status);

	return (EXIT_SUCCESS);
}
