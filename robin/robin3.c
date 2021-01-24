#include<stdio.h>

struct patient_info {

    int patient_id,total_bill,admt_date;
    char patient_name[100];

};

int main(){

    int num,i;
    printf("Enter the number of patients:\n");
    scanf("%d",&num);

    struct patient_info info[num];

    for(i=0;i<num;i++){
        printf("Patient-%d ID: ",i+1);
        scanf("%d",&info[i].patient_id);

        printf("Patient-%d Name: ",i+1);
        fflush(stdin);
        gets(info[i].patient_name);

        printf("Patient-%d Bill: ",i+1);
        scanf("%d",&info[i].total_bill);

        printf("Patient-%d Adm Dt(yymmdd): ",i+1);
        scanf("%d",&info[i].admt_date);


    }

    int id;


    printf("Which patient info you need for display? Enter prod id: ");
    scanf("%d",&id);

    for(i=0;i<num;i++){
        if(info[i].patient_id==id){
            printf("Name : %s\n",info[i].patient_name);
            printf("Bill : %d\n",info[i].total_bill);
            printf("Admt Dt(yymmdd) : %d\n",info[i].admt_date);
            return 0;
        }

    }
    printf("data not found");
    return 0;
}