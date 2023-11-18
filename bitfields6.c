#include <stdio.h>

int main()
{
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);

    if ((n & (n - 1)) == 0)
    {
        printf("Entered Number %d is Power Of Two\n", n);
    }
    else
    {
        printf("Entered Number %d Is Not a power Of Two\n", n);
    }
}