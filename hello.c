
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Topper
{
    char name[20];
    char usn[13];
    float cgpa;
    int yop;
};
struct Topper print_data(struct Topper t[], int n);

int main()
{
    int n;
    char temp1[20], temp2[13];
    int y_arr[n]; // an array to store year of passing values
    printf("Enter Number Of Toppers: \n");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Ivalid Number Entered\n");
        return 1;
    }
    struct Topper t[n];
    printf("Enter Details Of Toppers: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter Details Of Topper %d: \n", i + 1);
        printf("Enter Name: \n");
        scanf("%s", temp1);
        strcpy(t[i].name, temp1);

        printf("Enter USN: \n");
        scanf("%s", temp2);
        strcpy(t[i].usn, temp2);

        printf("Enter CGPA: \n");
        scanf("%f", &t[i].cgpa);
        printf("Enter Year Of Passing: \n");
        scanf("%d", &t[i].yop);
    }

    print_data(t, n);
}
struct Topper print_data(struct Topper t[], int n)
{
    printf("______________________________________________________________________\n");
    printf("\n%-20s%-20s%-20s%-20s", "NAME", "USN", "CGPA", "YEAR OF PASSING");
    printf("\n______________________________________________________________________");

    for (int i = 0; i < n; i++)
    {
        printf("\n%-20s%-20s%-20f%-20d", t[i].name, t[i].usn, t[i].cgpa, t[i].yop);
    }
}