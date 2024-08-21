#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int num = 0;
int money = 1000;
int in_money = 0;
int prize1,prize2,prize3,prize4,prize5,prize6;    
                                                                // 1등 10배 2등 5 배 3등 3배  4등 2배 5등 1배 6등 꽝(돈날림) 
int main(void)                                                   //    3퍼    6퍼      9퍼       14퍼    28퍼    40퍼                                     
{
    srand(time(NULL));
    printf("돈을 입력하세요. :");
    while(1)
    {
    scanf("%d", &in_money);
    if(in_money < money)
    {   
        money -= in_money;
        printf("%d",money);
        num = (rand() % 100)+1;
        if(num<=3){
            prize1++;
            break;
        }
        else if (num>3 && num<=9){
            prize2++;
            break;
        }
        else if (num>9 && num<=18){
            prize3++;
            break;
        }
        else if (num>18 && num<=32){
            prize4++;
            break;
        }
        else if (num>32 && num<=60){
            prize5++;
            break;
        }
        else{
            prize6++;  
            break;
        }
    }     
    
    else
    {
        printf("다시입력하시오. : ");
        continue; 
    }
    printf("%d",money);
    printf("1등:%d 2등:%d 3등:%d 4등:%d 5등:%d 6등:%d \n",prize1,prize2,prize3,prize4,prize5,prize6);
    return 0;
}
}


