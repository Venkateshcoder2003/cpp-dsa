#include <stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int executed;
};

void findwaitingtime(struct process proc[], int n)
{

    int currenttime = 0, shortest = 0, completed = 0;
    float totalwaitingtime = 0, totalturnaroundtime = 0;

    while (completed != n)
    {
        shortest = -1;
        for (int i = 0; i < n; i++)
        {

            if (proc[i].at <= currenttime && proc[i].executed != 1)
            {
                if (shortest == -1 || proc[i].bt < proc[shortest].bt)
                {

                    shortest = i;
                }
            }
        }
        if (shortest == -1)
        {
            currenttime++;
            continue;
        }

        proc[shortest].ct = currenttime + proc[shortest].bt;
        proc[shortest].tat = proc[shortest].ct - proc[shortest].at;
        proc[shortest].wt = proc[shortest].tat - proc[shortest].bt;

        totalwaitingtime += proc[shortest].wt;
        totalturnaroundtime += proc[shortest].tat;

        proc[shortest].executed = 1;
        completed++;
        currenttime = proc[shortest].ct;
    }
    printf("PID\tARRIVALTIME\tSTARTING TIME\tBURST TIME\tCOMPLETION TIME\tWAITING Time\tTURN AROUND TIME\n");
    for (int i = 0; i < n; i++)
    {

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].at, proc[i].at + proc[i].wt, proc[i].bt, proc[i].ct, proc[i].wt, proc[i].tat);
    }
    printf("\nAverage Waiting Time: %.2f", totalwaitingtime / n);
    printf("\nAverage Turn Around Around Time: %.2f", (totalturnaroundtime) / n);
}

int main()
{

    int n;
    printf("Enter Number Of Process: ");
    scanf("%d", &n);

    struct process proc[n];
    printf("Enter Arrival Time And Burst Time for Each Process: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: \n", i + 1);
        proc[i].pid = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &proc[i].at);

        printf("Burst Time: ");
        scanf("%d", &proc[i].bt);

        proc[i].executed = 0;
    }
    findwaitingtime(proc, n);
    return 0;
}