#include <stdio.h>
int getMovieNumber (int n);

//백준 1436번 영화감독 숌
//브루트포스 알고리즘을 이용. 666부터 1씩 더해가면서 종말의수인지 판단하며 개수를 센다.
int main(void)
{
    int N;
    scanf("%d",&N);
    printf("%d",getMovieNumber(N));

    return 0;
}

int getMovieNumber (int n)
{
    int numSave = 0;
    int temp = 0;
    int count = 0;
    int countSix = 0;
    
    for (int i = 666; count < n; i++)
    {
        numSave = i;
        temp = i;
        countSix = 0;
        while (temp > 0) //이 반복문에서 해당 숫자의 연속된 6의 개수를 파악한다.
        {
            if ( temp % 10 == 6 )
            {
                countSix++;
                if (countSix == 3) //더해서 3개가 되면 탈출.
                    break;
            }
            else
                countSix = 0;
            temp /= 10;
            
        }
        if (countSix >= 3)
            count++;
    }
    return numSave;
}

