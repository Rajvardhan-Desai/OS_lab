#include <stdio.h>
#define MAX 9999

void sjf_preempt(int n, int at[], int bt[])
{
    int rt[n], ct[n], tt[n], wt[n];
    int time = 0, minbt, count = 0, c_pro;
    float total_tt = 0.0, total_wt = 0.0;

    for (int i = 0; i < n; i++)
    {
        rt[i] = bt[i];
    }

    while (count < n)
    {
        minbt = MAX;
        c_pro = -1;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0 && rt[i] < minbt)
            {
                minbt = rt[i];
                c_pro = i;
            }
        }

        if (c_pro == -1)
        {
            time++;
            continue;
        }

        rt[c_pro]--;
        time++;

        if (rt[c_pro] == 0)
        {
            ct[c_pro] = time;
            tt[c_pro] = ct[c_pro] - at[c_pro];
            wt[c_pro] = tt[c_pro] - bt[c_pro];
            total_tt += tt[c_pro];
            total_wt += wt[c_pro];
            count++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tt[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tt / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    sjf_preempt(n, at, bt);

    return 0;
}