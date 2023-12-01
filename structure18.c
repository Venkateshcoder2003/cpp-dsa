#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct student
{
    char name[20];
    int roll;
    float marks;
};
struct student get_data()
{
    struct student p;
    printf("Enter Name,Roll NUmber and Marks Of Student Respectively: \n");
    scanf("%s%d%f", p.name, &p.roll, &p.marks);

    return p;
}
int main()
{
    struct student s = get_data();

    printf("NAME:%s\nROLL NUMBER:%d\nMARKS:%.2f\n", s.name, s.roll, s.marks);
    return 0;
}