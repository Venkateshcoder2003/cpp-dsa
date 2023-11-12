#include <stdio.h>

struct student
{
    char name[20];
    int roll;
    float cgpa;
};

void printinfo(struct student s1);
int main()
{
    struct student s1 = {"venki", 20, 9.2};
    printinfo(s1);

    s1.roll = 21;
    printf("%d\n", s1.roll);

    return 0;
}

void printinfo(struct student s1)
{
    printf("Student Information :\n");
    printf("%s\n", s1.name);
    printf("%d\n", s1.roll);
    printf("%0.2f\n", s1.cgpa);
}
