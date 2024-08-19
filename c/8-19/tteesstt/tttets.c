#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Run();
int InputMoney();
int main(void)
{
   
    int slot[3]={0};
    int a, b, c, end;
    int money, cnt=0;
//배팅금액 입력
while(1)
    {
    money=InputMoney();
//게임결과
    srand(time(NULL));
    for(int i=0 ; i<=2; i++)
    {   if(i==0)
        slot[0]=Run(a);
        else if(i==1)
        slot[1]=Run(b);
        else
        slot[2]=Run(c);
    }
    printf("게임결과 : %d %d %d\n",slot[0],slot[1],slot[2]);
//등수
     
    // 쩡누
    
    for(int i=0;i<3;i++)
    {
        if(i==2)
        {
            if(slot[0]==slot[2])
            {
                cnt=cnt+1;
            }
        }
        else {
            if(slot[i]==slot[i+1])
            {
                cnt=cnt+1;
 
            }
        }
    }

    if(cnt==2)
    {
        if(slot[0]==7)
        {
            printf("축하합니다! 1등입니다!\n");
            printf("%d원이 지급됩니다.\n",money*5);
        }
        else
        {
            printf("축하합니다! 2등입니다!\n");
            printf("%d원이 지급됩니다.\n",money*3);
        }       
    }
    else if(cnt == 1)
    {
            printf("축하합니다! 3등입니다!\n");
            printf("%d원이 지급됩니다.\n",money*2);
    }
    else
    {
            printf("축하합니다! 꼴등입니다!\n");
            printf("도박중독에서 벗어나셨습니다! 집에가세요!\n");
    }
//마지막 질문
    printf("게임을 계속 하시겠습니까? 예 <1> 아니요 <0>");
    scanf("%d",&end);

    if(end == 1)
        continue;
    else if(end == 0)
        break;
    else
        printf("멍청한 자식! 넌 자격이 없다 집이나 가!");
        break;
    }
    return 0;
}



//빠칭코 함수
int Run()
{
    int run = rand() % 9+1;
    return run;
}


//배팅금액 함수
int InputMoney()

{
    int money;
    while(1)
        {
            printf("배팅금액을 입력하세요<도박중독방지. 100원 미만으로만 배팅하세요>");
            scanf("%d", &money);
            if(money > 100)
            {
                printf("도박중독방지협회에서 나왔습니다. 100원 미만으로 금액을 조정하세요! 안그러면 체포합니다!\n");
                while(getchar() != '\n');
                continue;
            }                
            else
            {
                return money;//무한루프를 탈출 시키고(함수 종료시키고) 메인함수에 입력받은 값을 리턴시켜라!
            }
        }
}