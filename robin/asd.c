#include <stdio.h>
int main() {
    int rows, columns, A[100][100], B[100][100], sum[100][100], m, n;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);


    printf("Enter first matrix elements:\n");
  
    for (m= 0; m<rows; m++)
    {
        for (n=0; n<columns; n++)
        {
             printf("A[%d][%d]: ",m,n);
            scanf("%d", &A[m][n]);
        }
    }

    printf("Enter second matrix elements:\n");
    for (m= 0; m<rows; m++)
    {
        for (n=0; n<columns; n++) 
        {
            printf("B[%d][%d]: ", m,n);
            scanf("%d", &B[m][n]);
        }
    }
   
    for (m=0; m<rows; m++)
    {
        for (n=0; n<columns; n++) 
        {
            sum[m][n] = A[m][n] + B[m][n];
        }
    }

   

printf("\nThe First matrices:\n ");
    for (m=0; m<rows; m++)
    {
        for (n=0; n<columns; n++)
        {
            printf("%d   ", A[m][n]);
            if (n == columns - 1)
            {
                printf("\n\n");
            }
        }
    }

printf("\nThe second  matrices:\n ");
    for (m=0; m<rows; m++)
    {
        for (n=0; n<columns; n++)
        {
            printf("%d   ", B[m][n]);
            if (n == columns - 1)
            {
                printf("\n\n");
            }
        }
    }



    printf("\nSum of two matrices:\n ");
    for (m=0; m<rows; m++)
    {
        for (n=0; n<columns; n++)
        {
            printf("%d   ", sum[m][n]);
            if (n == columns - 1)
            {
                printf("\n\n");
            }
        }
    }
    return 0;
}