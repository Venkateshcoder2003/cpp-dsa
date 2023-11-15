#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    char name[20];
    int marks;
};

int main()
{
    char temp[20];
    struct student s1[3];
    printf("Enter Info... of Students: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("Enter Student %d Info...\n", i + 1);
        printf("Enter Roll Number: \n");
        scanf("%d", &s1[i].roll);
        printf("Enter Name Of Student: \n");
        scanf("%s", temp);
        strcpy(s1[i].name, temp);
        printf("Enter Marks: \n");
        scanf("%d", &s1[i].marks);
    }
    printf("******************Displaying Student Information*******************\n");
    for (int j = 0; j < 3; j++)
    {
        printf("Roll Number: %d\n", s1[j].roll);
        printf("NAME: %s\n", s1[j].name);
        printf("MARKS: %d\n", s1[j].marks);
    }
}