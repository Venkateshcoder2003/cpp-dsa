#include <stdio.h>
#include <string.h>

struct doj
{
    int date, month, year;
};
struct salary
{
    int basic, da, hra;
};
struct employee
{
    char Ename[20];
    int Eid;
    struct doj d;
    struct salary s;
};
void print_employee_details(struct employee e[], int);
int main()
{
    int n;
    char temp1[20], temp2[20];
    printf("Enter Number Of Employees: \n");
    scanf("%d", &n);

    if (n <= 0)
    {
        fprintf(stderr, "Invalid Number Of Emoloyees\n");
        return 1;
    }
    struct employee e[n];
    printf("Enter The Details Of Employee: \n");
    // Reading Employee Details
    for (int i = 0; i < n; i++)
    {
        printf("Enter The Details Of Employee %d: \n", i + 1);
        printf("Enter Name Of Employee %d: \n", i + 1);
        scanf("%s", temp1);
        strcpy(e[i].Ename, temp1);

        printf("Enter Employee ID Of Employee %d: \n", i + 1);
        scanf("%d", &e[i].Eid);

        printf("Enter Employee's Joining Details: \n");

        printf("Enter Date Of Joining: \n");
        scanf("%d", &e[i].d.date);
        printf("Enter Month Of Joining: \n");
        scanf("%d", &e[i].d.month);
        printf("Enter Year Of Joining: \n");
        scanf("%d", &e[i].d.year);

        printf("Enter Salary Details Of Employee %d: \n");
        printf("Enter Basic Salary: \n");
        scanf("%d", &e[i].s.basic);
        printf("Enter da: \n");
        scanf("%d", &e[i].s.da);
        printf("Enter HRA: \n");
        scanf("%d", &e[i].s.hra);
    }
    // Displaying Employee Details
    print_employee_details(e, n);
}
void print_employee_details(struct employee e[], int n)
{
    printf("______________________________________________________________________________\n");
    printf("%s\t\t%s\t\t%s\t\t%s", "NAME", "id", "DATE OF JOINING", "GROSS SALARY");
    printf("\n______________________________________________________________________________");

    for (int i = 0; i < n; i++)
    {
        printf("\n%s\t\t%d\t\t%d:%d:%d\t\t%d", e[i].Ename, e[i].Eid, e[i].d.date, e[i].d.month, e[i].d.year, e[i].s.basic + e[i].s.da + e[i].s.hra);
    }
}
