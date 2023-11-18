#include <stdio.h>
int main()
{
    int n, n1, n2, s = 0, r, base = 1, sum = 0, base1 = 1;
    printf("Enter n: \n");
    scanf("%d", &n);
    int i;
    printf("Enter Position To Clear: \n");
    scanf("%d", &i);
    n1 = n;
    while (n1 != 0)
    {
        r = n1 % 2;
        s = s + r * base;
        n1 = n1 / 2;
        base = base * 10;
    }
    printf("Number Before Clearing In Binary Format : %d\n", s);
    int m = 1 << i;
    int mask = ~m;
    int n3 = n & mask;
    printf("NUmber After Clearing: \n");
    printf("%d\n", n3);

    int temp = n3;
    while (temp != 0)
    {
        int rem = temp % 2;
        sum = sum + rem * base1;
        temp = temp / 2;
        base1 = base1 * 10;
    }
    printf("Number In Binary Format Is: %d", sum);
}
