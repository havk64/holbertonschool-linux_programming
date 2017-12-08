#include "lcap.h"
#define lsize 128

int fieldlen(char *str)
{
	int i = 0;

	while (str[i] != 0 && str[i] != 32)
		i++;

	return (i);
}
char **split_string(char *str)
{
	int i = 0, fsize = 0, index = 0;
	char **s;

	s = malloc(sizeof(char *) * 6);
	if (s == NULL)
		return (NULL);

	while (*(str + i))
	{
		while (*(str + i) == 32)
			i++;

		fsize = fieldlen(str + i);
		s[index] = malloc(fsize + 1);
		if (s[index] == NULL)
			return (NULL);

		strncpy(s[index], (str + i), fsize);
		s[index][fsize] = 0;
		i += fsize;
		index++;
	}
	return (s);
}

void free_array(char **s)
{
	int i;

	for (i = 0; i < 6; i++)
		free(s[i]);

	free(s);
}
int parse_line(char *line)
{
	char **s, *addr, *perm, *offset, *inode, *pathname;

	s = split_string(line);
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
	free_array(s);
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
