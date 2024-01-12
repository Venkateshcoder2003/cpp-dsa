#include <stdio.h>
int i = 8;
int funB(int);
int fun(int n)
{
    if (n == 0)
        funB(n);
    printf("%d", n);
    return fun(n - 1);
}
int funB(int j)
{
    if (j > i / 2)
    {
        return 0;
    }
    printf("%d", j + 1);
    return funB(j + 1);
}

int main()
{

    fun(i / 2);
    return 0;
}