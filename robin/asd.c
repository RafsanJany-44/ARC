#include <stdio.h>
int main()
{
   int i,j,b;

   printf("Base Length : ");
   scanf("%d",&b);
   for(i=1;i<=b;i++)
   {
	for(j=1;j<=i;j++)
	   printf("%d ",i);
	printf("\n");
   }
   return 0;
}