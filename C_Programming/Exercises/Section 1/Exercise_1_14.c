#include <stdio.h>

//historgram of the frequencies of the different characters in its input

#define ALPHA 0
#define BLANK 1
#define CHARA 2
#define DIGIT 3

main()
{
  int histogram[4];
  int c, i, j;

  for(i =0; i<4; ++i)
    histogram[i] = 0;
  
  while((c = getchar()) != EOF)
    if((c == ' ') || (c == '\n') || (c == '\t'))
      ++histogram[BLANK];
    else if(((c >= 'a') && (c<= 'z')) || ((c >= 'A') && (c <= 'Z')))
      ++histogram[ALPHA];
    else if((c >= '0') && (c <= '9'))
      ++histogram[DIGIT];
    else
      ++histogram[CHARA];

  printf("\nAlphabet: ");
  for(i = 0; i < histogram[ALPHA]; ++i)
    printf("|");

  printf("\nBlank: ");
  for(i = 0; i < histogram[BLANK]; ++i)
    printf("|");

  printf("\nCharacter: ");
  for(i = 0; i < histogram[CHARA]; ++i)
    printf("|");

  printf("\nDigits: ");
  for(i = 0; i < histogram[DIGIT]; ++i)
    printf("|");
}
