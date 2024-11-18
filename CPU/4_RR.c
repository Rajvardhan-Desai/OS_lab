#include <stdio.h>

void roundRobin(int n, int at[], int bt[], int tq)
{
    int wt[n], tt[n], ct[n], rt[n];
    int time = 0, completed = 0;
    float total_tt = 0, total_wt = 0;

    for (int i = 0; i < n; i++)
    {
        rt[i] = bt[i];
    }

    while (completed < n)
    {
        int exec = 0;

        for (int i = 0; i < n; i++)
        {
            if (rt[i] > 0 && at[i] <= time)
            {
                exec = 1;
                if (rt[i] <= tq)
                {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    tt[i] = ct[i] - at[i];
                    wt[i] = tt[i] - bt[i];
                    total_tt += tt[i];
                    total_wt += wt[i];
                    completed++;
                    
                }
                else
                {
                    time += tq;
                    rt[i] -= tq;
                }
            }
        }
        if (!exec)
            time++;
    }

     printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tt[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tt / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
}

int main() {
    int n, time_quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    roundRobin(n, at, bt, time_quantum);

    return 0;
}