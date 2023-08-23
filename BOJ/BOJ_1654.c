//가장 많은 랜선을 만들 수 있는 건 원하는 랜선의 길이가 1일때이고, 가장 적은 랜섬을 만들 수 있는 건 원하는 랜선의 길이가 입력된 랜선의 길이들 중 최댓값일때이다. 또한 원하는 랜선의 길이가 길어질수록 만들 수 있는 랜선의 길이는 점점 적어짐을 이용해서, 매개변수 탐색을 이용한다.

//백준 1654 랜선자르기
#include <stdio.h>
#include <stdlib.h>

int getMax (int *array, int size);
int getMaxLength (int *array, int arraySize, int requiredQuantity);

int main(void)
{
    int input;
    int requiredQuantity;
    int *array;
  
    scanf("%d %d",&input,&requiredQuantity);
    array = (int *)calloc(sizeof(int), input);
    for ( int i = 0; i < input; i++)
        scanf("%d",array + i);
     
    printf("%d",getMaxLength(array, input, requiredQuantity));
    
    return 0;
}

int getMax (int *array, int arraySize)
{
    int max = 1;
    for ( int i = 0; i < arraySize; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

int getMaxLength (int *array, int arraySize, int requiredQuantity)
{
    long long low = 1;
    int possibleQuantity = 0;
    long long high = getMax(array, arraySize);
    long long mid;
    int result = 0;
   
    while (low <= high)
    {
        mid = (low + high) / 2;
        for ( int i = 0; i < arraySize; i++) //mid를 길이로 할 때 만들 수 있는 랜선의 개수
            possibleQuantity += array[i] / mid;
       
        if ( possibleQuantity < requiredQuantity)
            high = mid - 1;
        else
        {
            low = mid + 1;
            result = (int)mid;
        }
        possibleQuantity = 0;
    }
    return result;
}
