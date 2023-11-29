#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    char ch;
    char str[10];
    fp = fopen("abc.txt", "w+");
    if (fp == NULL)
    {
        printf("Error In Opening a File\n");
        return 0;
    }
    printf("Enter a String: ");
    scanf("%s", str);
    fputs(str, fp);
    rewind(fp);
    printf("\nContent of File Is : \n");
    while ((ch = fgetc(fp)) != EOF)
    {

        printf("%c", ch);
    }
    fclose(fp);
}