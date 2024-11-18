#include <stdio.h>

int RefStr[] = {7, 1, 0, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
int fc = 3;
int frames[3];
int n = sizeof(RefStr) / sizeof(RefStr[0]);

int isPresent(int page)
{
    for (int i = 0; i < fc; i++)
    {
        if (page == frames[i])
        {
            return 1;
        }
    }
    return 0;
}

int findoptimal(int cIdx)
{
    int far = -1;
    int replaceIdx = -1;

    for (int i = 0; i < fc; i++)
    {
        int j;
        for (j = cIdx + 1; j < n; j++)
        {
            if (frames[i] == RefStr[j])
            {
                if (j > far)
                {
                    far = j;
                    replaceIdx = i;
                }
                break;
            }
        }
        if (j == n)
        {
            return i;
        }
    }

    return replaceIdx == -1 ? 0 : replaceIdx;
}

void optimal(){
    
    for (int i = 0; i < fc; i++)
    {
        frames[i] = -1;
    }

    int pfCnt = 0;

    for (int i = 0; i < n; i++)
    {
        int page = RefStr[i];
        
        if (!isPresent(page))
        {
            int repIdx = findoptimal(i);
            frames[repIdx] = page;
            pfCnt++;
        }

        printf("%d\t\t\t", page);
        for (int j = 0; j < fc; j++) {
            if (frames[j] == -1) {
                printf("-\t");
            } else {
                printf("%d\t", frames[j]);
            }
        }
        printf("\n");
        
        
    }
    
    printf("Total Page Faults: %d\n", pfCnt);
}

int main() {
    optimal(); // Run Optimal Page Replacement Algorithm
    return 0;
}