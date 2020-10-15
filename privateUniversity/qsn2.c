#include<stdio.h>

int factorial(int n){
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) {
    fact *= i;
    }
    return fact;
}

int main(){

}