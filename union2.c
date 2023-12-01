#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

union circle
{
    float radius;
};
union square
{
    float side;
};
struct rectangle
{
    float length;
    float breadth;
};

int main()
{
    struct area
    {
        int choice;
        union circle c;
        union square s;
        struct rectangle r;
    };

    struct area A;

    printf("\n1:CIRCLE\n2:SQUARE\n3:RECTANGLE\n4:EXIT\n");

    while (1)
    {
        printf("\nEnter Your Choice: ");
        scanf("%d", &A.choice);
        switch (A.choice)
        {
        case 1:
            printf("Enter Radius Of Circle: \n");
            scanf("%f", &A.c.radius);
            printf("Area Of Circle IS: %.2f UNITS", (3.14 * A.c.radius * A.c.radius));
            break;

        case 2:
            printf("Enter Side Of Square: \n");
            scanf("%f", &A.s.side);
            printf("Area Of Square Is : %.2f UNITS", A.s.side * A.s.side);
            break;

        case 3:
            printf("Enter Length And Breadth Of Rectangle: \n");
            scanf("%f%f", &A.r.length, &A.r.breadth);
            printf("Area Of Rectangle Is: %.2f UNITS", A.r.length * A.r.breadth);
            break;

        case 4:
            printf("*****Exiting From The Program*****\n");
            exit(0);
        default:
            printf("Invalid Choice");
        }
    }
    return 0;
}