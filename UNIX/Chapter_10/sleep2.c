#include <unistd.h>
#include <setjmp.h>
#include <signal.h>
#include <stdio.h>

static jmp_buf env_alrm;

static void sig_alrm(int);
unsigned int sleep2(unsigned int);

static void sig_alrm(int signo)
{
  longjmp(env_alrm, 1);
}

unsigned int sleep2(unsigned int seconds)
{
  if(signal(SIGALRM, sig_alrm) == SIG_ERR)
    return(seconds);
  if(setjmp(env_alrm) == 0)
    {
      alarm(seconds);
      pause();
    }

  return(alarm(0));
}

int main(void)
{
  unsigned int sec;

  printf("enter how long you want sleep in sec: ");
  scanf("%u", &sec);

  printf("\nsleeps for %u seconds\n", sec);
  
  printf("starts now\n");

  if(sleep2(sec) != 0)
    {
      printf("sleep2 error\n");
      return -1;
    }

  printf("end sleep\n");

  return 0;
}
