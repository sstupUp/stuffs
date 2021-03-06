#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAXLINE 4096

static void sig_alrm(int);

static void sig_alrm(int signo)
{
  printf("\ninside of sig_alrm\n");
  /*nothing to do, just return to interrupt the read */
}

int main(void)
{
   int n;
   char line[MAXLINE];
   
   if(signal(SIGALRM, sig_alrm) == SIG_ERR)
     {
       printf("signal(SIGALRM) error");
       return -1;
     }
   
   alarm(10);
   
   if((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
     {
       printf("read error");
       return -1;
     }
   alarm(0);
   
   write(STDOUT_FILENO, line, n);
   
   exit(0);
}
