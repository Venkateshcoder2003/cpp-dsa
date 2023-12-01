#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Euclidian
{
    int x1, x2, y1, y2;
};

struct Euclidian set_data()
{
    struct Euclidian E1;
    printf("Enter (x-coordinates) x1 and x2 Respectively: \n");
    scanf("%d%d", &E1.x1, &E1.x2);
    printf("Enter (y-coordinates) y1 and y2 Respectively: \n");
    scanf("%d%d", &E1.y1, &E1.y2);
    return E1;
}
int main()
{
    float dis, A, B;
    struct Euclidian E = set_data();

    dis = sqrt(pow(E.x2 - E.x1, 2) + pow(E.y2 - E.y1, 2));
    printf("Euclidian Distance Between Two Points In Two-Dimensional Space IS: %.2f UNITS", dis);
    return 0;
}
