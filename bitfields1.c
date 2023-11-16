#include <stdio.h>

int main()
{
    int n, result, mask, i;
    printf("Enter Number: \n");
    scanf("%d", &n);

    printf("Enter index of bit to be extracted:\n");
    scanf("%d", &i);

    mask = 1 << i;
    result = n & mask;
    if (result != 0)
    {
        printf("bit At Entered Position %d Is: 1", i);
    }
    else
        printf("bit at Entered Position %d is 0", i);
}