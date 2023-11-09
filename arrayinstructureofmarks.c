#include <stdio.h>
#include <string.h>

struct student
{
    char name[20];
    int roll;
    int marks[5];
};
int sum = 0;
int sum_array[2];
int main()
{
    int max = 0, new_index;
    int empt_array[50];
    char temp[20];
    int no_of_students;
    printf("Enter The Number Of Students: \n");
    scanf("%d", &no_of_students);

    if (no_of_students <= 0)
    {
        printf("Invalid Number of Student Entered \n");
        return 1;
    }

    struct student s[no_of_students];
    for (int i = 0; i < no_of_students; i++)
    {
        printf("Enter Details of Student %d\n", i + 1);
        printf("Enter Name: \n");
        scanf("%s", temp);
        strcpy(s[i].name, temp);
        printf("Enter Roll-Number: \n");
        scanf("%d", &s[i].roll);
        printf("Enter Marks: \n");
        for (int j = 0; j < 5; j++)
        {
            printf("Enter marks in subject %d: \n", j + 1);
            scanf("%d", &s[i].marks[j]);
            empt_array[j] = s[i].marks[j];
        }
    }
    // Printing Student Details
    printf("Printing Student Details \n");
    for (int m = 0; m < no_of_students; m++)
    {
        printf("____________________________________________\n");
        printf("Details Of Student %d\n", m + 1);
        printf("Name: %s\n", s[m].name);
        printf("Age: %d\n", s[m].roll);

        for (int n = 0; n < 5; n++)
        {
            printf("Marks Of Student in subject %d: \n", n + 1);
            printf("%d\n", s[m].marks[n]);
        }
    }
    // Finding Average Marks
    for (int v = 0; v < no_of_students; v++)
    {

        for (int u = 0; u < 5; u++)
        {
            sum = sum + empt_array[u];
        }
        printf("Total Marks Of Student %d is %d\n", v + 1, sum);
        // float avg = sum / (float)5;
        // printf("Average Marks: %d\n", avg);
        sum_array[v] = sum;
    }

    for (int w = 0; w < no_of_students; w++)
    {
        if (sum_array[w] > max)
        {
            max = sum_array[w];
            new_index = w;
        }
    }
    printf("Student %s Got Highest Average Marks Of %d\n", s[new_index].name, max);
}