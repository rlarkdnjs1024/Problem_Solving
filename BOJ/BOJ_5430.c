#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void textToArray (char *text, char *array)
{
    int cursor = 0;
    int number = 0;
    int index = 0;
    
    while ( text[cursor] != 0 )
    {
        if (isdigit(text[cursor])) //커서의 문자가 숫자이면
            number = number * 10 + (text[cursor] - '0');
        else
        {
            if (number != 0)
            {
                array[index] = number;
                index++;
            }
            number = 0;
        }
        cursor++;

    }
}
                
void printArray ( char *array, int size, bool isFlipped, int front, int rear)
{
    if (size < 0)
    {
        printf("error\n");
        return;
    }
    
    printf("[");
    if (isFlipped == false)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d",array[i]);
            if ( i != rear )
                printf(",");
        }
    }
    
    else
    {
        for (int i = rear; i >= front; i--)
        {
            printf("%d",array[i]);
            if ( i != front )
                printf(",");
        }
    }
    printf("]\n");
}

void processCommand (char *command, char *array, int size)
{
    bool isFlipped = false;
    int cursor = 0;
    int front = 0;
    int rear = size - 1;
    
    
    while (command[cursor] != 0)
    {
        if (command[cursor] == 'R')
            isFlipped = !isFlipped;
            
        else //명령어가 D이면.
        {
            if (isFlipped == false) //뒤집히지 않은 상태라면
                front++;
            else                    //뒤집힌 상태라면
                rear--;
            size--;
        }
        cursor++;
    }
    printArray(array, size, isFlipped, front, rear);
    
}

int main(void)
{
    int testCases;
    char *command = (char *)calloc(sizeof(char), 100001); //명령어를 저장할 배열
    char *arrayText = (char *)calloc(sizeof(char), 400002);
    char *array = (char *)calloc(sizeof(char), 100000);
    int size;
    
    scanf("%d",&testCases);
    for (int i = 0; i < testCases; i++)
    {
        scanf("%s",command);
        scanf("%d",&size);
        scanf("%s",arrayText);
        
        textToArray(arrayText, array);
        
        if ( 1 == 0) //디버깅용
        {
            for (int j = 0; j < size; j++)
                printf("%d ",array[j]);
        }
        processCommand(command, array, size);
    }
    
    return 0;
}

