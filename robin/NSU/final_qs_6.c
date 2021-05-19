#include <stdio.h>
int main() {
  int n, mat[100][100], i, j;
  printf("Enter dimenssion(NxN):");
  scanf("%d", &n);
  for (i = 0; i < n; ++i){
    for (j = 0; j < n; ++j) {
        if(i==j){
            mat[i][j]=0;
        }
        else{mat[i][j]=-1;}
      
    }
  }
  
  for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
          mat[i][j]=1;
      }
  }
  for (i = 0; i < n; ++i){
    for (j = 0; j < n; ++j) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }

  return 0;
}
