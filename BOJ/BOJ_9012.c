#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//백준 9012번 괄호
typedef struct
{
    int size;
    int top;
    char *array;
}stack;

void initStack (stack *ps);
void push (stack *ps, char element);
char pop (stack *ps);
int checkVPS (int size, char *array, stack *ps);

int main(void)
{
    stack s;
    int testCases;
    char stringInput[51] = "";
    
    initStack(&s);
    scanf("%d", &testCases);
    
    for (int i = 0; i < testCases; i++)
    {
        s.top = -1;
        scanf("%s",stringInput);
        
        if(checkVPS((int)strlen(stringInput), stringInput, &s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

int checkVPS (int size, char *array, stack *ps)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == '(')
            push(ps, '(');
        else if (array[i] == ')')
        {
            if (pop(ps) == 0) //스택에 괄호가 부족할때
                return 0;
        }
    }
    
    if (ps->top != -1) //스택에 괄호가 남아있을떄
        return 0;
    
    return 1;
}

void initStack (stack *ps)
{
    ps->size = 1;
    ps->top = -1;
    ps->array = (char *)calloc(sizeof(char), ps->size);
}

void push (stack *ps, char element)
{
    if (ps->top == ps->size - 1)
    {
        ps->size *= 2;
        ps->array = (char *)realloc(ps->array, ps->size * sizeof(char));
    }
    ps->array[++ps->top] = element;
}

char pop (stack *ps)
{
    if (ps->top == -1)
    {
        return 0; //스택에 괄호가 부족할때를 처리하기 위한 리턴값
    }
    return ps->array[ps->top--];
}
