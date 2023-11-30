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
struct Topper sort_data(struct Topper t[], int n);

int main()
{
    int n;
    char temp1[20], temp2[13];

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

    sort_data(t, n);
    printf("_____________________________________________________________________________________\n");
    printf("%-20s%-20s%-20s%-20s", "NAME", "USN", "CGPA", "YEAR OF PASSING");
    printf("\n___________________________________________________________________________________\n");

    print_data(t, n);
}
struct Topper sort_data(struct Topper t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (t[j].yop > t[j + 1].yop)
            {
                struct Topper temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}
struct Topper print_data(struct Topper t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%-20s%-20s%-20f%-20d", t[i].name, t[i].usn, t[i].cgpa, t[i].yop);
    }
}
