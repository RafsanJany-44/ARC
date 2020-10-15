#include<stdio.h>

struct  employee
{
    char name[20];
    char id[10];
    float salary;
    float increment;
    float total_salary;
};

float Increment(float sal,float percent){
    float n=percent/100;
    return sal*n;
}

int main(){

    struct employee emp[5];
    for(int i=0;i<=4;i++){
        printf("Enter the salary of employee no.%d: ",(i+1));
        scanf("%f",&emp[i].salary);
        emp[i].increment=Increment(emp[i].salary,12);
        emp[i].total_salary=emp[i].salary+emp[i].increment;
    }

    for(int i=0;i<=4;i++){
        printf("Total Salary of Employee No.%d: %f\n",(i+1),emp[i].total_salary);
    }



}

