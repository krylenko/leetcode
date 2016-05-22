#include <stdio.h>
#include <malloc.h>

int** generateMatrix(int n)
{
  int** mtxptr = NULL;
  mtxptr = (int**)malloc(n * sizeof(*mtxptr));
  
  for(int i=0;i<n;++i)
  {
    mtxptr[i] = (int*) malloc(n*sizeof(int));
  }

  int i = 0, j = 0;
  int imin = 0, imax=n-1, jmin=0, jmax = n-1;
  int numel = 0;
  enum{RIGHT,DOWN,LEFT,UP};
  int direction = RIGHT;
  
  while( numel < n*n )
  {
    mtxptr[i][j] = numel + 1;
    switch(direction)
    {
      case RIGHT:
      ++j;
      if(j==jmax)
      {
        --jmax;
        direction = DOWN;
      }
      break;
      case DOWN:
      ++i;
      if(i==imax)
      {
        ++imin;
        --imax;
        direction = LEFT;
      }    
      break;
      case LEFT:
      --j;
      if(j==jmin)
      {
        ++jmin;
        direction = UP;
      }    
      break;
      case UP:
      --i;
      if(i==imin)
      {
        direction = RIGHT;
      }
      break;
    }
    ++numel;
  }
  
  return mtxptr;
}

int main(int argc, char* argv[])
{

  int** mtxptr = NULL;
  const int N = 6;
  
  mtxptr = generateMatrix(N);

  printf("\n");
  for(int i=0;i<N;++i)
  {
    printf("[\t");
    for(int j=0;j<N;++j)
    {
      printf("%d\t",mtxptr[i][j]);
    }
    printf("]\n");
  }

  for(int k=0;k<N;++k)
    free(mtxptr[k]);
    
  return 0;

}