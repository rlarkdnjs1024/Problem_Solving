#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min (int a, int b);
int fillBoard (int **board, int width, int height);
void printBoard (int **board, int width, int height);
int getMaxSize (int **board, int width, int height, int maxSize);

int main(void)
{
    int **board;
    int width, height;
    int maxSize;
    int maxNum;
    scanf("%d %d",&height ,&width);
    maxSize = min(height, width);
    board = (int **)calloc(sizeof(int *), height);
    for (int i = 0; i < height; i++)
        board[i] = (int *)calloc(sizeof(int *), width);

    maxNum = fillBoard(board, width, height);
    
    //printBoard(board, width, height);
    
    printf("%d\n",getMaxSize(board, width, height, maxSize));
    
    return 0;
}

int getMaxSize (int **board, int width, int height, int maxSize)
{
    for (int i = maxSize; i >= 1; i--) //찾는 정사각형의 한 변의 길이를 여기서 정한다.
    {
        if (i == 1)
            return 1;
        for (int j = 0; j <= height - i; j++)
        {
            for (int k = 0; k <= width - i; k++)
            {
                if (board[j][k] != board[j+i-1][k+i-1])
                    continue;
                if (board[j][k] != board[j][k+i-1])
                    continue;
                if (board[j][k] != board[j+i-1][k])
                    continue;
                return (int)pow(i, 2);
            }
        }
    }
    return 0;
}

int fillBoard (int **board, int width, int height) //작동확인 완
{
    char array[50];
    int max = 0;
    for (int i = 0; i < height; i++)
    {
        scanf("%s",array);
        for ( int j = 0; j < width; j++)
        {
            if (array[j] - '0' > max)
                max = array[j] - '0';
            board[i][j] = array[j] - '0';
        }
    }
    return max;
}

void printBoard (int **board, int width, int height) //작동확인 완
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%d",board[i][j]);
        }
        printf("\n");
    }
}

int min (int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

