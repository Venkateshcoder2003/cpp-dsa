#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter Number 1: \n");
    scanf("%d", &num1);
    printf("Enter Number 2: \n");
    scanf("%d", &num2);

    printf("Values Before Swaping:\n%d\n%d\n", num1, num2);
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;

    printf("Values After Swaping:\n%d\n%d\n", num1, num2);
}