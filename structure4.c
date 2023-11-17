#include <stdio.h>

struct student
{
    char name[20];
    char usn[10];
    char branch[5];
    float percentage;
};
int main()
{
    int n;
    char temp1[20], temp2[20], temp3[20];

    printf("Enter Number Of Students: \n");
    scanf("%d", &n);

    struct student s[n];
    printf("Enter Student Details: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter Name Of Student %d: \n", i + 1);
        scanf("%s", temp1);
        strcpy(s[i].name, temp1);
        printf("Enter USN Of student %d: \n", i + 1);
        scanf("%s", temp2);
        strcpy(s[i].usn, temp2);
        printf("Enter Branch Of Student %d: \n", i + 1);
        scanf("%s", temp3);
        strcpy(s[i].branch, temp3);
        printf("Enter Marks Of Student %d: \n", i + 1);
        scanf("%f", &s[i].percentage);
    }
    printf("Checking If Marks In The Range 90-100: \n");
    for (int i = 0; i < n; i++)
    {
        if (s[i].percentage >= 90 && s[i].percentage <= 100)
        {
            printf("Detail Of student %d who got 90-100 marks Is: \n", i + 1);
            printf("Name:%s\nUSN:%s\nBranch:%s\nPercentage:%.2f\n", s[i].name, s[i].usn, s[i].branch, s[i].percentage);
        }
        else
        {
            printf("Student %d Is Not Got Enough marks\n", i + 1);
        }
    }
}