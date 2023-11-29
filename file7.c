#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    fp = fopen("abc.txt", "r");
    if (fp == NULL)
    {
        printf("\nError In Opening a File");
        exit(0);
    }
    int count = 1;
    while ((ch = fgetc(fp)) != EOF)
    {
        count++;
    }
    fclose(fp);
    printf("Number Of Lines:%d \n", count - 1);
    return 0;
}