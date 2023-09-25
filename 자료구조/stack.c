#include <stdio.h>
#include <stdlib.h>

typedef int dataType;

typedef struct
{
    int top;
    int size; //스택 속 원소의 개수가 아닌 배열의 최대 길이를 담는 변수.
    dataType *array;
    
}stack;

void initStack (stack *p)
{
    p->top = -1;
    p->size = 1;
    p->array = (dataType *)calloc(sizeof(dataType), p->size);
    if (p->array == NULL)
        exit(1);
}

void push (stack *p, dataType element)
{
    if (p->size - 1 == p->top)
    {
        p->array = (dataType *)realloc(p->array, sizeof(dataType) * p->size);
        if (p->array == NULL)
            exit(1);
    }
    p->array[++p->top] = element;
    p->size++;
}

dataType pop (stack *p)
{
    return p->array[p->top--];
}

void printStack (stack *p)
{
    for (int i = 0; i <= p->top; i++)
    {
        printf("%d",p->array[i]);
        if ( i != p->top)
            printf(" -> ");
    }
    printf("\n");
}

int main(void)
{
    stack a;
    initStack(&a);
    
    push(&a, 1);
    printStack(&a);
    
    push(&a, 2);
    printStack(&a);
    
    pop(&a);
    printStack(&a);
    
    push(&a, 4);
    printStack(&a);
    
    
    return 0;
}

