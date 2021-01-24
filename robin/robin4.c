#include<stdio.h>
#include <string.h>
int main()
{

    char s[300];
    gets(s);
    
    int x=0, y=0, z=0, i;

    for(i=0;i<strlen(s);i++){
        if(s[i]==' '){
            x++;
        }
        if(s[i]=='?')y++;
        if(s[i]=='.')z++;

    }

    printf("Total number of iterrogative sentences : %d\n",y);
    printf("Total number of assertive sentences : %d\n",z);
    printf("Total number of words : %d\n",x+1);

    return 0;
}