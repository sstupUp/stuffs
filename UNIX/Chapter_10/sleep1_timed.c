#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/times.h>

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
  static long clktck = 0;
  clock_t start, end;
  struct tms tmsstart, tmsend;

  if((clktck = sysconf(_SC_CLK_TCK)) < 0)
    return -1;
  
  printf("enter how long you want sleep in sec: ");
  scanf("%u", &sec);

  printf("\nsleeps for %u seconds\n", sec);

  start = times(&tmsstart);
  
  printf("starts now\n");

 
  sleep1(sec);

  end = times(&tmsend);
  printf("end sleep\n");

  printf("\ntime passed = %f\n", (float)(end - start)/clktck);
  
  return 0;
}
  
