/*
In this example, I use the syscall signal(2) to change a signal disposition 
sent to my process by other process bypass the kernel of course !
* 
* SIGSTOP      P1990      Stop    Stop process
* SIGTSTP      P1990      Stop    Stop typed at terminal
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);

/*
 * This signal handler.
*/
void sig_handler(int signum)
{
  printf("Hello : %d\n", signum);
}

int main(void)
{
  /* Change signal disposition of signal SIGTSTP (Ctrl + Z) */
  if (signal(SIGTSTP, sig_handler) == SIG_ERR)
    exit(1);

  /*
   * 1- If You want to reset the signal disposition to its default => Use SIG_DFL Instead 
   * the handler sig_handler.
   * 2- Use SIG_IGN instead sig_handler if you want ignore the signal.
   */
  while (1);
  return 0;
}
