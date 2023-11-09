#include <stdio.h>
#include <stdlib.h>

int max (int a, int b)
;

int main(void)
{
    int level;
    int *point;
    int *DP;
    
    scanf("%d",&level);
    point = (int *)calloc(sizeof(int), level + 1);
    DP = (int *)calloc(sizeof(int), level + 1);
    for (int i = 1; i <= level; i++)
        scanf("%d", point + i);
    DP[1] = point[1];
    DP[2] = point[1] + point[2];
    
    for ( int i = 3; i <= level; i++)
    {
        DP[i] = max(DP[i-3] + point[i-1] + point[i], DP[i-2] + point[i]);
    }
    
    printf("%d\n",DP[level]);
    
    return 0;
}

int max (int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

