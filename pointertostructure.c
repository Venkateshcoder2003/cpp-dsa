#include <stdio.h>

struct student
{
    int roll;
    char name[20];
    int marks;
};

struct student s1 = {1, "venki", 88};
int main()
{

    struct student *ptr = &s1;
    printf("Roll Number: %d\n", (*ptr).roll);
    printf("Name: %s\n", (*ptr).name);
    printf("Marks: %d\n", (*ptr).marks);

    printf("Roll Number: %d\n", ptr->roll);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %d\n", ptr->marks);
}
