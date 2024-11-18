#include <stdio.h>

void find_wt_tt(int bt[], int wt[], int tt[], int n)
{
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (int i = 0; i < n; i++)
        tt[i] = bt[i] + wt[i];
    
}

void findAvgWt(int bt[], int n)
{
    int tt[n], wt[n], totalTt = 0, totalWt = 0;

    find_wt_tt(bt, wt, tt, n);

    printf("P id |\t burst time |\t wating time |\t turn around time\n");
    for (int i = 0; i < n; i++)
    {
        totalTt += tt[i];
        totalWt += wt[i];
        printf(" %d   \t    %d       \t    %d        \t       %d\n", (i + 1), bt[i], wt[i], tt[i]);
    }

    printf("\n Average Wating Time: %.2f", (float)totalWt / (float)n);
    printf("\n Average Turnaround Time: %.2f", (float)totalTt /(float) n);
}
int main()
{
    int n;

    printf("Enter No. of process: ");
    scanf("%d", &n);

    int bt[n];
    int wt[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Process %d burst time: ", (i + 1));
        scanf("%d", &bt[i]);
    }

    findAvgWt(bt, n);
}