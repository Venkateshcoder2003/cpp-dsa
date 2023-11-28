#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char c;
    fp1 = fopen("abc.txt", "r");
    fp2 = fopen("abcd.txt", "w");

    if (fp1 == NULL)
    {
        printf("Error IN Opening A Source File\n");
        return 1;
    }
    if (fp2 == NULL)
    {
        printf("Error In Opening a Destination File\n");
        return 1;
    }
    while ((c = fgetc(fp1)) != EOF)
    {
        fputc(c, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    printf("COPY SUCCESSFULL\n");
    return 0;
}