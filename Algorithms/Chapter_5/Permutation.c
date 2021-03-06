#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(x,y,z) (x=y, y=z, z=x;)

typedef struct DATA{
  int data;
  int key;
}DATA;

void permutation(DATA [], int);

int main(void)
{
  srand(time(NULL));

  DATA array[20];
  int length = 20;
  int i=0;

  printf("\ndata=");

  for(i=0; i<20; ++i)
    array[i].data = i+1;

  for(i=0; i<19; ++i)
    {
      array[i].key = rand()%(length*length*length);
      
      printf(" %d", array[i].data);
    }

  printf("\n");

  printf("\nkey: ");
  for(i = 0; i<length; ++i)
    printf(" %d", array[i].key);
  
  permutation(array, length);
  
  printf("\npermutation: ");
  for(i= 0 ;i<length; ++i)
    printf(" %d", array[i].data);

  printf("\n");
  
  return 0;
}

void permutation(DATA array[], int length)
{
  DATA dummy;
  int n = 0, m;
  
  for(n = 1; n<length; ++n)
    {
      m = n;
      dummy = array[m];
      while(--m >= 0 && dummy.key < array[m].key)
	{
	  array[m+1] = array[m];
	  array[m] = dummy;
	}
    }
}
