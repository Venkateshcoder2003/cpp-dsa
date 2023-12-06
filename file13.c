#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    fp = fopen("good.txt", "w+");

    if (fp == NULL)
    {
        printf("Error In Opening a file\n");
        return 1;
    }

    char ch;
    int count = 0;
    char str[30];
    printf("Enterr a Line to The File: \n");
    fgets(str, sizeof(str), stdin);
    fputs(str, fp);

    fseek(fp, 0, SEEK_SET);
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == 'v')
        {
            count++;
        }
    }
    printf("The Character (a) Occurs %d Times in Given File\n", count);
    fclose(fp);
    return 0;
}