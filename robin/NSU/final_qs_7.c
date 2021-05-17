#include<stdio.h>
int main(){
    int a=70, b=20;
    int *p,*q;
    p=&b;printf("Line 5: value of p-> %d\n",p);
    q=&a;printf("Line 6: value of q-> %d\n",q);
    a=b+*p;printf("Line 7: value of a-> %d\n",a);
    q=p;printf("Line 8: value of q-> %d\n",q);
    a=(*p)*(*q);printf("Line 9: value of a-> %d\n",a);
    *p=a%b;printf("Line 10: value of b-> %d\n",b);
    printf("Line 11: value of b-> %d\n",b);

}