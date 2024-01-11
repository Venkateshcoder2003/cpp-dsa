
#include <stdio.h>
int main()
{
    union Data
    {
        char a[10];
        int b;
        float c;
    };
    union Data d[10];
    int i, n, choice, index[10];

    printf("\nEnter the size of the array:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter a character: ");
            scanf("%s", d[i].a);
            index[i] = choice;
            break;

        case 2:
            printf("\nEnter an integer: ");
            scanf("%d", &d[i].b);
            index[i] = choice;
            break;
        case 3:
            printf("\nEnter a real number: ");
            scanf("%f", &d[i].c);
            index[i] = choice;
            break;
        }
    }

    printf("\nArray Contents:");
    for (i = 0; i < n; i++)
    {
        switch (index[i])
        {
        case 1:
            printf("\nd[%d] = '%s'", i, d[i].a);
            break;

        case 2:
            printf("\nd[%d] = %d", i, d[i].b);
            break;
        case 3:
            printf("\nd[%d] = %f", i, d[i].c);
            break;
        }
    }
    return 0;
}