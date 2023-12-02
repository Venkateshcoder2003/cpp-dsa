#include <stdio.h>

struct point
{
    int x, y;
};

struct point find_min(struct point p1[], int);
struct point find_max(struct point p1[], int);

void get_data(struct point p1[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("Enter x and y coordinates of point %d: \n", i + 1);
        scanf("%d%d", &p1[i].x, &p1[i].y);
    }
}

int main()
{

    int n;
    printf("Enter Size Of Array: \n");
    scanf("%d", &n);

    struct point p[n];
    get_data(p, n);
    struct point minpoint = find_min(p, n);
    struct point maxpoint = find_max(p, n);
    printf("Mininum Point IS :(%d,%d)\n", minpoint.x, minpoint.y);
    printf("Maximum Point Is: (%d,%d)\n", maxpoint.x, maxpoint.y);

    return 0;
}

struct point find_min(struct point p1[], int n)
{
    struct point min = p1[0];

    for (int i = 1; i < n; i++)
    {

        if (p1[i].x < min.x)
        {
            min = p1[i];
        }
    }
    return min;
}

struct point find_max(struct point p1[], int n)
{

    struct point max = p1[0];
    for (int i = 1; i < n; i++)
    {

        if (p1[i].x > max.x)
        {
            max = p1[i];
        }
    }
    return max;
}