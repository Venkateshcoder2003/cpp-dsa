#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("abc.txt", "a");
    if (fp == NULL)
    {
        printf("Error In Opening a File\n");
        return 1;
    }

    fputs("\n good morning", fp);
    fclose(fp);
    printf("APPENDING SUCCESSFULL\n");
    return 0;
}