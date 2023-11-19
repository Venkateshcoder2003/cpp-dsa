#include <stdio.h>

int main()
{
    int n;
    printf("Enter Size: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array Elements: \n");
    for (int i = 0; i < n; i++)
    {
        // printf("Enter Element %d:\n", i + 1);
        scanf("%d", &arr[i]);
    }
    int xor = 0;
    for (int i = 0; i < n; i++)
    {

        xor = xor^arr[i];
    }
    printf("The Number Which Is Repeating One Time Is %d ", xor);
}