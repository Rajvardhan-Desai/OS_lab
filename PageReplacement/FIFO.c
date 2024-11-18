#include <stdio.h>

int RefStr[] = {7, 1, 0, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
int fC = 3;
int frames[fC];

int n = sizeof(RefStr) / sizeof(RefStr[0]);

int isPagePresent(int page)
{
    for (int i = 0; i < fC; i++)
    {
        if (frames[i] == page)
        {
            return 1;
        }
    }
    return 0;
}
void fifo()
{

    for (int i = 0; i < fC; i++)
    {
        frames[i] = -1;
    }

    int pfcnt = 0;
    int pointer = 0;
    printf("FIFO\n");
    printf("Refernce String\t Frames\n");

    for (int i = 0; i < n; i++)
    {
        if (!isPagePresent(RefStr[i]))
        {
            frames[pointer] = RefStr[i];
            pointer = (pointer + 1) % fC;
            pfcnt++;

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
    }

    printf("Total Page Faults : %d", pfcnt);
}

int main()
{
    fifo();
}