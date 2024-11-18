#include <stdio.h>

#define P 5
#define R 3

int alloc[P][R] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 3},
    {2, 1, 1},
    {0, 0, 2}};

int req[P][R] = {
    {0, 0, 0},
    {2, 0, 2},
    {0, 0, 0},
    {1, 0, 0},
    {0, 0, 2}};

int avail[R] = {0, 0, 0};

int isDeadlocked()
{
    int work[R];
    int finish[P] = {0};

    for (int i = 0; i < R; i++)
    {
        work[i] = avail[i];
    }

    while (1)
    {
        int found = 0;

        for (int i = 0; i < P; i++)
        {
            if (!finish[i])
            {
                int canDo = 1;
                for (int j = 0; j < R; j++)
                {
                    if (req[i][j] > work[j])
                    {
                        canDo = 0;
                        break;
                    }
                }

                if (canDo)
                {
                    for (int j = 0; j < R; j++)
                    {
                        work[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
        {
            break;
        }
    }

    for (int i = 0; i < P; i++)
    {
        if (!finish[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    if (isDeadlocked())
    {
        printf("The system is in a deadlock state.\n");
    }
    else
    {
        printf("No deadlock detected.\n");
    }

    return 0;
}