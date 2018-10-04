
#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;
  scanf("%d",&N);
  int *array=calloc(N, sizeof(int));
  printf("%d ",array[0]);
  for (int i = 1; i <N ; ++i) {
      array[i]=array[i-1]+1;
      printf("%d ",array[i]);
  }
  free(array);


}