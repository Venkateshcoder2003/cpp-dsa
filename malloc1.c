#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *ptr;
    printf("Enter Value Of n: \n");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }
    printf("Enter Values: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }
    printf("Entered Values Are: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", *(ptr + i));
    }

    free(ptr);
    return 0;
}
