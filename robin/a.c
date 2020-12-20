#include <stdio.h>

int main()
{
    int i, j, n;

    printf("Base Length: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        for(j=i; j<n; j++)
        {
            printf(" ");
        }

        
        for(j=1; j<=i; j++)
        {
            printf("%d", i);
        }

        printf("\n");
    }

    return 0;
}