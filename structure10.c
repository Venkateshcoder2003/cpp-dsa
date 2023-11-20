#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct student
{
    char name[20];
    char usn[20];
    char branch[20];
    float marks;
};

void set_data(struct student s[], int n);
void print_data(struct student s[], int n);
void bubble_sort(struct student s[], int n);
void printdata(struct student s[], int n);
int main()
{
    int n;
    printf("Enter Number Of Students: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("\n Invalid Number Of Students");
        exit(0);
    }
    struct student s[n];
    set_data(s, n);
    print_data(s, n);
    bubble_sort(s, n);
    printdata(s, n);
}
void set_data(struct student s[], int n)
{
    char temp1[20], temp2[14], temp3[20];
    printf("Enter Student Details: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter Name Of Student %d: \n", i + 1);
        scanf("%s", temp1);
        strcpy(s[i].name, temp1);

        printf("Enter USN Of Student %d: \n", i + 1);
        scanf("%s", temp2);
        strcpy(s[i].usn, temp2);

        printf("Enter Branch Of Student %d: \n", i + 1);
        scanf("%s", temp3);
        strcpy(s[i].branch, temp3);
 
        printf("Enter marks Of Student %d: \n", i + 1);
        scanf("%f", &s[i].marks);
    }
}

void print_data(struct student s[], int n)
{
    printf("Printing Student Details Before Sorting: \n");
    printf("\n__________________________________________________________________________\n");
    printf("%-20s%-20s%-20s%-20s", "NAME", "USN", "BRANCH", "MARKS");
    printf("\n__________________________________________________________________________\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n%-20s%-20s%-20s%-20f", s[i].name, s[i].usn, s[i].branch, s[i].marks);
    }
    printf("\n__________________________________________________________________________\n");
}
void bubble_sort(struct student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].marks > s[j + 1].marks)
            {
                // swaping student details  by comparing  marks
                struct student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void printdata(struct student s[], int n)
{
    printf("\nStudent Details After Sorting: \n");
    printf("\n__________________________________________________________________________\n");
    printf("%-20s%-20s%-20s%-20s", "NAME", "USN", "BRANCH", "MARKS");
    printf("\n__________________________________________________________________________\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n%-20s%-20s%-20s%-20f", s[i].name, s[i].usn, s[i].branch, s[i].marks);
    }
    printf("\n__________________________________________________________________________\n");
} // student details using bubble sort