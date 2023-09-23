#include <stdio.h>
#include <stdlib.h>

typedef int data; //리스트에 사용할 데이터의 자료형을 입력 int를 대신해서 입력.

typedef struct
{
    data *array; //이 포인터에 메모리를 할당한 후 배열처럼 사용할 것이다.
    int rear; //배열을 마지막 원소의 인덱스를 저장한다.
    int size; //베열의 크기를 저장한다.
}list;

void initList (list *p) //리스트 구조체를 초기화한다.
{
    p->array = (data *)calloc(sizeof(data), 1);
    if (p->array == NULL)
        exit(1);
    p->rear = -1;
    p->size = 1;
}

void insertLast (list *p, data element) //맨 뒤에 요소를 삽입한다.
{
    if (p->rear == p->size - 1)
    {
        p->size *= 2;
        p->array = (data *)realloc(p->array, sizeof(data) * p->size);
        if (p->array == NULL)
            exit(1);
    }
    p->array[++p->rear] = element;
}

void insert (list *p, int index, data element)
{
    if ( index > p->rear || index < 0)
    {
        printf("해당위치에 원소를 넣을 수 없습니다.\n");
        return;
    }
    
    else  if (p->rear == p->size - 1)
    {
        p->size *= 2;
        p->array = (data *)realloc(p->array, sizeof(data) * p->size);
        if (p->array == NULL)
            exit(1);
    }
    
    for ( int i = p->rear; i >= index; i--)
        p->array[i+1] = p->array[i];
    p->array[index] = element;
    p->rear++;
}

void delete (list *p, int index)
{
    if ( index > p->rear || index < 0)
    {
        printf("해당 위치에서 원소를 삭제할 수 없습니다.\n");
        return;
    }
    
    for ( int i = index + 1; i <= p->rear; i++)
        p->array[i-1] = p->array[i];
    p->rear--;
}

void deleteLast (list *p, data element)
{
    p->rear--;
}

data peek (list *p, int index)
{
    return p->array[index];
}

void printList (list *p)
{
    for ( int i = 0; i <= p->rear; i++)
    {
        printf("%d ", *(p->array + i));
    }
    printf("\n");
}

int main(void)
{
    list myList;
    
    initList(&myList);
    
    insertLast(&myList, 1);
    printList(&myList);
    
    insertLast(&myList, 2);
    printList(&myList);
    
    insertLast(&myList, 3);
    printList(&myList);
    
    insert(&myList, 0, 5);
    printList(&myList);
    
    delete(&myList, 1);
    printList(&myList);
    
    
    free(myList.array);
    return 0;
}








