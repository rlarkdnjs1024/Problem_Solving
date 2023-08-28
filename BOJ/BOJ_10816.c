#include <stdio.h>
#include <stdlib.h>

//백준 10816번 숫자카드2
int compare (const void *a, const void *b);
int getQuantity (int target, int *array, int size);
int lowerBound (int target, int *array, int size);
int upperBound (int target, int *array, int size);

int main(void)
{
    int input;
    int targetQuantity;
    int target;
    int *array;
    
    scanf("%d",&input);
    array = (int *)calloc(sizeof(int), input);
    for (int i = 0; i < input; i++)
        scanf("%d",array + i);
    qsort((void *)array, input, sizeof(int), compare);
    
    scanf("%d",&targetQuantity);
    for (int i = 0; i < targetQuantity; i++)
    {
        scanf("%d",&target);
        printf("%d ",getQuantity(target, array, input));
    }
    
    return 0;
}
int compare (const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    else
        return 0;
}

int getQuantity (int target, int *array, int size)
{
    return upperBound(target, array, size) - lowerBound(target, array, size);
}

int lowerBound (int target, int *array, int size)
{
    int mid = 0;
    int left = 0;
    int right = size;
    
    while (left < right)
    {
        mid = (left + right) / 2;
        if (array[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
    return right;
}

int upperBound (int target, int *array, int size)
{
    int mid = 0;
    int left = 0;
    int right = size;
    
    while (left < right)
    {
        mid = (left + right) / 2;
        if (array[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
