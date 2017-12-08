#include "lcap.h"

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

static int write_heap(char *mem_path, char *addr, char *search_string,
	       char *replace_string)
{
	int fd, n, i;
	char *addr_begin, *addr_end, *buf;
	long int start, end, hsize;

	addr_begin = strtok(addr, "-");
	addr_end = strtok(NULL, "-");
	printf("\tAddr start [%s] | end [%s]\n", addr_begin, addr_end);
	start = strtol(addr_begin, NULL, 16);
	end = strtol(addr_end, NULL, 16);
	hsize = end - start;
	buf = malloc(hsize + 1);
	fd = open(mem_path, O_RDWR);
	if (fd < 0)
	{
		perror("Cannot open file");
		return (EXIT_FAILURE);
	}
	lseek(fd, start, SEEK_SET);
	n = read(fd, buf, hsize);
	for (i = 0; i < hsize; i++)
	{
		if (strstr((buf + i), search_string) != NULL)
			break;
		if (i == hsize)
		{
			printf("Can't find '%s'\n", search_string);
			return (EXIT_FAILURE);
		}
	}
	printf("[*] Found '%s' at %x\n", (buf + i), i);
	free(buf);
	lseek(fd, (start + i), SEEK_SET);
	printf("[*] Writing '%s' at %p\n", replace_string, (void *)(start + i));
	n = write(fd, replace_string, 10);
	close(fd);
	if (n != 10)
		return (EXIT_FAILURE);

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
	if (status < 0)
	{
		perror("status");
		return (status);
	}
	fclose(maps);
	return (EXIT_SUCCESS);
}
