#include <stdio.h>

int RefStr[] = {7, 1, 0, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
int fC = 3;
int frames[3];

int n = sizeof(RefStr) / sizeof(RefStr[0]);

int isPagePresent(int page)
{
    for (int i = 0; i < fC; i++)
    {
        if (frames[i] == page)
        {
            return i;
        }
    }
    return -1;
}
void lru()
{

    for (int i = 0; i < fC; i++)
    {
        frames[i] = -1;
    }

    int lastUsed[fC];

    for (int i = 0; i < fC; i++) {
        lastUsed[i] = -1; 
    }
    int pfcnt = 0;

    printf("LRU\n");
    printf("Refernce String\t Frames\n");

    for (int i = 0; i < n; i++)
    {
        int page = RefStr[i];
        int pos = isPagePresent(page);

        if (pos == -1)
        {
            int lruIdx = 0;

            for (int j = 0; j < fC; j++)
            {
                if (frames[j] == -1 || lastUsed[j] < lastUsed[lruIdx])
                {
                    lruIdx = j;
                }
            }
            frames[lruIdx] = page;
            lastUsed[lruIdx] = i;
            pfcnt++;
        }
        else
        {
            lastUsed[pos] = i;
        }

   

        printf("%d\t\t", RefStr[i]);

        for (int j = 0; j < fC; j++)
        {
            if (frames[j] == -1)
            {
                printf("-\t");
            }
            else
            {
                printf("%d\t", frames[j]);
            }
        }
        printf("\n");

       
    }
     printf("Total Page Faults : %d", pfcnt);
}
int main()
{
    lru();
}