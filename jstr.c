#include <stdio.h>

struct student
{
    int roll;
    char name[20];
    int marks;
};
int main()
{
    struct student s1;
    printf("\n Enter Info Of Student 1: ");
    scanf("%d %s %d", &s1.roll, &s1.name, &s1.marks);

    printf("\n Entered Info Is : ");
    printf("\n Roll  Number: ");
    printf("%d", s1.roll);
    printf("\n Name: ");
    printf("%s", s1.name);
    printf("\n Marks: ");
    printf("%d", s1.marks);

    return 0;
}
