#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int r;
    int n;
    char str[20];

    fp = fopen("good.txt", "w+");
    if (fp == NULL)
    {
        printf("Error In Opening a File\n");
        exit(0);
    }
    printf("Enter An Integer,real and String Into File: \n");
    scanf("%d%d%s", &n, &r, str);
    fprintf(fp, "%d\t%d\t%s\t", n, r, str);

    rewind(fp);

    printf("File Contents Are: \n");
    fscanf(fp, "%d%d%s", &n, &r, str);
    printf("%d\t%d\t%s", n, r, str);

    fclose(fp);
}