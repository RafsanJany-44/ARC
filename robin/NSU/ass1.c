#include<stdio.h>
struct empInfo
{
int Employee_ID;
int Age;
float Salary;
};

float highest_salary(struct empInfo info[],int n){
    float max=0;
    int i;
    
    for(i=0;i<n;i++){
        if(info[i].Salary>max){
            max=info[i].Salary;
        }
    }
    return max;
}

int oldest(struct empInfo info[],int n){
    int max=0;
    int i,index;
    
    for(i=0;i<n;i++){
        if(info[i].Age>max){
            max=info[i].Age;
            index=i;
        }
    }
    return index;
}


int main(){

    int N,i,index;
    float max;
    printf("Enter the number of Employee: ");
    scanf("%d",&N);
    
    struct empInfo info[N];    
    printf("Enter Records of %d Employee:",N);    
    for(i=0;i<N;i++){       
    printf("\nEnter Employee ID:");    
    scanf("%d",&info[i].Employee_ID);    
    printf("\nEnter Age:");    
    scanf("%d",&info[i].Age);
    printf("\nEnter Salary:");    
    scanf("%f",&info[i].Salary);
    
    }
    max=highest_salary(info,N);
    printf("The Higest Salary is: %f\n", max);
    index=oldest(info,N);

    printf("\nInformation of the Oldest Employee: \n");
    printf("Employee ID: %d\n", info[index].Employee_ID);
    printf("Salary: %.2f\n", info[index].Salary);
    printf("Age: %d\n", info[index].Age);
}