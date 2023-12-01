#include <stdio.h>
#include <ctype.h>
#include <string.h>

union integer
{
    int num1;
    float num2;
};
int main()
{
    struct data
    {
        int choice;
        union integer d1;
    } d2;

    printf("\n1:INTEGER\n2:REAL NUMBER\n3:EXIT\n");

    while (1)
    {
        printf("\nEnter Your Choice: \n");
        scanf("%d", &d2.choice);

        switch (d2.choice)
        {
        case 1:
            printf("Enter An Integer: \n");
            scanf("%d", &d2.d1.num1);
            printf("Square Of a Integer Is: %d", d2.d1.num1 * d2.d1.num1);
            break;

        case 2:
            printf("Enter a Real Number: \n");
            scanf("%f", &d2.d1.num2);
            printf("Square Of Real Number Is: %.2f", d2.d1.num2 * d2.d1.num2);
            break;

        case 3:
            return 0;
        default:
            printf("Invalid Choice");
        }
    }
    return 0;
}
