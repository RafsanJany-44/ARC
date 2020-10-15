#include<stdio.h>
int main(){
    int row, colunm, i, j;
    int first_mat[10][10], second_mat[10][10], ans_mat[10][10];

    printf("Number of rows of matrices : ");
    scanf("%d", &row);

    printf("Number of columns matrices : ");
    scanf("%d", &colunm);

    printf("Elements of first matrix : \n");

    for (i = 0; i <row; i++)
        for (j = 0; j < colunm; j++)
            scanf("%d", &first_mat[i][j]);

    printf("Elements of second matrix : \n");

    for (i = 0; i <row; i++)
        for (j = 0; j < colunm; j++)
            scanf("%d", &second_mat[i][j]);

    printf("Sum of entered matrices : \n");

    for (i = 0; i <row; i++)
    {
        for (j = 0; j < colunm; j++)
        {
            ans_mat[i][j] = first_mat[i][j] + second_mat[i][j];
            printf("%d\t",ans_mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
