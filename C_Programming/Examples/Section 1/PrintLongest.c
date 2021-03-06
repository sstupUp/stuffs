#include <stdio.h>
#define MAX_LINE 100

//print longest input line

int Getline(char [], int);
void Copy(char [], char []);

main()
{
  int len;
  int max;

  char buffer[MAX_LINE];
  char longest[MAX_LINE];

  max = 0;
  while((len = Getline(buffer, MAX_LINE)) > 0)
    if(len > max)
      {
	max = len;
	Copy(longest, buffer);
      }

  if(max > 0)
    printf("Longest inpu: %s\n", longest);
}

int Getline(char s[], int lim)
{
  int c, i;

  for(i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if(c == '\n')
    {
      s[i] = c;
      ++i;
    }

  s[i] = '\0';

  return i;
}

void Copy(char to[], char from[])
{
  int i;

  i =0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
