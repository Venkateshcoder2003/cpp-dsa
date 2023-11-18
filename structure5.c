#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
    char temp1[20], temp2[20], temp3[20], branch[20], temp_branch[20];

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
    printf("Enter Branch Of student Whose Details u Want: \n");
    scanf("%s", &branch);

    char ori_branch[20];
    strcpy(ori_branch, branch);
    // converting user 2nd input to Uppercase
    for (int i = 0; ori_branch[i] != '\0'; i++)
    {
        ori_branch[i] = toupper(ori_branch[i]);
    }

    for (int i = 0; i < n; i++)
    {
        temp_branch[20] = s[i].branch;
        for (int k = 0; s[i].branch[k] != '\0'; k++)
        {
            temp_branch[k] = toupper(s[i].branch[k]);
        }
        int res = strcmp(temp_branch, ori_branch);
        if (res == 0)
        {
            printf("Details Of Student Who Belongs To %s Branch Is: \n", ori_branch);
            printf("Name: %s\nUSN: %s\nBranch: %s\nPercentage: %f\n", s[i].name, s[i].usn, ori_branch, s[i].percentage);
        }
    }
}