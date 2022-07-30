/***
 * Print a signal information:
 * The strsignal() function performs bounds checking on the sig argument, and then
 * returns a pointer to a printable description of the signal,
 */
#include <stdio.h>
#include <string.h>
#include <signal.h>

int main(void)
{
	char *sig_infos = strsignal(SIGINT);
	printf("INFORMATIONS : %s\n", sig_infos); // INFORMATIONS : Interrupt
	return 0;
}
