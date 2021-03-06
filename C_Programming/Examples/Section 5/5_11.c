#include <stdio.h>
#include <string.h>

#define MAXLINES 500
#define MAXLEN 100
#define ALLOCSIZE 100000

char *lineptr[MAXLINES];
static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int Getline(char [], int);
char *Alloc(int);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void*));

int numcomp(char *, char *);
void swap(void *v[], int, int);

int main(int argc, char* argv[])
{
  int nlines;
  int numeric = 0;

  if(argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;

  if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
      qsort((void **) lineptr, 0, nlines-1, (int(*)(void*, void*))(numeric ? numcomp : strcmp));
      printf("\nResult: \n");
      writelines(lineptr, nlines);

      return 0;
    }
  else
    {
      printf("input too big to sort\n");
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

void swap(void *v[], int i, int j)
{
  void *temp;

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

int numcomp(char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);

  if(v1<v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;

}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
  int i, last;

  if(left >= right)
    return;
  swap(v, left, (left+right)/2);

  last = left;

  for(i = left +1; i<= right; i++)
    if((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);

  swap(v,left,last);

  qsort(v, left, last-1, comp);
  qsort(v, last+1, right, comp);
}
