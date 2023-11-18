#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct student
{
    char name[20];
    char usn[15];
    char branch[10];
    float percentage;
};

int main()
{
    int n;
    char temp1[20], temp2[10], temp3[20], temp4[5], ch[5], ori_ch[10], ori_name[20];
    printf("Enter Number Of Students: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("\n Invalid Number Of Students");
        exit(0);
    }
    struct student s[n];
    printf("\nEnter Student Details: ");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Name Of Student %d: ", i + 1);
        scanf("%s", temp1);
        strcpy(s[i].name, temp1);
        printf("Enter USN Of Student %d: \n", i + 1);
        scanf("%s", temp2);
        strcpy(s[i].usn, temp2);
        printf("Enter Branch Of Student %d: \n", i + 1);
        scanf("%s", temp3);
        strcpy(s[i].branch, temp3);
        printf("Enter Marks Of Student %d: \n", i + 1);
        scanf("%f", &s[i].percentage);
    }
    printf("Enter Letter: \n");
    scanf("%s", temp4);
    strcpy(ch, temp4);
    // converting user input to uppercase

    strcpy(ori_ch, ch);
    for (int i = 0; ori_ch[i] != '\0'; i++)
    {
        ori_ch[i] = toupper(ch[i]);
    }

    for (int i = 0; i < n; i++)
    {
        strcpy(ori_name, s[i].name);
        for (int j = 0; ori_name[j] != '\0'; j++)
        {
            ori_name[j] = toupper(s[i].name[j]);
        }
        // int res = strcmp(ori_name[0], ori_ch);
        if (ori_name[0] == ori_ch[0])
        {
            printf("The Student Details Starts With %s letter Is : \n", ori_ch);
            printf("Name:%s\nUSN:%s\nBranch:%s\nPercentage:%.2f\n", ori_name, s[i].usn, s[i].branch, s[i].percentage);
            printf("______________________________________________________________________\n");
        }
        else
        {
            printf("Student %s's Name Not Starts With letter %s\n", s[i].name, ori_ch);
            printf("____________________________________________________________\n");
        }
    }
}