#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b);
//백준 11399번 이용시간이 짧은 사람부터 기계를 이용해야 전체 시간이 줄어든다.
int main(void)
{
    int input;
    int total = 0;
    int userWait = 0;
    int *users;
    
    scanf("%d",&input);
    users = (int *)calloc(sizeof(int), input);
    for (int i = 0; i < input; i++)
        scanf("%d",users + i);
    qsort((void *)users, input, sizeof(int), compare);
    for (int i = 0; i < input; i++)
    {
        userWait = 0;
        for (int j = 0; j <= i; j++)
            userWait += users[j];
        total += userWait;
    }
    printf("%d",total);
    
    return 0;
}

int compare (const void *a, const void *b)
{
    return (*(int *)a > *(int *)b);
}

