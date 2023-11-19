#include <stdio.h>

int main()
{

    int n;
    printf("Enter Range: ");
    scanf("%d", &n);

    printf("XOR of All Numbers Between 1 to n: \n");
    int xor = 0;
    for (int i = 1; i <= n; i++)
    {
        xor = xor^i;
    }
    printf("%d\n", xor);

    printf("XOR of ANumbers Between 1 to n: \n");
    if (n % 4 == 0)
        printf("%d", n);
    else if (n % 4 == 1)
        printf("1");
    else if (n % 4 == 2)

        printf("%d", n + 1);
    else
        printf("0");
}