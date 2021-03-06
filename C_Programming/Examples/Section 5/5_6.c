#include <stdio.h>
#include <string.h>

#define MAXLINES 500
#define MAXLEN 100
#define ALLOCSIZE 100000

static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;

int readlines(char *[], int);
void writelines(char *[], int);
int Getline(char [], int);
char *Alloc(int);

void qsort(char *[], int, int);
void swap(char *[], int, int);

char *lineptr[MAXLINES];

int main()
{
  int nlines;

  if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
      qsort(lineptr, 0, nlines-1);

      printf("\nOutput:\n");
      writelines(lineptr, nlines);

      return 0;
    }
  else
    {
      printf("\nerror: input too big to sort\n");

      return 1;
    }
}

int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;

  while((len = Getline(line, MAXLEN)) > 0)
    if((nlines >= maxlines) || ((p = Alloc(len)) == NULL))
      return -1;
    else
      {
	line[len - 1] = '\0';
	strcpy(p, line);
	lineptr[nlines++] = p;
      }

  return nlines;
}

void writelines(char *lineptr[], int nlines)
{
  while(nlines-- >0)
    printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right)
{
  int i, last;

  if(left >= right)
    return;

  swap(v, left, (left+right)/2);

  last = left;

  for(i = left+1; i <=right; i++)
    if(strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);

  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);

}

void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;

}

char* Alloc(int n)
{
  if((allocbuf + ALLOCSIZE - allocp) >= n)
    {
      allocp += n;
      return allocp;
    }
  else
    return 0;
}

int Getline(char s[], int lim)
{
  int c, i;

  for(i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if(c == '\n')
    {
      s[i] = c;
      ++i;
    }

  s[i] = '\0';

  return i;
}
    
