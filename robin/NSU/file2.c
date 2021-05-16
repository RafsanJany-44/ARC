#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *filePointer;
    char ch[10000];
    int count=0;
    filePointer = fopen("story.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        int i=0;
        while ((ch[i] = fgetc(filePointer)) != EOF)
        {
            if(ch[i]=='A'||ch[i]=='E'||ch[i]=='O'||ch[i]=='I'||ch[i]=='U'||ch[i]=='a'||ch[i]=='e'||ch[i]=='i'||ch[i]=='o'||ch[i]=='u'){
                count++;
            }
            i++;
        }
    }
    fclose(filePointer);
    printf("There are %d vowels",count);

    return 0;
}