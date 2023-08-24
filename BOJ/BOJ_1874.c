//백준 1874번

#include <stdio.h>
#include <stdlib.h>

//백준 1874 스택수열
typedef struct
{
    int top;
    int size;
    int *stackArray;
    
}stack;

typedef struct
{
    int index;
    int size;
    char *outputArray;
}output;

void initialStack (stack *ps);
void push(int element, stack *ps);
void initialOutput (output *po);
int pop(stack *ps);
void append (char element, output *po);

int main(void)
{
    stack a;
    output o;
    initialStack(&a);
    initialOutput(&o);
    int max = 0;
    int input;
    int temp;
    scanf("%d",&input);
    for ( int i = 0; i < input; i++)
    {
        scanf("%d",&temp);
        if (temp > max) //max보다 큰 값이 새로 들어올때만 push를 한다.
        {
            for (int j = max + 1; j <= temp; j++)
            {
                push(j, &a);
                append('+', &o);
            }
            max = temp;
        }
        if (pop(&a) != temp)
        {
            printf("NO\n");
            return 0;
        }
        append('-', &o);
    }
    
    for ( int i = 0; i <= o.index; i++)
        printf("%c\n",o.outputArray[i]);
    
    free(a.stackArray); free(o.outputArray);
    return 0;
}

void initialStack (stack *ps)
{
    ps->top = -1;
    ps->size = 1;
    ps->stackArray = (int *)calloc(sizeof(int), ps->size);
}

void initialOutput (output *po)
{
    po->size = 1;
    po->index = -1;
    po->outputArray = (char *)calloc(sizeof(char), po->size);
}

void push(int element, stack *ps)
{
    if (ps->top == ps->size - 1)
    {
        ps->size *= 2;
        ps->stackArray = (int *)realloc(ps->stackArray, sizeof(int) * ps->size);
    }
    ps->stackArray[++ps->top] = element; //먼저 하나 증가시킨다
}

void append (char element, output *po)
{
    if (po->index == po->size - 1)
    {
        po->size *= 2;
        po->outputArray = (char *)realloc(po->outputArray, sizeof(char) * po->size);
    }
    po->outputArray[++po->index] = element;
    
}

int pop(stack *ps)
{
    if ( ps->top == -1)
    {
        printf("stack is empty\n");
        exit(-1);
    }
    return ps->stackArray[ps->top--]; //리턴을 한 후에 하나 감소시킨다.
}
