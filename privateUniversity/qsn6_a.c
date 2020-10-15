
#include <stdio.h>

void swap(int *x,int *y)
{
    int t;
     t   = *x;
    *x   = *y;
    *y   =  t;
}

int main()
{
    int first_number,second_number;
    printf("Enter the first number: ");
    scanf("%d",&first_number);
    printf("Enter the second number: ");
    scanf("%d",&second_number);
    swap(&first_number,&second_number);
    printf("After  Swapping: first_number is: %d, second_numnber is: %d\n",first_number,second_number);
}