#include <stdio.h>
#include <stdlib.h>

//백준 18110
int roundOff (double num);
int compare (const void *a, const void *b);
int getDifficulty (int n, int *scoreArray);

int main(void)
{
    int input;
    int *scoreArray;
    scanf("%d",&input);
    scoreArray = (int *)calloc(sizeof(int), input);
    
    for ( int i = 0; i < input; i++)
        scanf("%d",scoreArray + i);
    qsort((void *)scoreArray, input, sizeof(int), compare);
    printf("%d",getDifficulty(input, scoreArray));
    return 0;
}

int roundOff (double num)
{
    int integerArea;
    double decimalArea;
    if ( num >= 0)
    {
        integerArea = (int)num;
        decimalArea = num - integerArea;
    }
    else
    {
        integerArea = (int)num - 1;
        decimalArea = num - integerArea;;
    }
    
    if (decimalArea < 0.5)
        return integerArea;
    else
        return integerArea + 1;
}

int getDifficulty (int n, int *scoreArray)
{
    int difficulty = 0;
    int exclude = roundOff(n * 0.15);
    if (n > 0)
    {
        for (int i = exclude; i <= n - exclude - 1; i++)
        {
            difficulty += scoreArray[i];
        }
        exclude *= 2;
        difficulty = roundOff((double)difficulty/(n - exclude));
        return difficulty;
    }
    
    return 0;
}
    
int compare (const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if ( *(int *)a < *(int *)b)
        return -1;
    else
        return 0;
}
