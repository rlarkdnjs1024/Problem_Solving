#include <stdio.h>
int checkNum ( int, int);

int main(void)
{
    char *dateString[4] = {"오늘 오전", "오늘 오후", "내일 오전", "내일 오후"};
    int startingHour, startingMinute;
    int cookingHour, cookingMinute;
    int alarmHour, alarmMinute;
    int i = 0;
    
    printf("요리를 시작하는 시간을 입력해주세요. (HH MM)\n");
    
    while(1)
    {
        scanf("%d %d",&startingHour, &startingMinute);
        if ( checkNum(startingHour, startingMinute) == 0)
        {
            printf("올바른 숫자를 다시 입력해주세요.\n");
            continue;
        }
        break;
    }
    
    printf("오븐에 넣어둘 시간을 입력하세요. (MM)\n");
    
    while(1)
    {
        scanf("%d",&cookingMinute);
        if (!((cookingMinute >= 0) && (cookingMinute <= 1000)))
        {
            printf("올바른 숫자를 다시 입력해주세요.\n");
            continue;
        }
        break;
    }
    
    //입력받은 분을 시간과 분으로 바꾼다.
    cookingHour = cookingMinute / 60;
    cookingMinute = cookingMinute % 60;
    //이 값은 최대 59까지 가능함. 따라서 alarmMinute는 최대 108까지 가능하다.
    
    printf("%d시간 %d분 동안 오븐에 넣어두시는군요!\n",cookingHour,cookingMinute);
    
    //시작한 시간에서 입력받은 시간을 더해서 알람이 울릴 시간을 일단 계산한다.
    alarmHour = startingHour + cookingHour;
    alarmMinute = startingMinute + cookingMinute;
    
    if ( alarmMinute >= 60 ) //분이 60분 이상하면 시를 하나 올리고 분에서 60을 빼준다 어차피 108까지만 가능하므로 60을 뺴주기만 하면 알맞는 범위 내의 숫자로 만들 수 있다.
    {
        alarmMinute -= 60;
        alarmHour += 1;
    }
    
    if ( alarmHour >= 24 ) //그 다음날로 넘어가는 경우
    {
        alarmHour -= 24; //시간을 알맞게 조정한다.
        
        i = 2;
        
        if ( alarmHour >= 12 )
        {
            alarmHour -= 12;
            i = 3;
        }
    }
    
    else
    {
        i = 0;
        
        if (  alarmHour >= 12 )
        {
            alarmHour -= 12;
            i = 1;
        }
    }
    //시가 범위를 넘어가면, 예를들어 24시, 25시이면
    
    printf("성공적인 요리를 위해서 %s %d시 %d분에 오븐에서 요리를 꺼내세요!\n",dateString[i], alarmHour,alarmMinute);
    
    return 0;
}
            
int checkNum ( int a, int b)
{
    if (!((a >= 0) && (a <= 23)))
        return 0;
    if (!((b >= 0) && (b <= 59)))
        return 0;
    return 1;
}
