#include <stdio.h>
#include "Lines.h"

char buffer[MAX_BUFFER_SIZE];

int ItoA_r(int n)
{
  static int c = 0;
  
  if(n < 0)
    {
      buffer[c++] = '-';
      n = -n;
    }

  if(n > 0)
    {
      buffer[c++] = n%10 + '0';
      
      return ItoA_r(n/10);
    }
  else if(n == 0)
    {
      buffer[c] = '\0';

      return 0;
    }
}

main()
{
  int c = 0;
  int dummy = 0;
  
  dummy = ItoA_r(15);

  while(buffer[c] != '\0')
    printf("%c", buffer[c++]);

  printf("\n");
}
