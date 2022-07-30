#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void signal_handler(int sig_num)
{
	printf("hello handler ...\n");
}


int main(void)
{
	struct sigaction act;
	struct sigaction old_act;
	act.sa_handler = signal_handler;
	sigset_t blocked, prevMask;
	sigemptyset(&blocked);
	sigaddset(&blocked, SIGTSTP); // Add SIGINT to a signal_set
	
	// Block SIGINT and save prev Mask
	if (sigprocmask(SIG_BLOCK, &blocked, &prevMask) == -1)
		perror("sigprocmask");
	act.sa_mask = blocked;
	act.sa_flags = SA_SIGINFO;
	
	// Change signal disposition
	if (sigaction(SIGINT, &act, &old_act) == -1)
		perror("sigaction");
	
	sleep(10);
	if (sigprocmask(SIG_UNBLOCK, &blocked, &prevMask) == -1)
		perror("sigprocmask");
	sleep(5);
	return 0;
}
