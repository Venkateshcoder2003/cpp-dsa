#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    int pos;
    fp = fopen("good.txt", "r"); // mode=r+,r,a+(for this code)
    if (fp == NULL)
    {
        printf("Error In Opening a File\n");
        exit(0);
    }

    // int pos1 = ftell(fp);
    rewind(fp);
    fseek(fp, 0, SEEK_END);
    pos = ftell(fp);
    printf("Length Of Text File Is: %d", pos);

    fclose(fp);
}