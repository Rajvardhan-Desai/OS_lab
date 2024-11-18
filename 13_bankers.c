#include <stdio.h>

#define PRO_N 5
#define RES_N 3

int need[PRO_N][RES_N];
int alloc[PRO_N][RES_N] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
int max[PRO_N][RES_N] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
int avail[RES_N] = {3, 3, 2};

void cal_need()
{
    for (int i = 0; i < PRO_N; i++)
        for (int j = 0; j < RES_N; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

int isSafe()
{
    int finish[PRO_N] = {0};
    int safeSeq[PRO_N];
    int idx = 0;
    int cnt = 0;
    int work[RES_N];

    for (int i = 0; i < RES_N; i++)
        work[i] = avail[i];

    while (cnt < PRO_N)
    {
        int found = 0;

        for (int i = 0; i < PRO_N; i++)
        {

            if (!finish[i])
            {
                int canFinish = 1;

                for (int j = 0; j < RES_N; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canFinish = 0;
                        break;
                    }
                }

                if (canFinish)
                {
                    for (int j = 0; j < RES_N; j++)
                        work[j] += alloc[i][j];

                    safeSeq[idx++] = i;
                    finish[i] = 1;
                    found = 1;
                    cnt++;
                }
            }
        }
        if (!found)
        {
            printf("The system is not in a safe state\n");
            return 0;
        }
    }

    printf("Safe Sequence : ");

    for (int i = 0; i < PRO_N; i++)
    {
        printf("P%d", safeSeq[i]);
        if (i != PRO_N - 1)
            printf(" -> ");
    }
    printf("\n");

    return 1;
}

int main()
{
    cal_need();
    isSafe();
    return 0;
}