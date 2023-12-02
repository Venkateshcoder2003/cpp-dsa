
#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char ch;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");

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
    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    printf("COPY SUCCESSFULL\n");
    return 0;
}
