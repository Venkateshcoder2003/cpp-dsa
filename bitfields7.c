#include <stdio.h>

int main()
{

    int n;
    printf("Enter n: \n");
    scanf("%d", &n);

    int temp1 = n, r1, s1 = 0, base1 = 1, temp2, r2, s2 = 0, base2 = 1, mask, c = 0;
    while (temp1 != 0)
    {
        r1 = temp1 % 2;
        s1 = s1 + r1 * base1;
        temp1 = temp1 / 2;
        base1 = base1 * 10;
    }
    printf("Decimal To Binary is: %d\n", s1);

    int count = 0, temp = s1;
    while (temp != 0)
    {
        temp = temp / 10;
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        mask = 1 << i;
        if ((mask & n) != 0)
        {
            c++;
        }
        else
        {
            continue;
        }
    }
    printf("The Number Of Set Bits In Entered Number Is %d \n", c);
}