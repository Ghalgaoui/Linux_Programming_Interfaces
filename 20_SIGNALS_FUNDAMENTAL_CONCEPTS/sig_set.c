#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	sigset_t blockSet, prevMask;
	/* Initialize a signal set to contain SIGINT */
	sigemptyset(&blockSet); 

	/* Add SIGINT to the signal set */
	sigaddset(&blockSet, SIGINT); // sigfillset(sigset_t * set ): initializes a set to contain all signals

	/* Check if SIGINT is member of the sig set */
	if (sigismember(&blockSet, SIGINT) == 1) {
		printf("SIGINT is a member of the set signals\n");
	}
	/* Display current sa_mask */
	/***
	 * Specify NULL for the set arg "sigprocmask(int how , const sigset_t * set , sigset_t * oldset );"
	 */

	/* Block SIGINT, save previous signal mask */
	/********
	 * SIG_BLOCK: 	The signals specified in the signal set pointed to by set are added to the signal mask.
	 * SIG_UNBLOCK: The signals in the signal set pointed to by set are removed from the signal mask.
	 * SIG_SETMASK: The signal set pointed to by set is assigned to the signal mask.
	 */
	if (sigprocmask(SIG_BLOCK, &blockSet, &prevMask) == -1) {
		printf("sigprocmask1");
		exit(1);
	}
	
}
