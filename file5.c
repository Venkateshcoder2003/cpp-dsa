#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp, *fp1;

    char line[50];
    fp = fopen("abc.txt", "w+");
    if (fp == NULL)
    {
        printf("Error In Opening a File\n");
        return 1;
    }
    printf("Enter a Line: ");
    if (fgets(line, sizeof(line), stdin) != NULL)
    {
        printf("Entered line is : \n");
        printf(line);
    }
    else
    {
        printf("ERROR");
    }
    fputs(line, fp);
    fclose(fp);

    fp1 = fopen("abcd.txt", "w");
    if (fp1 == NULL)
    {
        printf("Error In Opening a File\n");
        return 1;
    }

    fputs(line, fp);

    fclose(fp1);
}