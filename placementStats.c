#include <stdio.h>

int bSize[] = {100, 500, 200, 300, 600};
int pSize[] = {212, 417, 112, 426};

int Bn = sizeof(bSize) / sizeof(bSize[0]);
int Pn = sizeof(pSize) / sizeof(pSize[0]);

void FirstFit()
{
    int alloc[Pn];
    int tbSize[Bn];

    for (int i = 0; i < Pn; i++)
        alloc[i] = -1;

    for (int i = 0; i < Bn; i++)
        tbSize[i] = bSize[i];

    for (int i = 0; i < Pn; i++)
    {
        for (int j = 0; j < Bn; j++)
        {
            if (tbSize[j] >= pSize[i])
            {
                alloc[i] = j;
                tbSize[j] -= pSize[i];
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    for (int i = 0; i < Pn; i++)
    {
        if (alloc[i] != -1)
            printf("Process %d (%d) -> Block %d (%d)\n", i + 1, pSize[i], alloc[i] + 1, bSize[alloc[i]]);
        else
            printf("Process %d (%d) -> Not Allocated\n", i + 1, pSize[i]);
    }
}

void BestFit()
{
    int alloc[Pn];
    int tbSize[Bn];

    for (int i = 0; i < Pn; i++)
        alloc[i] = -1;

    for (int i = 0; i < Bn; i++)
        tbSize[i] = bSize[i];

    for (int i = 0; i < Pn; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < Bn; j++)
        {
            if (tbSize[j] >= pSize[i])
            {
                if (bestIdx == -1 || tbSize[j] < tbSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1)
        {
            alloc[i] = bestIdx;
            tbSize[bestIdx] -= pSize[i];
        }
    }

    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < Pn; i++)
    {
        if (alloc[i] != -1)
            printf("Process %d (%d) -> Block %d (%d)\n", i + 1, pSize[i], alloc[i] + 1, bSize[alloc[i]]);
        else
            printf("Process %d (%d) -> Not Allocated\n", i + 1, pSize[i]);
    }
}

void worstFit()
{
    int alloc[Pn];
    int tbSize[Bn];

    for (int i = 0; i < Pn; i++)
        alloc[i] = -1;

    for (int i = 0; i < Bn; i++)
        tbSize[i] = bSize[i];

    for (int i = 0; i < Pn; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < Bn; j++)
        {
            if (tbSize[j] >= pSize[i])
            {
                if (worstIdx == -1 || tbSize[j] > tbSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1)
        {
            alloc[i] = worstIdx;
            tbSize[worstIdx] -= pSize[i];
        }
    }

    printf("\nWorst Fit Allocation:\n");
    for (int i = 0; i < Pn; i++)
    {
        if (alloc[i] != -1)
            printf("Process %d (%d) -> Block %d (%d)\n", i + 1, pSize[i], alloc[i] + 1, bSize[alloc[i]]);
        else
            printf("Process %d (%d) -> Not Allocated\n", i + 1, pSize[i]);
    }
}

void NextFit()
{
    int alloc[Pn];
    int tbSize[Bn];
    int lastAlloc = 0;

    for (int i = 0; i < Pn; i++)
        alloc[i] = -1;

    for (int i = 0; i < Bn; i++)
        tbSize[i] = bSize[i];

    for (int i = 0; i < Pn; i++)
    {
        int j = lastAlloc;
        do
        {
            if (tbSize[j] >= pSize[i])
            {
                alloc[i] = j;
                tbSize[j] -= pSize[i];
                lastAlloc = j;
                break;
            }
            j = (j+1) % Bn;
        } while (j != lastAlloc);
        
    }

    printf("\nNext Fit Allocation:\n");
    for (int i = 0; i < Pn; i++)
    {
        if (alloc[i] != -1)
            printf("Process %d (%d) -> Block %d (%d)\n", i + 1, pSize[i], alloc[i] + 1, bSize[alloc[i]]);
        else
            printf("Process %d (%d) -> Not Allocated\n", i + 1, pSize[i]);
    }
}

int main()
{
    FirstFit();
    BestFit();
    worstFit();
    NextFit();
    return 0;
}