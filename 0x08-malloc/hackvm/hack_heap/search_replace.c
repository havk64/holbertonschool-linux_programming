#include "lcap.h"

char **tokenize(char *str)
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

int parse_line(char *line)
{
	char **s, *addr, *perm, *offset, *inode, *pathname;
	char *addr_begin, *addr_end;

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
		return (EXIT_FAILURE);
	}

	addr_begin = strtok(addr, "-");
	addr_end = strtok(NULL, "-");
	printf("\tAddr start [%s] | end [%s]\n", addr_begin, addr_end);
	free(s);
	return (EXIT_SUCCESS);
}
int main(int argc, char *argv[])
{
	pid_t pid;
	char maps_path[64], maps_line[lsize], mem_path[64], *line;
	FILE *maps;

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
	{
		if (strstr(line, "[heap]") != NULL)
		{
			if (parse_line(line) < 0)
			{
				fclose(maps);
				return (EXIT_FAILURE);
			}
		}
	}
	fclose(maps);
	return (EXIT_SUCCESS);
}
