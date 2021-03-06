#include <stdio.h>

#define MAX_LINE 200

//upper to lower

void UtoL(char []);
int Getline(char [], int);
void PrintLine(char []);

main()
{
  char buffer[MAX_LINE];

  while(Getline(buffer, MAX_LINE) >= 0)
    {
      UtoL(buffer);
      PrintLine(buffer);
    }
}

void UtoL(char s[])
{
  int i;

  for(i = 0; s[i] != '\0'; ++i)
    s[i] = (s[i] >= 'A' && s[i] <= 'Z')? s[i] + ('a' - 'A') : s[i];
}

void PrintLine(char s[])
{
  int i;

  for(i=0; s[i] != '\0'; ++i)
    putchar(s[i]);
}

int Getline(char s[], int lim)
{
  int c, i;

  PrintLine("Enter string:");
  
  for(i=0; i<lim-1 && (c= getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if(i == 0)
    return -1;

  if(c == '\n')
    s[i++] = '\n';

  s[i] = '\0';

  return i;
}
