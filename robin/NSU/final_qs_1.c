#include <stdio.h>
#include <math.h>

int fact(int n){
    int fact=1;
    for(int i=1; i<=n;i++){
        fact=fact*i;
    }
    return fact;
}

int main(){

    int degree,i=0;
    printf("Enter Angle: ");
    scanf("%d",&degree);
    degree %= 360; 
    double radian = degree * 3.1416 / 180;
    long double cosec = 0;
    ;
    while(i<100)
    { 
        cosec += pow(-1, i) * pow(radian, 2 * i) / fact(2 * i);
        i++;
    }


printf("The cos value is: %.6LF",cosec);
}
