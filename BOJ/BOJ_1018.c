//백준 1018번 체스판 다시 칠하기
//@autor 김가원 rosaeflora@hanyang.ac.kr

#include <stdio.h>
#include <stdlib.h>

void setStartPoint (int *sg, int *sr, int *g, int *s);
int returnMinChange (int *sg, int *ss, int firstChar, char **board);

int main(void)
{
    char **chess;
    int garo, sero;
    int startPointG, startPointS;
    int min;
    
    scanf("%d %d", &sero, &garo);
    chess = (char **)calloc(sizeof(char*), sero);
    min = garo * sero;
    
    for ( int i = 0; i < sero; i++)
    {
        chess[i] = (char *)calloc(sizeof(char), garo + 1);
        scanf("%s",chess[i]);
    }
    
    for ( int i = 0; i < (garo-7)*(sero-7); i++)
    {
        setStartPoint(&startPointG, &startPointS,&garo, &sero);
        for ( int j = 0; j < 2; j++)
        {
            int temp = returnMinChange(&startPointG, &startPointS, j,chess);
            if ( temp < min )
                min = temp;
        }
    }
    printf("%d",min);
    return 0;
}

void setStartPoint (int *sg, int *ss, int *g, int *s)
{
    int static count = -1;
    count++;
    *ss = count / (*g - 7);
    *sg = count % (*g - 7);

}

//시작점을 인수로해서 8 * 8판을 검사해서 최솟값을 반환한다.
int returnMinChange (int *sg, int *ss, int firstChar, char **board)
{
    int temp;
    int count = 0;
    char array[3] = {'B', 'W'};
    temp = firstChar;
    for ( int i = *ss; i < *ss + 8; i++)
    {
        for ( int j = *sg; j < *sg + 8; j++)
        {
            if (array[temp] != board[i][j])
                count++;
            if ( j != *sg + 7 )
            {
                temp++;
                temp = temp % 2;
            }
        }
    }
    return count;
}

