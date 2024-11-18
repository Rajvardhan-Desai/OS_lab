#include <stdio.h>

#define MAX 9999

void priority_premptive(int n, int at[], int bt[], int priority[])
{
    int time = 0, remaing = n;
    int rt[n], ct[n], tat[n], wt[n], tmpPri[n];

    float total_tt = 0, total_wt = 0;

    for (int i = 0; i < n; i++)
    {
        rt[i] = bt[i];
        tmpPri[i] = priority[i];
    }

    while (remaing > 0)
    {
        int min_pri = MAX;
        int curr_process = -1;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && tmpPri[i] < min_pri && rt[i] > 0)
            {
                min_pri = tmpPri[i];
                curr_process = i;
            }
        }

        if (curr_process == -1)
        {
            time++;
            continue;
        }

        rt[curr_process]--;
        time++;

        if (rt[curr_process] == 0)
        {
            ct[curr_process] = time;
            tat[curr_process] = ct[curr_process] - at[curr_process];
            wt[curr_process] = tat[curr_process] - bt[curr_process];
            total_tt += tat[curr_process];
            total_wt += wt[curr_process];
            tmpPri[curr_process] = MAX;
            remaing--;
        }
    }

    printf("\nProcess\tAT\tBT\tPri\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], priority[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tt / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
}

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pri[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time, and Priority (lower value = higher priority) for Process %d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pri[i]);
    }

    priority_premptive(n, at, bt, pri);

    return 0;
}