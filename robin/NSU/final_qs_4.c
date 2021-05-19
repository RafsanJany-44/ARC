#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char f1[100],f2[100];
    printf("Enter the 1st file name: ");
    gets(f1);
    printf("Enter the 2nd file name: ");
    gets(f2);
    FILE *file1;
    char c[10000];
    file1 = fopen(f1, "r");
    if (file1 == NULL)
    {
        printf("File %s is not available \n",f1);
        return 0;
    }
    else
    {

        int i=0;
        FILE *file2;
        file2 = fopen(f2, "w");

        if (file2 != NULL) {
            while ((c[i] = fgetc(file1)) != EOF)
            {       
                if( c[i] >= 'a' && c[i] <= 'z' )
                    {
                    c[i] = c[i] - 32;
                    }
                fputc (c[i], file2);
                i++;
            }
            fclose(file2);		
        }
        else {
            printf("File %s is not available \n",f2);
            fclose(file1);
            return 0;
        }
                
    }
    fclose(file1);


    return 0;
}