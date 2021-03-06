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

      if(len >= 0)
	for(i=len; i>=0; --i)
	  putchar(buffer[i]);
      else
	break;
      
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

  
