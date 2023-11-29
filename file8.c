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
        if (ch == ' ')
        {
            count++;
        }
    }
    fclose(fp);
    printf("Number Of strings/Words:%d \n", count);
    return 0;
}