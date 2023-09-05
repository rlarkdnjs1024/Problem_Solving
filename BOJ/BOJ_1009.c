#include <stdio.h>
int getModTen (int a, int b);

int main(void)
{
    int input;
    int a, b;
    scanf("%d",&input);
    
    for (int i = 0; i < input; i++)
    {
        scanf("%d %d",&a, &b);
        printf("%d\n",getModTen(a, b));
    }
}

int getModTen (int a, int b)
{
    int result = 1;
    for (int i = 0; i < b; i++)
    {
        result = result * (a % 10);
        result = result % 10;
    }
    return result == 0 ? 10 : result;
}

