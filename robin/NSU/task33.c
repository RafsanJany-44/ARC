#include <stdio.h>
int main() {
  int N, a[100][100], i, j;
  printf("Enter dimenssion of array (NxN):");
  scanf("%d", &N);

  printf("Enter array elements:\n");
  for (i = 0; i < N; ++i){
    for (j = 0; j < N; ++j) {
        if(i+j==N-1){
            a[i][j]=1;
        }
        else{a[i][j]=0;}
      
    }
  }

  for (i = 0; i < N; ++i){
    for (j = 0; j < N; ++j) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}
