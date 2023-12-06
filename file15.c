#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("good.txt", "r+");
    if (fp == NULL)
    {
        printf("Error");
        exit(0);
    }

    fseek(fp, 10, SEEK_SET);
    char ch1, ch2 = 'T', temp;
    ch1 = fgetc(fp);
    fseek(fp, -1, SEEK_CUR);
    // printf("%c", ch1);
    temp = ch1;
    ch1 = ch2;
    ch2 = temp;
    fputc(ch1, fp);

    fclose(fp);
}