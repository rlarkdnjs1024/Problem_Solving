#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10001

typedef struct
{
    int front;
    int rear;
    int size;
    int *array;
    
}deque;

void initDeque (deque *p)
{
    p->front = 0;
    p->rear = 0;
    p->size = 0;
    p->array = (int *)calloc(sizeof(int), MAX_QUEUE_SIZE);
}

void pushFront (deque *p, int element)
{
    p->array[p->front] = element;
    p->front--;
    if ( p->front < 0)
        p->front += MAX_QUEUE_SIZE;
    p->size++;
}

void pushBack (deque *p, int element)
{
    p->rear = (p->rear + 1) % MAX_QUEUE_SIZE;
    p->array[p->rear] = element; //rear를 하나 증기시키고, 그 자리에 원소를 대입한다.
    p->size++;
}
  
int empty (deque *p)
{
    return (p->size == 0);
}

int popFront (deque *p)
{
    if (empty(p))
        return -1;
    p->front = (p->front + 1) % MAX_QUEUE_SIZE;
    p->size--;
    return p->array[p->front];
    
}

int popBack (deque *p)
{
    if (empty(p))
        return -1;
    int temp = p->array[p->rear];
    p->rear--;
    if (p ->rear < 0)
        p->rear += MAX_QUEUE_SIZE;
    p->size--;
    return temp;
}

int size (deque *p)
{
    return p->size;
}

int front (deque *p)
{
    int temp = (p->front + 1) % MAX_QUEUE_SIZE;
    
    if (empty(p))
        return -1;
    
    else
        return p->array[temp];
}

int back (deque *p)
{
    if (empty(p))
        return -1;
    
    else
        return p->array[p->rear];
}

int getNumber (char *str)
{
    int i = 0;
    int result = 0;
    while (str[i] != 0)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result *= 10;
            result = result + (str[i] - '0');
        }
        i++;
    }
    return result;
}

void printDeque (deque *p)
{
    int i = p->front;
    
    if (empty(p) == 1)
        return;
    
    printf("front :%d rear :%d\n",p->front, p->rear);
    do
    {
        i = (i + 1) % MAX_QUEUE_SIZE;
        printf("%d ",p->array[i]);
        
    } while ( i != p->rear);
    printf("\n");
}

int main(void)
{
    int input;
    char command[20];
    deque a;
    initDeque(&a);
    
    scanf("%d",&input);
    getchar();
    
    for (int i = 0; i < input; i++)
    {
        fgets(command, 20, stdin);
        command[strlen(command)-1] = 0;
        
        if (strcmp(command, "pop_front") == 0)
        {
            printf("%d\n",popFront(&a));
        }
        
        else if (strcmp(command, "pop_back") == 0)
        {
            printf("%d\n",popBack(&a));
        }
        
        else if (strcmp(command, "size") == 0)
        {
            printf("%d\n",size(&a));
        }
        
        else if (strcmp(command, "empty") == 0)
        {
            printf("%d\n",empty(&a));
        }
        
        else if (strcmp(command, "front") == 0)
        {
            printf("%d\n",front(&a));
        }
        
        else if (strcmp(command, "back") == 0)
        {
            printf("%d\n",back(&a));
        }
        
        else
        {
            if (strncmp(command, "push_front", 10) == 0)
            {
                int element = getNumber(command);
                pushFront(&a, element);
            }
            
            else
            {
                int element = getNumber(command);
                pushBack(&a, element);
            }
        }
        //printDeque(&a);
    }
    
    return 0;
}

  

