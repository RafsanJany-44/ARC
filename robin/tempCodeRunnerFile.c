#include<stdio.h>
#include <string.h>
int main()
{

    char sentence[300];
    gets(sentence);
    
    int total_word=1, interogative=0, assertive=0, i=0;


    while(i<strlen(sentence))
    {
        if(sentence[i]==" "){total_word++;}
        if(sentence[i]=="?"){interogative++;}
        if(sentence[i]=="."){assertive++;}
        i++;
    }

    printf("Total number of iterrogative sentences : %d\n",interogative);
    printf("Total number of assertive sentences : %d\n",assertive);
    printf("Total number of words : %d\n",total_word);

    return 0;
}