#include <stdio.h>
int main()
{
    int n, r, mask, s = 0, base = 1, temp2, r2, s2 = 0, base1 = 1;
    printf("Enter a Number: \n");
    scanf("%d", &n);
    int temp = n;
    while (temp != 0)
    {
        r = temp % 2;
        s = s + r * base;
        temp = temp / 2;
        base = base * 10;
    }
    printf("Decimal to Binary : %d\n", s);
    int s1 = s;
    int c = 0;
    while (s1 != 0)
    {
        s1 = s1 / 10;
        c++;
    }
    int temp1 = n;
    for (int i = 0; i < c; i++)
    {
        mask = 1 << i;
        if ((temp1 & mask) != 0)
        {
            break;
        }
        else
        {
            continue;
        }
    }

    int final_res = n ^ mask;
    printf("%d", final_res);
    temp2 = final_res;
    while (temp2 != 0)
    {
        r2 = temp2 % 2;
        s2 = s2 + r2 * base1;
        temp2 = temp2 / 2;
        base1 = base1 * 10;
    }
    printf("\nDecimal To Binary: %d\n", s2);
}