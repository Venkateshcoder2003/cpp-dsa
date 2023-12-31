#include <stdio.h>

void print_name(char *name, int n)
{
    if (n == 0)
        return;
    printf("%s\t", name);
    return (print_name(name, n - 1));
}
int main()
{
    int n;
    char name[20];
    printf("Enter Name :");
    scanf("%s", name);
    printf("Enter N value: ");
    scanf("%d", &n);
    print_name(name, n);
}