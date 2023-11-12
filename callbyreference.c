#include <stdio.h>
#include <string.h>

struct student
{
    char name[20];
    int roll;
    float per;
};

void set_data(struct student *s);
void display_data(struct student *s1);

int main()
{
    struct student s;
    set_data(&s);
}

void set_data(struct student *s1)
{
    char temp[20];
    printf("Enter Student Details: \n");
    printf("Enter Name: \n");
    scanf("%s", &temp);
    strcpy(s1->name, temp);
    printf("Enter Roll: \n");
    scanf("%d", &s1->roll);
    printf("Enter Percentage: \n");
    scanf("%f", &s1->per);
    display_data(s1);
}

void display_data(struct student *s1)
{
    printf("____________________________________________\n");
    printf("Name: %s\n  Roll: %d\n  percentage: %f\n", s1->name, s1->roll, s1->per);
}
