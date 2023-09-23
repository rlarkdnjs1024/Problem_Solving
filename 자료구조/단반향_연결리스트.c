#include <stdio.h>
#include <stdlib.h>

typedef int data;

typedef struct _listNode
{
    data element;
    struct _listNode *next;
    
}listNode;

typedef struct
{
    int size;
    listNode *headAdrs;
    listNode *lastAdrs;
    
}list;

void initList (list *p)
{
    p->headAdrs = NULL;
    p->lastAdrs = NULL;
    p->size = 0;
}

void printList (list *p)
{
    listNode *temp = p->headAdrs; //첫번째 메모리의 주소를 저장한다.
    while (temp != NULL)
    {
        printf("%d ",temp->element);
        temp = temp->next; //다음 주소를 저장한다.
    }
    printf("\n");
}

void insertFirst (list *p, data element)
{
    listNode *temp = (listNode *)malloc(sizeof(listNode));
    if (p->headAdrs == NULL) //리스트가 비어 있었을 떄
    {
        temp->element = element;
        temp->next = NULL;
        p->headAdrs = temp;
        p->lastAdrs = temp;
       
    }
    else
    {
        temp->element = element;
        temp->next = p->headAdrs;
        p->headAdrs = temp;
    }
    p->size++;
}

void deleteFirst (list *p)
{
    listNode *temp;
    
    if (p->headAdrs == NULL) //리스트가 아예 비어있을떄
        return;
    
    
    temp = p->headAdrs->next;
    
    if (temp == NULL) //리스트에 원소가 하나 있었을때
    {
        free(p->headAdrs);
        p->headAdrs = NULL;
        p->lastAdrs = NULL;
    }
    
    else //나머지 보통의 경우
    {
        free(p->headAdrs);
        p->headAdrs = temp;
        
    }
    p->size--;
}

int main(void)
{
    list a;
    initList(&a);
    
    deleteFirst(&a);
    printList(&a);
    
    insertFirst(&a, 10);
    printList(&a);
    
    deleteFirst(&a);
    printList(&a);
    
    insertFirst(&a, 20);
    printList(&a);
    
    insertFirst(&a, 30);
    printList(&a);
    
    insertFirst(&a, 40);
    printList(&a);
    
    deleteFirst(&a);
    printList(&a);
    
    insertFirst(&a, 50);
    printList(&a);
    
    return 0;
}
