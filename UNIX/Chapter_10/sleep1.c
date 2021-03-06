#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void sig_alrm(void);
unsigned int sleep1(unsigned int);

static void sig_alrm(void)
{  
  /* nothing to do, just return to wake up the pause */
}

unsigned int sleep1(unsigned int seconds)
{
  if(signal(SIGALRM, sig_alrm) == SIG_ERR)
    return (seconds);

  alarm(seconds);

  pause();

  return (alarm(0));
}

int main(void)
{
  unsigned int sec;
  int i;
  
  printf("enter how long you want sleep in sec: ");
  scanf("%u", &sec);

  printf("\nsleeps for %u seconds\n", sec);
 
  printf("starts now\n");

 
  sleep1(sec);

  printf("end sleep\n");
  
  return 0;
}
  
