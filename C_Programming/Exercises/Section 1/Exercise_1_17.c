#include <stdio.h>

#define MAX_LINE 200
//print inputs that are over 80 characters

int Getline(char [], int);

char buffer[MAX_LINE];

main ()
{
  int c, i;
  int len = 0;

  while(1)
    {
      len = Getline(buffer, MAX_LINE);

      if(len >= 80)
	printf("\n%s", buffer);
      else if(len == -1)
	break;
      
      for(i=0; i<=len; ++i)
	buffer[i] = 0;

      printf("\n");
    }
  
}

int Getline(char s[], int lim)
{
  int c, i;

  for(i =0; i<lim-1 &&(c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if(i == 0)
    return -1;
  
  if(c == '\n')
    s[i++] = c;

  s[i]  = '\0';

  return i;
}

  
