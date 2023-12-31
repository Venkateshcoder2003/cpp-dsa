#include <stdio.h>

int fun(int n)
{
    if (n > 0)
    {
        printf("%d\t", n);
        fun(n - 1);
    }
}

int main()
{
    int a = 3;
    fun(a);
    printf("\n");

    return 0;
}