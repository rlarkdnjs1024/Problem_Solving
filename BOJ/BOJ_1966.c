#include <stdio.h>
#include <stdlib.h>

//백준 1966 프린터큐

typedef struct
{
    int importance;
    int docNum;
}docInfo;

typedef struct
{
    int front;
    int rear;
    int size;
    docInfo *queue;
    
}queue;

int getMaxImportance (queue *q); //큐의 문서들중 가장 높은 중요도를 구하느 함수
void initQueue (queue *q);
void addToRear ( docInfo element, queue *q); //맨 앞에 있던 구조체를 큐의 가장 마지막에 넣는 함수
void dequeue (queue *q);
int getPrintOrder (int N, int target, queue *q);

int main(void)
{
    int testCases;
    int N;
    int target;
    queue q;
    initQueue(&q);
    
    scanf("%d", &testCases);
    
    for (int i = 0; i < testCases; i++)
    {
        scanf("%d %d", &N, &target);
        q.front = -1;
        q.rear = N - 1;
        
        for (int j = 0; j < N; j++)
        {
            scanf("%d",&(q.queue[j].importance));
            q.queue[j].docNum = j;
            //printf("%d번 구조체 문서번호: %d 중요도: %d\n",j,q.queue[j].docNum, q.queue[j].importance);
        }
        printf("%d\n",getPrintOrder(N, target, &q));
    }
    free(q.queue);
    return 0;
}

int getPrintOrder (int N, int target, queue *q)
{

    int order = 0;
    while(1)
    {
        int max = getMaxImportance(q);
        //printf("max : %d\n",max);
        
        if (q->queue[q->front + 1].importance != max) //맨 앞에 있는게 중요도가 가장 큰 문서가 아닐때
        {
            addToRear(q->queue[q->front+1], q); //맨 뒤로 보낸다.
        }
        
        else //증요도가 가장 클 때
        {
            if (q->queue[q->front+1].docNum == target) //원하는 문서일때
                return ++order;
            
            else //원하는 문서가 아닐때
            {
                dequeue(q);
                order++;
            }
        }
    }
}

void addToRear ( docInfo element, queue *q)
{
    if (q->rear == q->size - 1) //만약 큐가 가득 차있다면
    {
        q->size *= 2;
        q->queue = (docInfo *)realloc(q->queue,sizeof(docInfo) * (q->size));
    }
    q->front++;
    q->queue[++q->rear] = element;
}

void dequeue (queue *q)
{
    q->front++;
}



void initQueue (queue *q)
{
    q->front = -1;
    q->rear= -1;
    q->queue = (docInfo *)calloc(sizeof(docInfo), q->size);
}

int getMaxImportance (queue *q)
{
    int max = 0;
    for ( int i = q->front + 1; i <= q->rear; i++)
    {
        if (q->queue[i].importance > max)
            max = q->queue[i].importance;
    }
    return max;
}
