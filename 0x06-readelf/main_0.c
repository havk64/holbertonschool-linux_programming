#include "readelf.h"

static void check(int n, char *error)
{
	if (n < 0)
	{
		perror(error);
		exit(EXIT_FAILURE);
	}
}

int is_elf(unsigned char *magic)
{
	if (magic[0] == 0x7f &&
	    magic[1] == 0x45 &&
	    magic[2] == 0x4c &&
	    magic[3] == 0x46)
		return (1);
	else
		return (0);
}

int get_stat(char *filename)
{
	int fd, st;
	struct stat sbuf;

	fd = open(filename, O_RDONLY);
	check(fd, "Error opening file");

	st = stat(filename, &sbuf);
	check(st, "Stat error");

	if ((sbuf.st_mode & S_IFMT) != S_IFREG)
	{
		printf("%s is not a regular file\n", filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

ElfClass get_class(char c)
{
	return ((c == 2) ? ELF64 : ELF32);
}

int main(int argc, char *argv[])
{
	int fd;

	if (argc != 2)
	{
		printf("Usage: %s <ELF binary file>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	fd = get_stat(argv[1]);
	parse_elf(fd);

	close(fd);
	return (0);
}
