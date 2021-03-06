//***************Incomplete******************//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(a, b, c) (a=b, b=c,c=a)

void Max_heapify(int [], int, int);
void Build_max_heap(int [], int);
void Heapsort(int [], int);

void Print_array(int [], int);
void Rand_array(int [], int);

int max_count = 0;

int main(void)
{
  int data[11] = {0,5,3,6,1,8,2,9,4,10,7};
  int i, j, k;
  int length = 10;

  srand(time(NULL));
  
  //  Rand_array(data, length);
  Print_array(data, length);

  Heapsort(data, length);
  Print_array(data, length);

  return 0;
}

void Max_heapify(int data[], int position, int heap_size)
{
  int l = position*2;
  int r = position*2 + 1;
  int largest=position;
  int dummy = 0;
  
  if((l <= heap_size) && (data[l] > data[position]))
    largest = l;
  else
    largest = position;

  if((r <= heap_size) && (data[r] > data[largest]))
    largest = r;

  if(largest != position)
    {
      //SWAP(dummy, data[position], data[largest]);
      dummy = data[position];
      data[position] = data[largest];
      data[largest] = dummy;
      Max_heapify(data, largest, heap_size);
      printf("\n%d: ", ++max_count);
      Print_array(data,heap_size);
    }
}

void Build_max_heap(int data[], int length)
{
  int heap_size = length;
  int i = 0;

  for(i = length/2; i>= 1; --i)  //***************************
    {
      Max_heapify(data, i, heap_size);
      printf("\n%d: ", ++max_count);
      Print_array(data,length);
    }

}

void Heapsort(int data[], int length)
{
  int i = 0, dummy;
  
  Build_max_heap(data, length);

  printf("\nMax:");
  Print_array(data, length);
  
  for(i = length; i >= 1; --i) //**************************
    {
      //SWAP(dummy, data[1], data[i]);
      dummy = data[1];
      data[1] = data[i];
      data[i] = dummy;
      
      length = length-1;
      Max_heapify(data,1,length);
      }
}

void Print_array(int data[], int length)
{
  int i = 1;

  for(; i<= length; ++i)
    printf("%d ", data[i]);

  printf("\n");
}

void Rand_array(int data[], int length)
{
  int i = 0;

  for(i = 0; i<length; ++i)
    data[i] = rand()%(length*length*length);
}
