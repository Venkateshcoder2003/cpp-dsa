// C program to demonstrate the use of getc(), feof() and
// EOF
#include <stdio.h>

int main()
{
    // Open the file "test.txt" in read mode
    FILE *fp = fopen("test.txt", "r");
    // Read the first character from the file
    int ch = getc(fp);

    // Loop until the end of the file is
    // reached
    while (ch != EOF)
    {
        /* display contents of file on screen */
        putchar(ch);

        // Read the next character from the file
        ch = getc(fp);
    }

    // Check if the end-of-file indicator is
    // set for the file
    if (feof(fp))
        printf("\n End of file reached.");
    else
        printf("\n Something went wrong.");

    // Close the file
    fclose(fp);

    // Wait for a keypress
    getchar();
    return 0;
}
