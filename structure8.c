#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    char name[20];
    char usn[20];
    int marks;
};

void bubblesort(struct student s[], int n);
void bubblesort(struct student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (s[j].marks > s[j + 1].marks)
            {
                // swap the students
                struct student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    char temp1[20], temp2[20];
    printf("Enter Number Of Students: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("\nInvalid Number Of Students");
        exit(0);
    }
    struct student s[n];
    printf("\nEnter Details Of Student: ");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Name OF Student %d: ", i + 1);
        scanf("%s", temp1);
        strcpy(s[i].name, temp1);

        printf("\nEnter USN Of Student %d: ", i + 1);
        scanf("%s", temp2);
        strcpy(s[i].usn, temp2);

        printf("\nEnter Marks Of Student %d: ", i + 1);
        scanf("%d", &s[i].marks);
    }
    bubblesort(s, n);

    printf("\nDetails Of Student After Bubble Sort: \n");
    printf("%-20s%-20s%-20s", "NAME", "USN", "MARKS", "\n");

    for (int i = 0; i < n; i++)
    {
        printf("\n%-20s%-20s%-20d", s[i].name, s[i].usn, s[i].marks);
    }
}