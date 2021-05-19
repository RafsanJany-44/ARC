#include<stdio.h>
#include<string.h>
//a
struct movieStar
{
char Name[30];
int Age;
float Annual_Income;
char Gender;
};

//c
float highestEearning(struct movieStar s[],int n){
    int i,income=0;
    
    for(i=0;i<n;i++){
        if(s[i].Annual_Income>income){
            income=s[i].Annual_Income;
        }
    }
    return income;
}

//d
int youngStar(struct movieStar a[],int n){
    int i,s=a[i].Age;
    
    for(i=0;i<n;i++){
        if(a[i].Age<s){
            s=a[i].Age;
        }
    }
    return s;
}


int main(){

    int N,i=0;
    //b
    printf("Enter the number of Film Star: ");
    scanf("%d",&N);
    
    struct movieStar ms[N];    
    printf("Enter Records of %d Film Star:",N);    
    
    while(i<N){    
    printf("\nEnter Name:");    
    get(ms[i].Name);    
    printf("\nEnter Annual Income:");    
    scanf("%f",&ms[i].Annual_Income);    
    printf("\nEnter Age:");    
    scanf("%d",&ms[i].Age);
    printf("\nEnter Gender:");    
    scanf(" %c",&ms[i].Gender);
    i++;
    }

    printf("\nHighest Earning: %f ",highestEarning(ms,N));
    printf("\nAge of Young Actor: %d \n",youngStar(ms,N));

}