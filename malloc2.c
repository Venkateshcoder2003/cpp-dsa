#include <stdio.h>
#include <stdlib.H>

struct student
{
    char name[20];
    int marks;
    int roll;
};

int main()
{
    struct student s, *str_ptr;

    str_ptr = (struct student *)malloc(sizeof(struct student));
    printf("Enter Details Of Student: \n");
    scanf("%s%d%d", str_ptr->name, &str_ptr->marks, &str_ptr->roll);

    printf("Details Of Student Are: \n");
    printf("Name: %s\n", str_ptr->name);
    printf("Marks: %d\n", str_ptr->marks);
    printf("Roll Number: %d\n", str_ptr->roll);

    free(str_ptr);
}