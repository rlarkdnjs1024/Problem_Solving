#include <stdio.h>
#include <stdlib.h>

//백준 5397번 키로거 -- 연결리스트 활용
typedef struct _listNode
{
    char data;
    struct _listNode *left;
    struct _listNode *right;
    
} listNode;

void initList (listNode *hp, listNode **cursor)
{
    hp -> left = NULL;
    hp -> right = NULL;
    *cursor = hp;
}

void clearList (listNode *hp, listNode **cursor)
{
    listNode *temp = *cursor;
    while (temp -> left != NULL)
    {
        listNode *delete = temp;
        temp = temp -> left;
        free(delete);
        
    }
    initList(hp, cursor);
}


void writeText (listNode **cursor, char data)
{
    listNode *new = (listNode *)malloc(sizeof(listNode));
    new -> data = data;
    new -> left = *cursor;
    new -> right = (*cursor)->right;
    if ((*cursor)->right != NULL)
        (*cursor)->right->left = new;
    (*cursor)->right = new;
    *cursor = new;
}

void deleteText (listNode **cursor)
{
    if ((*cursor)->left == NULL)
        return;
    listNode *delete = *cursor;
    (*cursor)->left->right = (*cursor)->right;
    if ((*cursor)->right != NULL)
        (*cursor)->right->left = (*cursor)->left;
    *cursor = (*cursor)->left;
    free(delete);
    
}

void moveLeft (listNode **cursor)
{
    if ((*cursor)->left == NULL)
        return;
    *cursor = (*cursor)->left;
}

void moveRight (listNode **cursor)
{
    if ((*cursor)->right == NULL)
        return;
    *cursor = (*cursor)->right;
}

void printPW (listNode *hp)
{
    listNode *temp = hp;
    do
    {
        temp = temp -> right;
        printf("%c",temp->data);
        
    } while (temp->right != NULL);
    printf("\n");
}

int main(void)
{
    int index;
    int testCases;
    listNode head;
    listNode *cursor;
    
    initList(&head, &cursor);
    char *input = (char *)calloc(sizeof(char), 1000001);
    scanf("%d",&testCases);
    
    for (int i = 0; i < testCases; i++)
    {
        scanf("%s",input);
        index = 0;
        while (input[index] != 0)
        {
            if (input[index] == '<')
            {
                moveLeft(&cursor);
            }
            
            else if (input[index] == '>')
            {
                moveRight(&cursor);
            }
            
            else if (input[index] == '-')
            {
                deleteText(&cursor);
            }
            else
            {
                writeText(&cursor, input[index]);
            }
            index++;
        }
        printPW(&head);
        clearList(&head, &cursor);
    }
    
    
    return 0;
}

