

#include<stdio.h>
#include<stdlib.h>
 
#define MAX 50	//Maximum number of elements that can be stored
 
int top=-1;
char stack[MAX];

 void push(char c)
{
	
	if(top==MAX-1)
	{
		printf("\nStack is full!!");
	}
	else
	{

		top=top+1;
		stack[top]=c;
	}
}
void pop()
{
	if(top==-1)
	{

	}
	else
	{
		top=top-1;
	}
}
 

int main()
{

    push('a');
    push('b');
    push('c');
    push('d');
    push('e');
    pop();
    printf("\nStack: ");
		for(int i=0;i<=top;i++){
			printf("%c",stack[i]);
            if (i!=top){printf(",");}
        }
}
 
