#include <stdio.h>

#define MAX_WORD_LENGTH 20
#define IN 1
#define OUT 0

//histogram of the lengths of words

main()
{
  int c, i, j, length;
  int lwords[MAX_WORD_LENGTH];
  int state = OUT;

  length = 0;
  for(i = 0; i<MAX_WORD_LENGTH; ++i)
    lwords[i] = 0;
  
  while((c = getchar()) != EOF)
    {
      if((c == ' ') || (c == '\n') ||(c == '\t'))
	{
	  state = OUT;

	  if(length > 0)
	    ++lwords[length];

	  length = 0;
	}
      else if(state == OUT)
	state = IN;

      if(state == IN)
	++length;

    }

  for(i = 0; i<MAX_WORD_LENGTH; ++i)
    {
      printf("%2d =", i);

      for(j = 0; j<lwords[i]; ++j)
	printf("|");

      printf("\n");
    }
}
