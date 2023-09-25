#include <stdio.h>
#include <stdlib.h>


//큐를 이용한 풀이

typedef struct
{
    int front;
    int rear;
    int arraySize;
    int *array;
}queue;

void initQueue (queue *p, int N)
{
    p->front = 0;
    p->rear = 0;
    p->arraySize = N;
    p->array = (int *)calloc(sizeof(int), p->arraySize);
    if (p->array == NULL)
        exit(1);
}

void enqueue (queue *p, int element)
{
    p->rear = (p->rear + 1) % p->arraySize;
    p->array[p->rear] = element;
}

int dequeue (queue *p)
{
    p->front = (p->front + 1) % p->arraySize;
    return p->array[p->front];

}

int getKthPerson (queue *p, int K)
{
    for (int i = 0; i < K-1; i++)
    {
        int temp = dequeue(p);
        enqueue(p, temp);
    }
    return dequeue(p);
}

void printArray (int *array, int size)
{
    printf("<");
    for (int i = 0; i < size; i++)
    {
        printf("%d",array[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf(">\n");
}

void printQueue (queue *q)
{
    int i = q->front;
    do
    {
        i = (i + 1) % q->arraySize;
        printf("%d ", q->array[i]);
        if ( i == q->rear)
            break;
    }
    while (1);
    printf("\n");
    
}

int main(void)
{
    queue a;
    int N, K;
    int *result;
    scanf("%d %d",&N, &K);
    
    result = (int *)calloc(sizeof(int), N);
    
    initQueue(&a, N + 1);
    
    for (int i = 0; i < N; i++)
        enqueue(&a, i+1);
    
    for (int i = 0; i < N; i++)
        result[i] = getKthPerson(&a, K);
    printArray(result, N);

    return 0;
}



