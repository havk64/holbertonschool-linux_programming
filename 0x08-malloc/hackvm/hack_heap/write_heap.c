#include <stdio.h>	/* for sprintf */
#include <fcntl.h>	/* for open */
#include <unistd.h>	/* for close */
#include <sys/ptrace.h>	/* for ptrace */
#include <stdlib.h>	/* for atoi */
#include <sys/wait.h>	/* for waitpid */

static uid_t uid, euid;

void do_setuid(void)
{
	int st;
	uid_t _uid, _euid;

#ifdef _POSIX_SAVED_IDS
	st = seteuid(euid);
#else
	st = setreuid(uid, euid);
#endif
	if (st < 0)
		perror("setuid error (do)");

	_uid = getuid();
	_euid = geteuid();
	printf("RUID: %u, EUID: %u\n", _uid, _euid);
}

void undo_setuid(void)
{
	int st;
	uid_t _uid, _euid;

#ifdef _POSIX_SAVED_IDS
	st = seteuid(uid);
#else
	st = setreuid(euid, uid);
#endif
	if (st < 0)
		perror("setuid error (undo)");

	_uid = getuid();
	_euid = geteuid();
	printf("RUID: %u, EUID: %u\n", _uid, _euid);
}

int main(int ac, char *argv[])
{
	int fd, mem;
	pid_t pid;
	char s[64];
	long pt;

	uid = getuid();
	euid = geteuid();
	printf("RUID: %u, EUID: %u\n", uid, euid);
	undo_setuid();
	if (ac < 3)
	{
		printf("Usage: ./%s <pid> <offset>\n", __FILE__);
		return (EXIT_FAILURE);
	}

	pid = atoi(argv[1]);
	sprintf(s, "/proc/%s/mem", argv[1]);

	do_setuid();
	fd = open(s, O_RDWR);
	if (fd < 0)
		perror("Error opening file");

	pt = ptrace(PTRACE_ATTACH, pid, NULL, NULL);
	undo_setuid();
	if (pt < 0)
		perror("Ptrace error");

	waitpid(pid, NULL, 0);

	mem = atoi(argv[2]);
	printf("Mem: %x\n", mem);
	lseek(fd, mem, SEEK_SET);
	write(fd, "holberton", 10);

	ptrace(PTRACE_DETACH, pid, NULL, NULL);
	close(fd);
	return (EXIT_SUCCESS);
}
