#include <stdio.h>
#include <string.h>

struct student
{
    char name[20];
    int roll;
    float percentage;
};

struct student s1;
void struct_display();

int main()
{
    // struct student s1; if we declare str variable once again here it will throw error
    strcpy(s1.name, "venki");
    s1.roll = 96;
    s1.percentage = 98.5;
    struct_display();
}

void struct_display()
{
    printf("Printing Student Details: \n");
    printf("Name: %s\n Roll: %d\n Percentage: %.2f\n", s1.name, s1.roll, s1.percentage);
}
