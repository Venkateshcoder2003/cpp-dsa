#include <stdio.h>

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int temp = n;
    int sum = 0, base = 1, rem;
    while (temp != 0)
    {
        rem = temp % 2;
        sum = sum + rem * base;
        temp = temp / 2;
        base = base * 10;
    }
    printf("Decimal To Binary Is: %d\n", sum);
    int res = n & (n - 1);
    printf("Number After Removing Last bit is: %d\n", res);
    int temp2 = res, sum1 = 0, base1 = 1, r;
    while (temp2 != 0)
    {
        r = temp2 % 2;
        sum1 = sum1 + r * base1;
        temp2 = temp2 / 2;
        base1 = base1 * 10;
    }
    printf("Decimal To Binary Is: %d\n", sum1);
}