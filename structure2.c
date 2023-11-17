#include <stdio.h>

struct point
{
    int x, y;
};

struct line
{
    struct point p1, p2;
};

int main()
{
    struct line l;

    printf("Enter line 1 Information: \n");
    printf("Enter x-coordinate of First line: \n");
    scanf("%d", &l.p1.x);
    printf("Enter Y coorinate of First Line: \n");
    scanf("%d", &l.p1.y);

    printf("Enter Line 2 Information: \n");
    printf("Enter x-Coordinate of Second line: \n");
    scanf("%d", &l.p2.x);
    printf("Enter Y -coordinate Of second line: \n");
    scanf("%d", &l.p2.y);

    if (l.p1.x == l.p2.x && l.p1.y != l.p2.y)
    {
        printf("LINES ARE VERTICAL!\n");
    }
    else if (l.p1.x != l.p2.x && l.p1.y == l.p2.y)
    {
        printf("LINES ARE HORIZONTAL!\n");
    }
    else if (l.p1.x == l.p2.x && l.p1.y == l.p2.y)
    {
        printf("IT IS A SINGLE POINT\n");
    }
    else
        printf("IT IS NOT A VERTICAL NOR AN HORIZONTAL LINE ,IT'S A OBLIQUE LINE\n");
}
