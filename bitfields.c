#include <stdio.h>

int main()
{
    int number, i;
    printf("Enter a Number: ");
    scanf("%d", &number);

    printf("Enter the Position To Check: ");
    scanf("%d", &i);

    int mask = 1 << i;
    int result = number & mask;

    if (result != 0)
    {
        printf("The Bit At position %d is setbit(1)\n", i);
    }
    else
        printf("The Bit At position %d is Not a setbit(1)\n", i);
}