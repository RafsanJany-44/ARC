#include<stdio.h>
#define MAX 100
 
void Multiply(int[4][4], int[4][4]);
int row1=4, row2=4, col1=4, col2=4;
int res[4][4];
 
int main() {
 
   int mat1[5][5],i, j, k;
    mat1[0][0]=res[0][0]=1;
    mat1[0][1]=res[0][1]=1;
    mat1[0][2]=res[0][2]=1;
    mat1[0][3]=res[0][3]=0;
    mat1[1][0]=res[1][0]=1;
    mat1[1][1]=res[1][1]=1;
    mat1[1][2]=res[1][2]=1;
    mat1[1][3]=res[1][3]=1;
    mat1[2][0]=res[2][0]=1;
    mat1[2][1]=res[2][1]=0;
    mat1[2][2]=res[2][2]=0;
    mat1[2][3]=res[2][3]=0;
    mat1[3][0]=res[3][0]=0;
    mat1[3][1]=res[3][1]=1;
    mat1[3][2]=res[3][2]=1;
    mat1[3][3]=res[3][3]=1;
 
     
      printf("\nThe First matrix is: n");
      for (i = 0; i < 4; i++) {
         printf("\n");
         for (j = 0; j < 4; j++) {
            printf("%d ", res[i][j]);

         }
      }

    Multiply( res,  mat1);
 
   printf("\nThe multiplication of two matrixes is : \n");
   for (i = 0; i < 4; i++) {
      printf("\n");
      for (j = 0; j < 4; j++) {
         printf("%d ", res[i][j]);
      }
   }
   return 0;
}

void Multiply(int a[4][4], int b[4][4]) {
   static int sum, i = 0, j = 0, k = 0;
   //row of first matrix
   if (i < row1) {
      //column of second matrix
      if (j < col2) {
         if (k < col1) {
            sum = sum + a[i][k] * b[k][j];
            k++;
            Multiply(a, b);
         }
         res[i][j] = sum;
         sum = 0;
         k = 0;
         j++;
         Multiply(a, b);
      }
      j = 0;
      i++;
      Multiply(a, b);
   }
}