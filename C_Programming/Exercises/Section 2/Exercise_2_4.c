#include <stdio.h>

#define MAX_LINE 200

//delet each characters in s1 that matches any character in the s2

int Getline(char [], int);
void Squeeze(char [], char[]);
void PrintLine(char []);
void Squeeze2(char [], int);

main()
{
  char buffer1[MAX_LINE];
  char buffer2[MAX_LINE];
  
  while((Getline(buffer1, MAX_LINE) >= 0) && (Getline(buffer2, MAX_LINE) >= 0))
    {
      Squeeze(buffer1, buffer2);
      //Squeeze2(buffer1, 'a');
      PrintLine(buffer1);
    }
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

void Squeeze(char s1[], char s2[])
{
  int i, j, k;
  int found;
  
  for(i = j = 0; s1[i] != '\0'; ++i)
    {
      found = 0;
      
      for(k = 0; s2[k] != '\0' && found == 0; ++k)
	if(s1[i] == s2[k])
	  found = 1;

      if(found == 0)
	s1[j++] = s1[i];
    }

  s1[j++] = '\n';
  s1[j] = '\0';
}

void PrintLine(char s[])
{
  int i;

  for(i=0; s[i] != '\0'; ++i)
    putchar(s[i]);
}

void Squeeze2(char s[], int c)
{
  int i, j;

  for(i = j = 0; s[i] != '\0'; ++i)
    if(s[i] != c)
      s[j++] = s[i];

  s[j] = '\0';
}
