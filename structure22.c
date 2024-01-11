#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EMPLOYEE
{
    int empid;
    char name[25];
    char dept[25];
    int salary;
    int age;
} e;

void Add_record(FILE *fp)
{

    printf("Enter Employee Details: \n");
    printf("Employee Id: \n");
    scanf("%d", &e.empid);
    printf("Employee Name: \n");
    scanf("%s", e.name);
    printf("Employee Department: \n");
    scanf("%s", e.dept);
    printf("Employee Salary: \n");
    scanf("%d", &e.salary);
    printf("Employee Age: \n");
    scanf("%d", &e.age);
    fprintf(fp, "%d\t%s\t%s\t%d\t%d\n", e.empid, e.name, e.dept, e.salary, e.age);
    printf("\nRecord Added Successfully");
}

void Display_record(FILE *fp)
{
    printf("_____________________________________________________________________________________\n");
    printf("%-20s%-20s%-20s%-20s%-20s\n", "ID", "NAME", "DEPARTMENT", "SALARY", "AGE");
    printf("_____________________________________________________________________________________");

    while ((fscanf(fp, "%d%s%s%d%d", &e.empid, e.name, e.dept, &e.salary, &e.age)) != EOF)
    {
        printf("\n%-20d%-20s%-20s%-20d%-20d", e.empid, e.name, e.dept, e.salary, e.age);
    }
}
void Search_record(FILE *fp)
{
    int flag = 0;
    char dept[25];

    printf("Enter Dept To Be Searched: \n");
    scanf("%s", dept);

    if (strcmp(e.dept, dept) == 0)
    {
        Display_record(fp);
        flag++;
    }

    if (flag == 0)
    {
        printf("No Data Found for Department: %s\n", dept);
    }
}

int main()
{
    FILE *fp;
    int choice;

    while (1)
    {
        printf("\n1:Add_record\n2:Search_Record\n3:Display_Record\n4:Exit\n");
        printf("Enter Your Choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            fp = fopen("empfile", "a+");
            if (fp == NULL)
                printf("\nError IN Opening a File\n");
            else
            {
                Add_record(fp);
                fclose(fp);
            }
            break;

        case 2:
            fp = fopen("empfile", "r+");
            if (fp == NULL)
                printf("\nError In Opening a File\n");
            else
            {
                Search_record(fp);
                fclose(fp);
            }

            break;
        case 3:
            fp = fopen("empfile", "r+");
            if (fp == NULL)
                printf("No Records To Display");
            else
            {
                Display_record(fp);
                fclose(fp);
            }
            break;

        case 4:
            exit(0);
        default:
            printf("\n*****Ivalid Choice.....Please Try Again*****\n");
        }
    }

    return 0;
}