#include <stdio.h>

int main()
{
    FILE *fp;

    char str[10];
    printf("Enter a String: \n");
    scanf("%s", str);

    fp = fopen("file2.txt", "w");

    fputs(str, fp);

    fclose(fp);
}