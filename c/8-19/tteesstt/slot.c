#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int slot[3];
int money, num, i, sta, prize;
int con = 1;

int inputmoney(void);
int run(void);

int inputmoney(void)
{
    printf("배팅금액을 입력하시오<100원미만 가능> : ");
    scanf("%d", &money);
    while(money<100 || money>=1)
    {
        //printf("배팅금액을 입력하시오<100원미만 가능> : ");
        //scanf("%d", &money);
        if(money>=100)
        {
            printf("100원 이상입니다. 다시입력하세요. : ");
            scanf("%d", &money);
            continue;
        }
        else if(money<=0)
        {
            printf("다시 입력하시오 : ");
            scanf("%d", &money);
        }
        else 
            break;
    }

}

int run(void)
{
    for (i = 0; i < 3; i++) 
    {
        //num = (rand() % 9) + 1;
        slot[0] = 3;
        slot[1] = 3;
        slot[2] = 3;
    }
    if(slot[0] == 7 && slot[1] == 7 && slot[2] == 7) 
    {
        printf("1등입니다.");
        prize = 1;
    }
    else if(slot[0] == slot[1]  == slot[2] && slot[0]!=7)
    {
        printf("2등입니다.");
        prize = 2;
    }
    else if(slot[0] == slot[1] && slot[0] == slot[2] && slot[1] != slot[2] || 
            slot[0] == slot[2] && slot[1] == slot[2] && slot[0] != slot[1] )
    {
        printf("3등입니다.");
        prize = 3;
    }
    else
    {
        printf("4등입니다.");
        prize = 4;
    }
}
int main(void)
{
    srand(time(NULL));
    
    //inputmoney();
    //run();
    //printf("게임 결과 : [%d] [%d] [%d]\n", slot[0], slot[1], slot[2]);
    
    while(sta = 1)
    {
        if(con == 1)
        {
            inputmoney();
            run();
            printf("게임 결과 : [%d] [%d] [%d]\n", slot[0], slot[1], slot[2]);
            printf("게임을 계속 하시겠습니까? 예<1> 아니요<0> : ");
            scanf("%d", &con);
        }
        else if(con == 0)
            break;
    }
    
    return 0;


}