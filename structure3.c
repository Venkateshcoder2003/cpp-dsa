#include <stdio.h>

struct employee
{
    char name[20];
    int id;
    int salary;
};
int main()
{
    int n;
    char temp[20];
    printf("Enter Number Of Employees: \n");
    scanf("%d", &n);

    struct employee e[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Employee %d Details: \n", i + 1);
        printf("Enter Name Of Employee %d: ");
        scanf("%s", temp);
        strcpy(e[i].name, temp);
        printf("Enter id and salary of Employee %d: \n");
        scanf("%d %d", &e[i].id, &e[i].salary);
    }
    printf("\nDetails Of Employee Are: ");
    for (int i = 0; i < n; i++)
    {
        printf("\nDetails Of Employee %d: ", i + 1);
        printf("\nName: %s\nID:%d\nSalary:%d\n", e[i].name, e[i].id, e[i].salary);
    }
}