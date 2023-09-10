#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int number;
    char name[21];
}mon;

int compare (const void *a, const void *b);
int checkInput (char *input);
int searchByName (mon *array, char *name, int size);

//최대 10만개의 문제를 풀 수 있고, 이 모든게 포켓몬의 이름이라면 시간이 오래걸린다. 일단 전
int main(void)
{
    int input;
    int quiz;
    int index;
    char **array;
    mon *sortArray;
    char temp[21];
    scanf("%d %d",&input, &quiz);
    array = (char **)calloc(sizeof(char *), input);
    sortArray = (mon *)calloc(sizeof(mon), input);
    
    for (int i = 0; i < input; i++)
    {
        scanf("%s",temp);
        int size = (int)strlen(temp) + 1;
        array[i] = (char *)calloc(sizeof(char), size);
        strcpy(array[i], temp);
        sortArray[i].number = (i+1);
        strcpy(sortArray[i].name, temp);
    }
    if ( 1 == 0) //디버깅용
    {
        for (int i = 0; i < input; i++)
        {
            printf("%d : %s\n",i+1, array[i]);
        }
    }
    qsort((void *)sortArray, input, sizeof(mon), compare);
    
    
    if ( 1 == 0) //디버깅용
    {
        printf("정렬된 문자열 출력 시작\n");
        for (int i = 0; i < input; i++)
        {
            printf("%d : %s, %d\n",i+1, sortArray[i].name, sortArray[i].number);
        }
    }
    
    for (int i = 0; i < quiz; i++)
    {
        scanf("%s",temp);
        if (checkInput(temp) == -1) //입력받은 값이 문자열일때
        {
            index = searchByName(sortArray, temp, input);
            printf("%d\n",sortArray[index].number);
        }
        else //입력받은 값이 숫자일때
        {
            index = checkInput(temp) - 1;
            printf("%s\n",array[index]);
        }
        
    }
   
    return 0;
}

int compare (const void *a, const void *b) //구조체를 이름의 알파벳 순서로 정렬한다.
{
    char *na = ((mon *)a)->name;
    char *nb = ((mon *)b)->name;
    return strcmp(na, nb);
}

int searchByName (mon *array, char *name, int size) //구조체 배열과 검색어인 이름을 매개변수로 받는다.
{
    int left = 0;
    int right = size - 1;
    int mid;
    
    while(left <= right)
    {
        mid = (left + right)/2;
        
        if (strcmp(array[mid].name, name) == 0)
            return mid;
        
        else if (strcmp(array[mid].name, name) < 0) //mid의 문자열이 찾는 문자열보다 작을떄
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    printf("그런 포켓몬은 없어요.\n");
    return -1;
}

int checkInput (char *input)
{
    if (input[0] >= '0' && input[0] <= '9') //입력받은 문자열이 숫자일떄
    {
        return atoi(input);
    }
    
    return -1; //입력받은 문자열이 포켓몬의 이름일 떄
    
}







