#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp;
    char str[20];
    fp = fopen("file3.txt", "w");
    printf("Enter a String: \n");
    scanf("%s", str);
    if (fp == NULL)
    {
        printf("error in Opening a file");
        return 1;
    }
    for (int i = 0; i < strlen(str); i++)
    {
        fputc(str[i], fp);
    }
    fclose(fp);
}