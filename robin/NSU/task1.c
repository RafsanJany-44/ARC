#include<stdio.h>

struct movieStar
{
char Name[30];
int Age;
float Annual_Income;
char Gender;
};

float highest_annual_earning(struct movieStar ms[],int n){
    int i,max=0;
    float total;
    for(i=0;i<n;i++){
        if(ms[i].Annual_Income>max){
            max=ms[i].Annual_Income;
        }
    }
    return max;
}

int youngStar(struct movieStar ms[],int n){
    int i,min=ms[i].Age;
    float total;
    for(i=0;i<n;i++){
        if(ms[i].Age<min){
            min=ms[i].Age;
        }
    }
    return min;
}


int main(){

    int N,i;
    printf("Enter the number of Film Star: ");
    scanf("%d",&N);
    
    struct movieStar ms[N];    
    printf("Enter Records of %d Film Star:",N);    
    for(i=0;i<N;i++){    
    printf("\nEnter Name:");    
    get(ms[i].Name);    
    printf("\nEnter Annual Income:");    
    scanf("%f",&ms[i].Annual_Income);    
    printf("\nEnter Age:");    
    scanf("%d",&ms[i].Age);
    printf("\nEnter Gender:");    
    scanf(" %c",&ms[i].Gender);
    
    }

    printf("\nNumber of Failed Student: %d ",passCount(st,N));
    printf("\nID of the student obtaining the highest marks: %d \n",highest_marks(st,N));

}