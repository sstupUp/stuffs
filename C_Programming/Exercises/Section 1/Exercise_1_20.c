#include <stdio.h>

#define MAX_LINE 200
//replace \t with proper number of spaces

int Getline(char [], int);
void Printline(char []);


main()
{
  char buffer[MAX_LINE];

  while(Getline(buffer, MAX_LINE) >= 0)
    Printline(buffer);

}

int Getline(char s[], int lim)
{
  int c, i, j;

  for(i=0; i<lim-1 && (c= getchar()) != EOF && c != '\n'; ++i)
    {
      if(c == '\t')
	{
	  for(j = 0;j<4; ++j)
	    s[i+j] = ' ';

	  i += 3;

	  continue;
	}
      else
	s[i] = c;
    }

  if(c == '\n')
    s[i++] = c;

  if(i == 0)
    return -1;
  
  s[i] = '\0';

  return i;
}

void Printline(char s[])
{
  int i = 0;

  while(s[i] != '\0')
    putchar(s[i++]);
}
