#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
  int value;
  struct data* next;
  
}DATA;

DATA* Create(int);
void Init(DATA*, int);
void Connect(DATA*, DATA*);


DATA* Create(int value)
{
  DATA* dummy = (DATA*)malloc(sizeof(DATA));

  Init(dummy, value);

  return dummy;
}

void Init(DATA* dummy, int v)
{
  dummy->value = v;
  dummy->next = NULL;
}

void Connect(DATA* d1, DATA* d2)
{
  d1->next = d2;
}

int main()
{
  DATA* dummy = Create(1);
  DATA* dummy2 = Create(2);
  DATA* head = dummy;
  Connect(dummy, dummy2);

  printf("\n");
  
  while(head != NULL)
    {
      printf("%d ", head->value);

      head = head->next;
    }

  printf("\nEND\n");
  
  return 0;
}
  
