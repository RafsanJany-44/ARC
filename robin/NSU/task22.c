#include <stdio.h>
int main() {
  int N, a[100][100], i, j,sum=0;
  printf("Enter dimenssion of array (NxN):");
  scanf("%d", &N);

  printf("Enter array elements:\n");
  for (i = 0; i < N; ++i){
    for (j = 0; j < N; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  for(i=0;i<N;i++){
    sum=sum+a[i][i];
  }
  printf("\nSum of the Main Diagonal Elements: %d",sum);

  return 0;
}
