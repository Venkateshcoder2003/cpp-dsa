#include <stdio.h>
int check_sort(int arr[], int i, int n)
{
    if (i == n)
        return 1;
    if (arr[i] > arr[i + 1])
        return -1;
    return check_sort(arr, i + 1, n);
}
int main()
{
    int arr[5] = {1, 2, 3, 2, 5};

    int res;
    res = check_sort(arr, 0, 5);
    if (res == 1)
    {
        printf("\nArray is sorted!");
    }
    else
        printf("\nArray is not sorted!");
}