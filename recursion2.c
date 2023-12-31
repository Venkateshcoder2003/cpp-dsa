#include <stdio.h>
int x = 0;
int fun(int n)
{

    if (n == 0)
        return 0;
    x++;
    return (fun(n - 1) + x);
}
int main()
{
    int a = 5;
    printf("%d", fun(a));
    return 0;
}