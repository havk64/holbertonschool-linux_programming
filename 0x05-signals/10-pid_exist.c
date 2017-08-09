#include <signal.h>
#include <errno.h>

int pid_exist(pid_t pid)
{
	if (kill(pid, 0) == 0)
		return (1);
	else if (errno == ESRCH)
		return (0);
	else
		return (1);
}
