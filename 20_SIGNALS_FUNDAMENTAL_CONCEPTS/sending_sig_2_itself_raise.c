#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

/* Sending signal to process itself using raise(2) => Not kill(getpid(), sig) OR pthread_kill(pthread_self(), sig)*/
/* When a process sends itself a signal using raise() (or kill()), the signal is delivered immediately (i.e., before raise() returns to the caller).*/

int main(void)
{
	int counter = 10;
	int time_2_kill = 5;
	while (counter-- > 0) {
		printf("I'm here : %d\n", counter); 
		if (counter == time_2_kill)
			raise(SIGTERM); // Killing the process
	}
	return 0;
}



/* Output :*/

/*
I'm here : 9
I'm here : 8
I'm here : 7
I'm here : 6
I'm here : 5
Terminated
*/
