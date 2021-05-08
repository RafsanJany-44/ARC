#include <stdio.h>
int main() {
  int r, c, a[100][100], b[100][100], sum[100][100], i, j;
  printf("Row: ");
  scanf("%d", &r);
  printf("Column:");
  scanf("%d", &c);

  printf("Enter first array elements:\n");
  for (i = 0; i < r; ++i){
    for (j = 0; j < c; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  printf("Enter second array elements:\n");
  for (i = 0; i < r; ++i){
    for (j = 0; j < c; ++j) {
      scanf("%d", &b[i][j]);
    }
  }

 
    printf("First Array:\n");
  for (i = 0; i < r; ++i){
    for (j = 0; j < c; ++j) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

    printf("Second Array \n");
  for (i = 0; i < r; ++i){
    for (j = 0; j < c; ++j) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < r; ++i)
    for (j = 0; j < c; ++j) {
      sum[i][j] = a[i][j] + b[i][j];
    }

  printf("\nSum: \n");
  for (i = 0; i < r; ++i)
    for (j = 0; j < c; ++j) {
      printf("%d ", sum[i][j]);
      if (j == c - 1) {
        printf("\n\n");
      }
    }

  return 0;
}
