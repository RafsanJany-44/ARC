#include<stdio.h>

struct student
{
int ID;
char Gender;
float Class_test_score;
float Mid_term_score;
float Final_Exam_score;
float Total_score;
};


int passCount(struct student st[],int n){
    int i,count=0;
    float total=0;
    for(i=0;i<n;i++){
        total=st[i].Class_test_score+st[i].Mid_term_score+st[i].Final_Exam_score;
        if(total<60){
            count++;
        }
        total=0;
    }
    return count;
}

int highest_marks(struct student st[],int n){
    int i,max=0,index;
    float total;
    for(i=0;i<n;i++){
        total=st[i].Class_test_score+st[i].Mid_term_score+st[i].Final_Exam_score;
        if(total>max){
            max=total;
            index=i;
        }
        total=0;
    }
    return st[index].ID;
}


int main(){

    int N,i;
    printf("Enter the number of stdents: ");
    scanf("%d",&N);
    
    struct student st[N];    
    printf("Enter Records of 5 students");    
    for(i=0;i<N;i++){    
    printf("\nEnter Student ID:");    
    scanf("%d",&st[i].ID);    
    printf("\nEnter Student Gender:");    
    scanf(" %c",&st[i].Gender);
    printf("\nEnter Class_test_score:");    
    scanf("%f",&st[i].Class_test_score);    
    printf("\nEnter Mid_term_score:");    
    scanf("%f",&st[i].Mid_term_score);
    printf("\nFinal_Exam_score:");    
    scanf("%f",&st[i].Final_Exam_score);    
    }

    printf("\nNumber of Failed Student: %d ",passCount(st,N));
    printf("\nID of the student obtaining the highest marks: %d \n",highest_marks(st,N));

}