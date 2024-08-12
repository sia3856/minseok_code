#include<stdio.h>
#define S_TO_M 60

int main(void)
{
    int sec, min, left;
    
    printf("이 프로그램은 초 수로만 주어지는 시간을");
    printf("분 수와 초 수로 변환한다.\n");
    printf("초 수를 입력하시오.\n");
    printf("프로그램을 종료하려면 0을 입력하시오.\n");
    
    while(sec>0)
    {
        scanf("%d", &sec);
        min = sec / S_TO_M;
        left = sec % S_TO_M;
        printf("%d초는 %d분, %d초입니다.\n", sec, min ,left);
        printf("다음 입력은?\n");
    }
    printf("안녕!\n");
    return 0;

    }