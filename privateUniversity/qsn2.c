#include<stdio.h>

int factorial(int n){
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) {
    fact *= i;
    }
    return fact;
}

int main(){
    int m,n;
    printf("m=");
    scanf("%d",&m);
    printf("n=");
    scanf("%d",&n);
    if (m!=0 && n!=0){
    float result,u,v,x;
    u=factorial(n);
    v=factorial(m);
    x=factorial(m+n);
    result=(u*v)/x;
    printf("Result= %f",result);
    }


}