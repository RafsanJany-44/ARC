#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *fptr;
   int n;
   printf("Enter a number:");
   scanf("%d",&n);

   fptr = fopen("number.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }


    for(int i=0;i<=n;i++){
        if(i%2==0)
            fprintf(fptr,"%d\n",i);
    }
    printf("Writting complete...");
   fclose(fptr);


    return 0;
}