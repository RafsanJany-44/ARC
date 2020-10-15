#include<stdio.h>

int factorial(int n){
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) {
    fact *= i;
    }
    return fact;
}

int main(){
    int m=3,n=2;
    float result,u,v,x;
    u=factorial(n);
    v=factorial(m);
    x=factorial(m+n);
    printf("%f %f %f",u,v,x);
    result=u*(v/x);
   // printf("Result= %f",result);


}