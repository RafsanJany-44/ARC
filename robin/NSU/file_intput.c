#include <stdio.h> 
#include<string.h>

int main()
{
   FILE *fileAddress;
   fileAddress = fopen("hello2.txt", "w");
   char name[50] = "Tutorial Gateway";
   int i;
   int len = strlen(name);

   if (fileAddress != NULL) {
	for (i = 0; i < len; i++) {
           printf("Character we ar writing to the File = %c \n", name[i]);
	   // Let us use our fputc
	   fputc ('T', fileAddress);
	}
	printf("\n We have written the Name successfully");
	fclose(fileAddress);		
   }
   else {
  	  printf("\n Unable to Create or Open the Sample.txt File");
   }
   return 0;
}