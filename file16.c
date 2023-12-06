#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch, ch1;
    FILE *fp, *fp1;
    fp = fopen("good1.txt", "w+");

    if (fp == NULL)
    {
        printf("ERROR in opening a file\n");
        exit(0);
    }

    // reading a sentence  from user
    char sent[50];
    printf("Enter a Sentence:\n");
    fgets(sent, sizeof(sent), stdin);
    fputs(sent, fp);
    printf("CONTENTS OF FILE BEFORE REVERSING: %s", sent);
    fclose(fp);

    fp = fopen("good1.txt", "r+"); // fp at 0
    fp1 = fopen("good2.txt", "w+");//new file
    fseek(fp, -3, SEEK_END); // fp set to last character
    int terminator = ftell(fp);
    printf("LAST CHARACTER NUMBER: %ld", terminator); // loop condition

    // char ch = fgetc(fp);
    // printf("\n%c", ch);
    while (terminator >= 0)
    {
        ch = fgetc(fp);
        fseek(fp, -2, SEEK_CUR);
        fputc(ch, fp1);
        terminator--;
    }
    rewind(fp1);
    printf("\nCONTENTS OF FILE AFTER REVERSING: ");
    while ((ch1 = fgetc(fp1)) != EOF)
    {
        printf("%c", ch1);
    }
    fclose(fp);
    fclose(fp1);
}