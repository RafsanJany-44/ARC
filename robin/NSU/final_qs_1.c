#include <stdio.h>
#include <math.h>
double PI=3.1415926535897932384650288;
int factorial(int n){
    int fact=1;
    for(int i=1; i<=n;i++){
        fact=fact*i;
    }
    return fact;
}

float cosine(int deg) {
    deg %= 360; 
    float rad = deg * PI / 180;
    float cos = 0;
    int i;
    for(i = 0; i < 100; i++) { // That's also Taylor series!!
        cos += pow(-1, i) * pow(rad, 2 * i) / factorial(2 * i);
    }
    return cos;
}
int main(){

    double sum=0,angle,m;
    int i,j=0;
    printf("Enter an Angle: ");
    scanf("%lf",&angle);
   /* for(i=0;i<=100;i++){
        
        if(i%2==0){
            m=pow(angle,j);
            sum=sum-m/factorial(j);
            
          //  printf("If: %f\n",m);
           
        }
        else{
            m=pow(angle,j);
            sum=sum-m/factorial(j);
           // printf(" not If: -%f\n",m);
            
        }
        j=j+2;
    }*/
printf("_______________: %d",factorial(3));
}
