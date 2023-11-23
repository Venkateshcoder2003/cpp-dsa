#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *ptr;
    printf("Enter N: \n");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory Allocation Failed\n");
    }
    printf("Enter Elements: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }
    printf("Entered Elements Are: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(ptr + i));
    }
}