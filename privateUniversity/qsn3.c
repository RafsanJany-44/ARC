#include<stdio.h>
int main(){
    int i, j,k,n,m;
    char c1,c2;

    scanf("%d",&n);
    m=n+1;
    printf("Character 1:");
    scanf(" %c",&c1);
    printf("Character 2:");
    scanf(" %c",&c2);
    printf("\n");

    for(i=1; i<=m-1; i++)
    {
        for(j=i; j<m; j++)
        {
            printf(" ");
        }
        for(j=1; j<=(2*i-1); j++)
        {

            if(i==m || j==1 || j==(2*i-1))
            {
                printf("%c",c1);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("  ");
    for(k=0;k<=m-1;k++){
    printf("%c",c2);
    }
}