//백준 11047번

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int input;
    int *coinTypeArray;
    int target;
    int count = 0;
    
    scanf("%d %d",&input, &target);
    coinTypeArray = (int *)calloc(sizeof(int), input);
    for (int i = 0; i < input; i++)
        scanf("%d",coinTypeArray + i);
    
    for (int i = input - 1; i >= 0; i--)
    {
        int quotient = target / coinTypeArray[i];
        count += quotient;
        target -= quotient * coinTypeArray[i];
        
    }
    printf("%d",count);
    
    return 0;
}
