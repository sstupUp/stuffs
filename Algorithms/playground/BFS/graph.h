typedef struct graph
{
  int nVertex;
  adjLIST_NODE** LIST;
  
}GRAPH;

GRAPH* Create_graph(int);
void Init_graph(GRAPH*, int); 
void Make_graph(GRAPH*);

GRAPH* Create_graph(int size)
{
  GRAPH* dummy = (GRAPH*)malloc(sizeof(GRAPH));

  Init_graph(dummy, size);

  return dummy;
}

void Init_graph(GRAPH* dummy, int size)
{
  dummy->LIST = (adjLIST_NODE**)malloc((sizeof(adjLIST_NODE))*size);

  dummy->nVertex = size;
}

void Make_graph(GRAPH* dummy)
{
  int a = 0, name = 0, node_count = 0;
  adjLIST_NODE* head = dummy->LIST;
  NODE* node_ptr = NULL;

  while(a != (dummy->nVertex+1))
    {
      printf("Enter vertex name: \n");
      scanf("%d", &name);

      dummy->LIST[node_count++] = Create_node(name);

      printf("//Vertex Added//\n");

      ++a;
    }   //Creating head nodes for adjacency lists which point original nodes
  
  while(1)
    {
      printf("Enter vertex %d's neighbor vertex name: \n", head->current->name);
      scanf("%d", &name);
      
      if(name <= -1)
	break;
      
      while(dummy->LIST[node_count]->vertex_name != name)
	++node_count;
      
      Add_adjLIST_NODE(head, dummy->LIST[node_count]);

      printf("\n//Neighbor VertexcAdded//\n");
      
    }  //Creating adjacency lists by finding same name as input name
}

