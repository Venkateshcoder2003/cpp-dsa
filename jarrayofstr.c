#include <stdio.h>

struct student
{
    int roll;
    char name[20];
    float marks;
};

int main()
{
    struct student s[3];

    printf("Enter Student Information: ");
    for (int i = 0; i < 3; i++)
    {
        printf("Enter Info of student %d\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
    // Display Entered Information
    for (int j = 0; j < 3; j++)
    {
        printf("Info Of Student %d \n", j + 1);
        printf("ROLL NUMBER: %d\n", s[j].roll);
        printf("NAME: %s\n", s[j].name);
        printf("MARKS: %f\n", s[j].marks);
    }
    return 0;
}
