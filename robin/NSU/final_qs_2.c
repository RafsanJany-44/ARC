#include <stdio.h>
#include <string.h>
int main(){
    char s1[30]="Twin";
    char s2[30]="little ";
    char s3[30]="kel ";
    char s4[30]="star.";
    char s5[30];
    strcat(s1,s3);printf("Line 9: value of string s1-> %s\n",s1);
    strcpy(s5,"");printf("Line 10: value of string s5-> %s\n",s5);
    strcat(s2,s4);printf("Line 11: value of string s2-> %s\n",s2);
    strcat(s1,s2);printf("Line 12: value of string s1-> %s\n",s1);
    strncat(s5,s1,8);printf("Line 13: value of string s5-> %s\n",s5);
    strcat(s5,s1);printf("Line 14: value of string s5-> %s\n",s5);
    printf("Line 25: value of string s5-> TWINKEL TWINKEL LITTLE STAR.");
    
}