#define BLACK 0
#define WHITE 1
#define GRAY 2

typedef struct node
{
  int vertex_name;
  int state;
  int distance;
  struct node* parent;
  
}NODE;

NODE* Create_node(int);
void Init_node(NODE*, int);

NODE* Create_node(int name)
{
  NODE* dummy = (NODE*)malloc(sizeof(NODE));

  Init_node(dummy, name);

  return dummy;
}

void Init_node(NODE* dummy, int name)
{
  dummy->vertex_name = name;
  dummy->state = BLACK;
  dummy->parent = NULL;
}


  
