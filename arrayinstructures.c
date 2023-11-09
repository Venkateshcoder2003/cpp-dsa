#include <stdio.h>
#include <string.h>

struct student
{
    char name[20];
    int age;
    int marks[5];
};

int main()
{
    int num_of_student;
    printf("Enter Number Of Students: \n");
    scanf("%d", &num_of_student);
    char temp[20];
    if (num_of_student <= 0)
    {
        printf("invalid Number Of Students \n");
        return 1;
    }
    struct student s[num_of_student];

    for (int i = 0; i < num_of_student; i++)
    {
        printf("Enter Student %d Details \n", i + 1);
        printf("Enter Name Of Student: \n");
        scanf("%s", &temp);
        strcpy(s[i].name, temp);
        printf("Enter Age: \n");
        scanf("%d", &s[i].age);
        printf("Enter Marks Of Students in 5 Subjects: \n");

        for (int k = 0; k < 5; k++)
        {
            printf("Enter The Marks Of Subject %d :\n", k + 1);
            scanf("%d", &s[i].marks[k]);
        }
    }
    printf("Displaying Student Details: \n");
    for (int m = 0; m < num_of_student; m++)
    {
        printf("Details Of Student %d..... \n", m + 1);
        printf("Name: %s\n Age: %d\n", s[m].name, s[m].age);
        for (int n = 0; n < 5; n++)
        {
            printf("Marks In %d Subject: ", n + 1);
            printf("%d\n", s[m].marks[n]);
        }
    }
}