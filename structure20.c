#include <stdio.h>
#include <stdlib.h>

struct point
{
    int x, y;
};
struct point get_p1()
{
    struct point p1;
    printf("Enter X and Y coordinates Of Point p1: \n");
    scanf("%d%d", &p1.x, &p1.y);

    return p1;
}
struct point get_p2()
{
    struct point p2;
    printf("Enter X and Y coordinates of Point p2: \n");
    scanf("%d%d", &p2.x, &p2.y);

    return p2;
}
int main()
{
    struct point p1 = get_p1();
    struct point p2 = get_p2();

    printf("Sum Of X Coordinates Is: %d\n", p1.x + p2.x);
    printf("Sum Of y Coordinates Is: %d\n", p1.y + p2.y);
    return 0;
}