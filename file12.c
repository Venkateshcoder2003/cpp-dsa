#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("good.txt", "a+");
    if (fp == NULL)
    {
        printf("Error In Opening a File\n");
        return 1;
    }
    int n, num;
    printf("Enter Number Of Integers: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        fprintf(fp, "%d ", num);
    }
    fseek(fp, 0, SEEK_SET);
    int sum = 0;
    while ((fscanf(fp, "%d", &num)) != EOF)
    {
        sum = sum + num;
    }
    fprintf(fp, "SUM: %d\n", sum);
    fclose(fp);
}