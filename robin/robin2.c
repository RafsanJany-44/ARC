#include<stdio.h>
#include <string.h>
int main()
{

    char sentence[300];
    printf("Enter a paragraph:\n");
    gets(sentence);
    
    int total_word=0, interogetive=0, assertive=0, i;

    for(i=0;i<strlen(sentence);i++){
        if(sentence[i]==' '){
            total_word++;
        }
        if(sentence[i]=='?')interogetive++;
        if(sentence[i]=='.')assertive++;

    }

    printf("Total number of iterrogative sentences : %d\n",interogetive);
    printf("Total number of assertive sentences : %d\n",assertive);
    printf("Total number of words : %d\n",total_word+1);

    return 0;
}