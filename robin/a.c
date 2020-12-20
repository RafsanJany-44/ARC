#include <stdio.h>
    int main ()
    {
        float n[10];
        int i, j, a;
        printf("Enter the numbers \n");
        for (i = 0; i < 10; ++i)
	        scanf("%f", &n[i]);
        for (i = 0; i < 10; ++i) 
        {
            for (j = i + 1; j < 10; ++j) 
            {
                if (n[i] < n[j]) 
                {
                    a = n[i];
                    n[i] = n[j];
                    n[j] = a;
                }
            }
        }
 
        printf("The numbers arranged in descending order are given below\n");
 
        for (i = 0; i < 10; ++i) 
        {
            printf("%f ", n[i]);
        }
 
    }