/*
 * In this example I send a signal (SIGINT, SIGSTOP, SIGTERM, NULL) to another process
 * using th syscall kill(2).
 * 
 * INFOS:
 * 1- The term kill was chosen because the default action of most of the 
 * signals that were available on early UNIX implementations was to terminate the process
 * 
 * 2- kill(pid_t pid , int sig ) = 0 if (OK) : -1 if error
 * if pid > 0 => Signal send to specified process id (pid)
 * if pid == 0 => Signal send to all process on the same group
 */

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>

int main(void)
{
	pid_t pid_process = 33226; // This just an exmaple, but for a generate code you should use popen/pidof
	if (kill(pid_process, SIGTSTP) == -1)
		perror("kill");
	
	/* Now we check if process 32613 (firefox) exists */
	pid_t pid_firefox = 33226;
	errno = 0;
	kill(pid_firefox, 0);
	if (errno == ESRCH) {
		printf("Process %u does not exists\n", pid_firefox);
	} else {
		printf("Process %u exists\n", pid_firefox);
	}

	/*
	 * There is other method to check the existance of a process using bash
	 * if file /proc/pidof(process) exists => The process exists otherwise Not exists.
	 */
	return 0;
}
