#include <stdio.h>

int fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        printf("%d\t", n);
    }
}
int main()
{
    int a = 3;
    fun(a);

    return 0;
}