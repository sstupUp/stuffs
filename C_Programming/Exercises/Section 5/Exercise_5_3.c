#include <stdio.h>

int Strcat(char *, int,  char *, int);

int Strcat(char *from, int f_len, char *to, int t_len)
{ 
  while(*(to++))
    ;

  --to;

  while(*(to++) = *(from++))
    ;
  
  return f_len + t_len;
}

int main(void)
{
  char str1[]= "Hello";
  char str2[]= " World!";
  int len = 0;
  
  len = Strcat(str2, 8, str1, 6);

  printf("%s\n", str1);

  return 0;
}
  
