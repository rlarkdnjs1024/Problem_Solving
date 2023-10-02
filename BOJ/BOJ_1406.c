#include <stdio.h>
#include <stdlib.h>

//백준 1406번 에디터 -> 문자를 추가하는 연산이 필요하므로 배열보단 연결리스트를 이용한다.

typedef struct _listNode
{
    char data;
    struct _listNode *left;
    struct _listNode *right;
    
}listNode;

void initList (listNode *hp, listNode **cursor) //이상없음
{
    *cursor = hp; //커서를 헤드노드로 설정한다.
    hp -> data = 'F'; //첫번쩨 문자를 대충 이걸로 설정.
    hp -> left = NULL;
    hp -> right = NULL;
}

void writeText (listNode **cursor, char data) //이상없음
{
    listNode *new = (listNode *)malloc(sizeof(listNode));
    new -> data = data;
    new -> left = *cursor;
    new -> right = (*cursor) -> right;
    if ((*cursor)->right != NULL)
        (*cursor)->right->left = new;
    (*cursor) -> right = new;
    *cursor = new;
}

void deleteText (listNode **cursor)
{
    listNode *delete = *cursor;
    if ((*cursor)->left != NULL) //커서가 헤드노드가 아닐때
    {
        (*cursor)->left->right = (*cursor)->right;
        if ((*cursor)->right != NULL) //지우는게 마지막 문자가 아닐 때
            (*cursor)->right->left = (*cursor)->left;
        *cursor = (*cursor)->left;
        free(delete);
        
    }
}

void moveLeft (listNode **cursor)
{
    if ((*cursor)->left != NULL)
    {
        *cursor = (*cursor)->left;
    }
}

void moveRight (listNode **cursor)
{
    if ((*cursor)->right != NULL)
    {
        *cursor = (*cursor)->right;
    }
}

void printText (listNode *hp, listNode **cursor)
{
    listNode *temp = hp;
    do
    {
        temp = temp->right;
        printf("%c",temp->data);
        
    } while(temp->right != NULL);
    //printf("\n커서는 %c의 오른쪽에 있습니다.",(*cursor)->data);
    printf("\n");
}


int main(void)
{
    int j = 0;
    int testCases;
    char *input = (char *)calloc(sizeof(char), 100001);
    char command;
    char insert;
    
    listNode head;
    listNode *cursor;
    initList(&head, &cursor);
    
    scanf("%s",input);
    
    while ( input[j] != 0) //리스트에 초기의 문자열을 넣어주는 과정이다.
    {
        writeText(&cursor, input[j]);
        j++;
    }
    
    //printText(&head,&cursor);
    
    scanf("%d",&testCases);
    for (int i = 0; i < testCases; i++)
    {
        getchar();
        command = getchar();
        
        if (command == 'P')
        {
            getchar();
            insert = getchar();
            writeText(&cursor, insert);
            
        }
        
        else if (command == 'L')
        {
            moveLeft(&cursor);
        }
        
        else if (command == 'D')
        {
            moveRight(&cursor);
        }
        
        else
        {
            deleteText(&cursor);
        }
        //printText(&head,&cursor);
    }
    printText(&head,&cursor);
    return 0;
}


