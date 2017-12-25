/* Private anonymous mapping example using mmap syscall */
#include "naive.h"

static inline void errExit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int main(void)
{
	int ret = -1;
	char *addr;

	printf("Private anonymous mapping example\n");
	printf("Before mmap\n");
	printf("(Open new terminal window and type:)\n");
	printf("$ cat /proc/%d/maps\n", getpid());
	getchar();

	addr = NULL;
	addr = mmap(NULL, (size_t)132 * 1024, PROT_READ | PROT_WRITE,
		   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (addr == MAP_FAILED)
		errExit("mmap");

	printf("After mmap\n");
	printf("(Again...)\n");
	getchar();

	/* Unmap mapped region. */
	ret = munmap(addr, (size_t)132 * 1024);
	if (ret == -1)
		errExit("munmap");
	printf("After munmap\n");
	printf("(Once more...)\n");
	getchar();
	printf("Bye!\n");
	return (0);
}
