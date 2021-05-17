#include <stdio.h>
void engigma(int n){
    if(n!=0){
        engigma(n/2);
        printf("%d",n%2);
    }
}

int main(){
    engigma(13);
    return 0;
}