#include "apue.h"
#include <pwd.h>

static void my_alarm(int signo)
{
  struct passwd *rootptr;

  printf("in signal handler\n");

  if((rootptr = getpwnam("root")) == NULL)
    err_sys("getpwnam error");

  alarm(1);
}

int main(void)
{
  struct passwd *ptr;

  signal(SIGALRM, my_alarm);

  alarm(1);

  for(;;)
    {
      if((ptr = getpwnam("an")) == NULL)
	err_sys("getpwnam in main error");

      if(strcmp(ptr->pw_name, "an") != 0)
	printf(" return value corrupted!, pw_name = %s\n", ptr->pw_name);
    }
}
