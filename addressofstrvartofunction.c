#include <stdio.h>
#include <string.h>

struct student
{
    char name[30];
    int roll;
    float marks;
};

void set_data(struct student *s2);
void get_data(struct student *s3);
char get_grade(float marks);

int main()
{
    struct student s1;
    set_data(&s1);
    return 0;
}

void set_data(struct student *s2)
{
    printf("Enter Student Details: \n");
    char temp[30];
    printf("Name: \n");
    scanf("%s", temp);
    strcpy(s2->name, temp);
    printf("Roll Number: \n");
    scanf("%d", &s2->roll);
    printf("Marks: \n");
    scanf("%f", &s2->marks);
    get_data(s2);
}

void get_data(struct student *s3)
{
    printf("\n");
    printf("Name: %s\nRoll Number: %d\n", s3->name, s3->roll);
    printf("Grade: %c\n", get_grade(s3->marks));
}

char get_grade(float marks)
{
    if (marks >= 90)
        return 'A';
    else if (marks >= 80)
        return 'B';
    else if (marks >= 70)
        return 'C';
    else if (marks >= 60)
        return 'D';
    else if (marks >= 50)
        return 'E';
    else
        return 'F';
}
