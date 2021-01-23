#include<stdio.h>
int main()
{
	
	int x, y, current_coordinate, target_coordinate;
	
	printf("Enter value of x\a: ");
	scanf("%d",&x);
	
	printf("Enter value of y\a: ");
	scanf("%d",&y);
	
	printf("\nEnter current coordinate \a: ");
	scanf("%d",&current_coordinate);
	
	printf("Enter target coordinate\a : ");
	scanf("%d",&target_coordinate);
	
	
	if(target_coordinate==1)
	{
		if(x<0)x=x*-1;
		if(y<0)y=y*-1;
		printf("\nNew value of x and y in the target coordinate is: (%d,%d)\n",x,y);
		
	}
	   else if(target_coordinate==2)
	   {
		  if(x>0)x=x*-1;
		  if(y<0)y=y*-1;
		  printf("\nNew value of x and y in the target coordinate is: (%d,%d)\n",x,y);
		  
	   }
	
	   else if(target_coordinate==3)
	   {
		  if(x>0)x=x*-1;
		  if(y>0)y=y*-1;
		  printf("\nNew value of x and y in the target coordinate is: (%d,%d)\n",x,y);
		  
	   }
	   else if(target_coordinate==4)
	   {
		  if(x<0)x=x*-1;
		  if(y>0)y=y*-1;
	
		printf("\nNew value of x and y in the target coordinate is: (%d,%d)\n",x,y);
		
	   }
       else
       {
		printf("Empty\n");
       }

//End of part a

//Part b starts here

    printf("\nEnter value of x\a: ");
    scanf("%d",&x);

    printf("Enter value of y\a: ");
    scanf("%d",&y);

    printf("\nEnter current coordinate\a : ");
    scanf("%d",&current_coordinate);

    printf("Enter target coordinate \a: ");
    scanf("%d",&target_coordinate);


    switch(target_coordinate)
    {
    case 1:
        if(x<0)x=x*-1;
        if(y<0)y=y*-1;

        printf("\nNew value of x and y in the target coordinate is: (%d,%d)\n",x,y);
        break;

    case 2:
        if(x>0)x=x*-1;
        if(y<0)y=y*-1;

        printf("\nNew value of x and y in the target coordinate is: (%d,%d)\n",x,y);
        break;

    case 3:
        if(x>0)x=x*-1;
        if(y>0)y=y*-1;

        printf("\nNew value of x and y in the target coordinate is: (%d,%d)\n",x,y);
        break;

    case 4:
        if(x<0)x=x*-1;
        if(y>0)y=y*-1;

        printf("\nNew value of x and y in the target coordinate is: (%d,%d)\n",x,y);
        break;

    default:
        printf("Empty\n");

    }

    return 0;
}