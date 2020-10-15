

#include<stdio.h>
int main(){
    int i, j,k,n;
    char c1,c2;

    scanf("%d",&n);
    printf("Character 1:");
    scanf(" %c",&c1);
    printf("Character 2:");
    scanf(" %c",&c2);
    printf("\n");

    for(i=1; i<=n; i++)
    {
        for(j=i; j<n+1; j++)
        {
            printf(" ");
        }
        for(j=1; j<=(2*i-1); j++)
        {

            if(i==n+1 || j==1 || j==(2*i-1))
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
    for(k=0;k<=n;k++){
    printf("%c",c2);
    }
}