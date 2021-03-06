#include <stdio.h>

#define MAX_LINE 200
#define FOLD 10

//folding long input in fornt of the n-th character

int Getline(int);

main()
{
  while(Getline(MAX_LINE) >= 0)
    ;
}

int Getline(int lim)
{
  int c, i;

  for(i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
      if(i%FOLD == 0)
        putchar('\n');
      
      putchar(c);
    }

  putchar('\n');
  
  if(i == 0)
    return -1;
  else
    return i;
}
      
