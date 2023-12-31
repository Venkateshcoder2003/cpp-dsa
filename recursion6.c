#include <stdio.h>

void funA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funB(n - 1);
    }
    return 0;
}

void funB(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funA(n / 2);
    }
    return 0;
}

int main()
{
    int x = 20;
    funA(x);
    return 0;
}