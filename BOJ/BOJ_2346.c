#include <stdio.h>
#include <stdlib.h>

typedef struct _listNode
{
    int content;
    int balloonNum;
    struct _listNode *left;
    struct _listNode *right;
    
}listNode;

void initList (listNode *hp)
{
    hp->left = hp;
    hp->right = hp;
}

void addLast (listNode *hp, int element)
{
    static int i;
    i++;
    listNode *last = hp->left;
    listNode *new = malloc(sizeof(listNode));
    if (new == NULL)
    {
        printf("메모리 할당에 실패했습니다.\n");
        exit(1);
    }
    new->balloonNum = i;
    new->content = element;
    
    new -> left = last;
    last -> right = new;
    new -> right = hp;
    hp -> left = new;
    
}

void pop (listNode *target) //이상 없음.
{
    target->left->right = target->right;
    target->right->left = target->left;
    free(target);
}

void printList (listNode *head) //이상없음
{
    listNode *cursor = head;
    
    while(1)
    {
        cursor = cursor->right;
        if (cursor == head)
            break;
        printf("%d번 풍선 : %d\n",cursor->balloonNum, cursor->content);
    }
}

int getOrder (listNode **cursor, listNode *head, int input)
{
    static int count;
    listNode *target = *cursor;
    int balloon = (*cursor)->balloonNum; //현재 커서가 가르키는 풍선 번호를 저장한다.
    int move = (*cursor)->content; //현재 커서가 가르키는 풍선 속 이동 횟수를 저장한다.
    count++;
    if (count == input)
    {
        pop(*cursor);
        return balloon;
    }
    int i = 0;
    if ( move > 0 )
    {
        while ( i < move)
        {
            *cursor = (*cursor) -> right;
            if (*cursor == head || *cursor == target)
                continue;
            i++;
        }
    }
    
    else
    {
        move = -move;
        while ( i < move)
        {
            *cursor = (*cursor) -> left;
            if (*cursor == head || *cursor == target)
                continue;
            i++;
        }
    }

    pop(target);
    //printList(head);
    return balloon;
}

int main(void)
{
    listNode head;
    int input;
    
    initList(&head);
    scanf("%d",&input);
    for (int i = 0; i < input; i++)
    {
        int temp;
        scanf("%d",&temp);
        addLast(&head, temp);
    }
    
    //printList(&head);
    
    listNode *cursor = head.right; //커서가 첫번쨰 풍선을 가르킨다.
    
    for (int i = 0; i < input; i++)
    {
        printf("%d ",getOrder(&cursor, &head, input));
    }
    printf("\n");
    
    
    
    return 0;
}

