#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct student
{
    char name[20];
    char usn[14];
    char branch[6];
    float marks;
};

int main()
{
    int n;
    char temp1[20], temp2[15], temp3[6], copy_usn[14], temp_usn[14];
    char ori_usn[14];
    printf("Enter Number Of Students: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("\n Invalid Number Of Students");
        exit(0);
    }
    struct student s[n];
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
        printf("Enter Marks Of Student %d: \n", i + 1);
        scanf("%f", &s[i].marks);
    }
    printf("Enter USN Of The Student: \n");
    scanf("%s", copy_usn);
    strcpy(temp_usn, copy_usn);
    printf("__________________________________________________________\n");

    for (int i = 0; temp_usn[i] != '\0'; i++)
    {
        temp_usn[i] = toupper(temp_usn[i]);
    }
    // printf("%s", temp_usn);

    for (int i = 0; i < n; i++)
    {
        strcpy(ori_usn, s[i].usn);
        for (int j = 0; ori_usn[j] != '\0'; j++)
        {
            ori_usn[j] = toupper(s[i].usn[j]);
        }
        int res = strcmp(ori_usn, temp_usn);
        if (res == 0)
        {
            printf("Name: %s\nUSN:%s\nBranch:%s\nMarks:%.2f\n", s[i].name, temp_usn, s[i].branch, s[i].marks);
            printf("________________________________________\n");
        }
        else
        {
            printf("Student %s's USN is Not Matching With The Current USN(%s)\n", s[i].name, temp_usn);
            printf("______________________________________________\n");
        }
    }
}