#include <stdio.h>

struct process
{
    int at;
    int bt;
    int wt;
    int tat;
    int ct;
    int temp;
};

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    float awt = 0, atat = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time Of Process %d: ", i + 1);
        scanf("%d", &p[i].bt);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter Arrival Time Of Process %d: ", i + 1);
        scanf("%d", &p[i].at);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                struct process temp1 = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp1;
            }
        }
    }

    p[0].temp = 0;
    printf("PROCESS\t\tBURST TIME\tARRIVAL TIME\tWAITING TIME\tTURN AROUND TIME\tCOMPLETION TIME\n");
    for (int i = 0; i < n; i++)
    {
        p[i].wt = 0;
        p[i].tat = 0;

        // Calculate waiting time, turn-around time, and completion time
        if (i > 0)
        {
            p[i].temp = p[i - 1].temp + p[i - 1].bt;
            p[i].wt = p[i].temp - p[i].at;
        }

        p[i].tat = p[i].wt + p[i].bt;
        p[i].ct = p[i].tat + p[i].at;

        awt += p[i].wt;
        atat += p[i].tat;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", i + 1, p[i].bt, p[i].at, p[i].wt, p[i].tat, p[i].ct);
    }

    awt = awt / n;
    atat = atat / n;
    printf("Average Waiting Time: %.2f\n", awt);
    printf("Average Turn Around Time: %.2f\n", atat);

    return 0;
}
