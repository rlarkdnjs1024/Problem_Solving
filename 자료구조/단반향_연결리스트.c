#include <stdio.h>
#include <stdlib.h>


typedef struct _listNode
{
    int element;
    struct _listNode *next;
}listNode;

void printList (listNode *head);
listNode *insertFirst (listNode *head, int element);
listNode *deletefirst (listNode *head);
listNode *insertLast (listNode *head, int element);

int main(void)
{
    listNode *head = NULL;
    while(1)
    {
        int menu;
        int temp;
        printf("\n<메뉴를 선택하세요>\n 1: 리스트 출력\n 2: 맨 앞에 추가\n 3 : 맨 뒤에 추가\n 4 : 맨 앞 제거\n 5: 종료\n->");
        scanf("%d",&menu);
        if (menu == 0)
        {
            printList(head);
        }
        else if (menu == 1)
        {
            printList(head);
        }
        
        else if (menu == 2)
        {
            printf("정수를 입력하세요 ->");
            scanf("%d",&temp);
            head = insertFirst(head, temp);
        }
        else if (menu == 3)
        {
            printf("정수를 입력하세요 ->");
            scanf("%d",&temp);
            head = insertLast(head, temp);
        }
        else if (menu == 4)
        {
            head = deletefirst(head);
        }
        else if (menu == 5)
        {
            return 0;
        }
    }
}
    
void printList (listNode *head)
{
    if (head == NULL)
        printf("리스트가 비어있습니다.\n");
    else
    {
        for (listNode *p = head; p != NULL; p = p->next) //p가 현재 출력할 노드를 가르킨다. 출력 후, 다음 노드를 가르킨다.
        {
            printf("%d",p->element);
            if (p->next != NULL)
                printf(" -> ");
        }
        printf("\n");
    }
}

listNode *insertFirst (listNode *head, int element)
{
    listNode *new = (listNode *)malloc(sizeof(listNode)); //새로운 노드를 생성하고, 그 노드의 주소를 저장한다.
    new->element = element;
    new->next = head; //우선 가장 앞에 올 노드를 두번째 노드에 연결한다.
    head = new;
    return head;
}

listNode *deletefirst (listNode *head)
{
    if (head == NULL)
    {
        printf("리스트가 비어있습니다.\n");
        return NULL;
    }
    listNode *rm = head;
    head = rm->next;
    free(rm);
    return head;
}

listNode *insertLast (listNode *head, int element)
{
    listNode *new = malloc(sizeof(listNode));
    new->element = element;
    new->next = NULL;
    listNode *p = head;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = new;
    }
    return head;
}



