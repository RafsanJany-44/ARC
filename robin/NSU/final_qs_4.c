#include <stdio.h>
#include <stdlib.h>

int main()
{
    //1
    FILE *filePointer;
    char ch[10000];

    //2
    filePointer = fopen("hello.txt", "r");

    //3
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        //4
        int i=0;
        while ((ch[i] = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch[i]);
            i++;
        }
    }

    //5
    fclose(filePointer);

    return 0;
}