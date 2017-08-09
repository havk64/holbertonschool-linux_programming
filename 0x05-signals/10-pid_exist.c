#include <signal.h>
#include <errno.h>

/**
 * pid_exist - Check if a given pid exits
 * @pid: the pid to check for
 *
 * Return: On success, 1. On error, 0
 */
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) == 0 ? 1 : (errno == ESRCH ? 0 : 1));
}
