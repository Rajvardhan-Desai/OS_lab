#include <stdio.h>

void priority_non_preemptive(int n, int at[], int bt[], int priority[])
{
    int wt[n], tt[n], completed[n], ct[n];
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++)
        completed[i] = 0;

    int time = 0, count = 0;

    while (count < n)
    {
        int c_pro = -1;
        int min_pri = 9999;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && priority[i] < min_pri && !completed[i])
            {
                min_pri = priority[i];
                c_pro = i;
            }
        }

        if (c_pro == -1)
        {
            time++;
            continue;
        }

        time += bt[c_pro];
        ct[c_pro] += time;
        tt[c_pro] = ct[c_pro] - at[c_pro];
        wt[c_pro] = tt[c_pro] - bt[c_pro];
        total_tat += tt[c_pro];
        total_wt += wt[c_pro];
        completed[c_pro] = 1;
        count++;
    }

    printf("P ID |\t AT  |\t BT |\t Pri |\t TAT |\t WT\n");

    for (int i = 0; i < n; i++)
    {
        printf("  %d | \t %d |\t %d |\t %d  |\t  %d |\t %d\n", (i + 1), at[i], bt[i], priority[i], tt[i], wt[i]);
    }

    printf("Avg. tt : %.2f", total_tat/n);
    printf("\nAvg. wt : %.2f", total_wt/n);
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pri[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time, and Priority (lower value = higher priority) for Process %d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pri[i]);
    }

    priority_non_preemptive(n, at, bt, pri);

    return 0;
}