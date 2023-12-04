#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n], ct[n], temp[n];

    float awt = 0, atat = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time Of Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter Arrival Time Of Process %d: ", i + 1);
        scanf("%d", &at[i]);
    }

    temp[0] = 0;
    printf("PROCESS\t\tBURST TIME\tARRIVAL TIME\tWAITING TIME\tTURN AROUND TIME\tCOMPLETION TIME\n");
    for (int i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;

        // Calculate waiting time, turn-around time, and completion time
        if (i > 0)
        {
            temp[i] = temp[i - 1] + bt[i - 1];
            wt[i] = temp[i] - at[i];
        }

        tat[i] = wt[i] + bt[i];
        ct[i] = tat[i] + at[i];

        awt += wt[i];
        atat += tat[i];

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i], ct[i]);
    }

    awt = awt / n;
    atat = atat / n;
    printf("Average Waiting Time: %.2f\n", awt);
    printf("Average Turn Around Time: %.2f\n", atat);

    return 0;
}
