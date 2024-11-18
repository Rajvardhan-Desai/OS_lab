#include <stdio.h>

int req[] = {98, 183, 37, 122, 14, 124, 65, 67};
int head = 53;
int maxtrack = 199;

int n = sizeof(req) / sizeof(req[0]);

int absDiff(int a, int b)
{
    return (a > b) ? (a - b) : (b - a);
}
void fcfs()
{
    int totalMov = 0;
    int c = head;

    printf("\nOrder of Service : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",req[i]);
        totalMov += absDiff(c,req[i]);
        c = req[i];
    }
    printf("\nTotal head movement = %d\n", totalMov); 
    printf("Average seek time = %.2f\n", (float)totalMov / n);
}

void main(){
    fcfs();
}