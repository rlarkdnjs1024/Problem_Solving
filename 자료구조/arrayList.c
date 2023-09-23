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

void insert (list *p, data element) //맨 뒤에 요소를 삽입한다.
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

void delete (list *p, data element)
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
    insert(&myList, 1);
    insert(&myList, 2);
    insert(&myList, 3);
    insert(&myList, 4);
    insert(&myList, 5);
    insert(&myList, 10);
    
    printList(&myList);
    
    free(myList.array);
    return 0;
}







