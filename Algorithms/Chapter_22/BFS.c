#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "queue.h"
#include "graph.h"

#define TRUE 1

void Where_2_begin(int*);
void BFS(GRAPH*, QUEUE*, int, int);

int main()
{
  GRAPH* g;
  QUEUE* q;
  int size, start = 0;

  printf("\nEnter total number of vertices: ");
  scanf("%d", &size);
  
  g = Create_graph(size);
  q = Create_queue();
    
  Make_graph(g);

  printf("\n");

  Where_2_begin(&start);
  
  BFS(g, q, start, size);

  return 0;
}

void Where_2_begin(int* start)
{
  printf("\nEnter starting vertex number: ");
  scanf("%d", start);

  printf("\n");

  return;
}
  
void BFS(GRAPH* g, QUEUE* q, int s, int size)
{
  int u;
  NODE* dummy;
  int visited[size];
  
  Enqueue(q, s);
  visited[s] = TRUE;
  printf("visited: %d\n", s);
  
  while(!is_EMPTY(q))
    {
      u = Dequeue(q);
      dummy = g->adjList[u];
      
      while(dummy != NULL)
	{ 
	  if(visited[dummy->vertex] != TRUE)
	    {
	      Enqueue(q, dummy->vertex);
	      visited[dummy->vertex] = TRUE;
	      printf("visited: %d\n", dummy->vertex);
	    }
	  
	  dummy = dummy->next;
	}
    }
}
