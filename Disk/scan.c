#include <stdio.h>

int req[] = {98, 183, 37, 122, 14, 124, 65, 67};
int head = 53;
int maxtrack = 199;

int n = sizeof(req) / sizeof(req[0]);

int absDiff(int a, int b)
{
    return (a > b) ? (a - b) : (b - a);
}
void scan()
{
    int totalMov = 0;
    int sortedReq[n + 1];
    int idx = 0;

    for (int i = 0; i < n; i++)
        sortedReq[idx++] = req[i];

    sortedReq[idx++] = head;
   

    for (int i = 0; i < idx - 1; i++)
    {
        for (int j = 0; j < idx - i - 1; j++)
        {
            if (sortedReq[j] > sortedReq[j + 1])
            {
                int temp = sortedReq[j];
                sortedReq[j] = sortedReq[j + 1];
                sortedReq[j + 1] = temp;
            }
        }
    }

    int hIdx;

    for (int i = 0; i < idx; i++)
    {
        if (sortedReq[i] == head)
        {
            hIdx = i;
            break;
        }
    }

    printf("\nOrder of Service : ");
    for (int i = hIdx; i < idx; i++)
    {
        printf("%d ",sortedReq[i]);
        if (i != hIdx)
        {
           totalMov += absDiff(sortedReq[i],sortedReq[i-1]);

        }
    }

    for (int i = hIdx - 1; i >= 0; i--)
    {
        printf("%d ",sortedReq[i]);
        totalMov += absDiff(sortedReq[i],sortedReq[i+1]);
    }
    
    printf("\nTotal head movement = %d\n", totalMov);
    printf("Average seek time = %.2f\n", (float)totalMov / n);
}

void main()
{
    scan();
}