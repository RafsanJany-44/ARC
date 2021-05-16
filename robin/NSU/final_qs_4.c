#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char file1[100],file2[100];
    printf("Enter the source file name: ");
    gets(file1);
    printf("Enter the destination file name: ");
    gets(file2);
    FILE *filePointer;
    char ch[10000];
    filePointer = fopen(file1, "r");
    if (filePointer == NULL)
    {
        printf("File %s is not available \n",file1);
        return 0;
    }
    else
    {

        int i=0;
        FILE *fileAddress;
        fileAddress = fopen(file2, "w");

        if (fileAddress != NULL) {
            while ((ch[i] = fgetc(filePointer)) != EOF)
            {       
                if( ch[i] >= 'a' && ch[i] <= 'z' )
                    {
                    ch[i] = ch[i] - 32;
                    }
                fputc (ch[i], fileAddress);
                i++;
            }
            fclose(fileAddress);		
        }
        else {
            printf("File %s is not available \n",file2);
            fclose(filePointer);
            return 0;
        }
                
    }
    printf("File Coping Successed.\n");
    fclose(filePointer);


    return 0;
}