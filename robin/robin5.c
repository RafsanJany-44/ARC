#include<stdio.h>

struct fruit_struct{
    char fruit_name[50];
    int fruit_code,fruit_quantity,fruit_life,fruit_price;
};

int main(){

    FILE *ff;
    ff=fopen("fruit_file.txt","a");

    struct fruit_struct fruit;
    printf("Enter the fruit name : ");
    scanf("%s",fruit.fruit_name);

    printf("Enter the fruit code : ");
    scanf("%d",&fruit.fruit_code);

    printf("Enter the quantity : ");
    scanf("%d",&fruit.fruit_quantity);

    printf("Enter the store life(days) : ");
    scanf("%d",&fruit.fruit_life);

    printf("Enter the price (tk per kg) : ");
    scanf("%d",&fruit.fruit_price);

    fprintf(ff,"%s\n%d\n%d\n%d\n%d",fruit.fruit_name,fruit.fruit_code,fruit.fruit_quantity,fruit.fruit_life,fruit.fruit_price);
    printf("Data Entry Complete");

    return 0;
}