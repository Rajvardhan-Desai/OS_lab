#include <stdio.h>

int req[] = {98, 183, 37, 122, 14, 124, 65, 67};
int head = 53;
int maxtrack = 199;

int n = sizeof(req) / sizeof(req[0]);

int absDiff(int a, int b)
{
    return (a > b) ? (a - b) : (b - a);
}
void sstf()
{
    int totalMov = 0;
    int visited[n];
    int c = head;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    

    printf("\nOrder of Service : ");
    for (int i = 0; i < n; i++)
    {
        int minDist = maxtrack + 1;
        int minIdx = -1;

        for (int j = 0; j < n; j++)
        {
            if(!visited[j] && absDiff(c,req[j]) < minDist){
                minDist = absDiff(c,req[j]);
                minIdx = j;
            }
        }

        visited[minIdx] = 1;
        totalMov += minDist;

        printf("%d ",req[minIdx]);
        c = req[minIdx];
    }
    printf("\nTotal head movement = %d\n", totalMov); 
    printf("Average seek time = %.2f\n", (float)totalMov / n);
}

void main(){
    sstf();
}