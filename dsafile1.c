#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;

    fp = fopen("file1.txt", "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Error in accessing file\n");
        return 1;
    }

    printf("Enter Character: ");
    scanf(" %c", &ch);

    fputc(ch, fp); // Corrected line

    fclose(fp);

    return 0;
}
