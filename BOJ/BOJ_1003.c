#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int n;
    int zero;
    int one;
    
}fibonacci;

void initArray (fibonacci *array, int target);

int main(void)
{
    int input;
    int target;
    fibonacci array[41]; //0부터 40번까지의 배열이 완성되었다.
    
    scanf("%d",&input);
    array[0].zero = 1;
    array[0].one = 0;
    array[1].one = 1;
    array[1].zero = 0;
    for (int i = 0; i < input; i++)
    {
        scanf("%d",&target);
        initArray(array, target);
        printf("%d %d\n", array[target].zero, array[target].one);
    }
    return 0;
}

void initArray (fibonacci *array, int target) //예를 들어 22가 들어오면 22까지의 0과 1을 프린트한 횟수를 구조체배열에 넣어준다.
{
    static int max = 1;
    
    if (target > max) //들어온 숫자가 우리가 구헤놓은 번호보다 크면 실행한다.
    {
        for (int i = max + 1; i <= target; i++)
        {
            array[i].zero = array[i-1].zero + array[i-2].zero;
            array[i].one = array[i-1].one + array[i-2].one;
        }
        max = target;
    }
}

