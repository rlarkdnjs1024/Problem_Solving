#include <stdio.h>
#include <stdlib.h>

#define target_01 11
#define target_02 7
//이진탐색 상한선, 하한선 알고리즘 연습

int lowerBound (int target, int *array, int size);
int upperBound (int target, int *array, int size);

int main(void)
{
    int array[10] = {1, 2, 2, 3, 4, 5, 5, 6, 10, 10};
    int l = lowerBound(target_01, array, 10);
    int u = upperBound(target_02, array, 10);
    
    printf("%d %d", l, u);
    return 0;
}

int lowerBound (int target, int *array, int size)
{
    int mid = 0;
    int left = 0;
    int right = size;
    
    while (left < right)
    {
        mid = (left + right) / 2;
        printf("lowerBound 구하기 :%d %d %d\n", left, mid, right);
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
        printf("upperBound 구하기 :%d %d %d\n", left, mid, right);
        if (array[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}


