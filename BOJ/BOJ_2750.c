#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int input;
    int *array;
    
    scanf("%d",&input);
    array = (int *)calloc(sizeof(int), input);
    for (int i = 0; i < input; i++)
        scanf("%d", array + i);
    qsort((void *)array, input, sizeof(int), compare);
    for (int i = 0; i < input; i++)
        printf("%d\n",array[i]);
    
    
    return 0;
}

