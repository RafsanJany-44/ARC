#include<stdio.h>

int main(){
    int mat[3][3];
    mat[0][0]=2;
    mat[0][1]=3;
    mat[0][2]=6;
    mat[1][0]=4;
    mat[1][1]=8;
    mat[1][2]=1;
    mat[2][0]=9;
    mat[2][1]=0;
    mat[2][2]=7;

    printf("Enter a Value of column: ");
    int c;
    int max=0;
    scanf("%d",&c);
    c=c-1;
    for(int i=0;i<3;i++){
        if(mat[i][c]>max)
        {
            max=mat[c][i];
        }
    }
    printf("\n %d \n",max);
}