#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num = 0;    
int slot(int *mon,int *p1, int *p2, int *p3, int *p4, int *p5, int *p6, int *s_play);

int main(void)                                                   
{
    srand(time(NULL));
    int money = 10000;
    int slot_play = 0;
    int prize1 = 0, prize2 = 0, prize3 = 0, prize4 = 0, prize5 = 0, prize6 = 0;  
    slot(&money,&prize1, &prize2, &prize3, &prize4, &prize5, &prize6, &slot_play);

    printf("최종 결과 - 잔액: %d원\n", money);
    printf("1등: %d번, 2등: %d번, 3등: %d번, 4등: %d번, 5등: %d번, 6등: %d번\n", prize1, prize2, prize3, prize4, prize5, prize6);
    printf("총 도박 횟수: %d \n", slot_play);
    return 0;
}

int slot(int *mon, int *p1, int *p2, int *p3, int *p4, int *p5, int *p6, int *s_play)
{
    int in_money = 0;
    int prize[5] = {10, 5, 3, 2, 1}; 

    while(1) {
        printf("현재 잔액: %d원\n", *mon);
        if (*mon <= 0) {
            printf("돈이 모두 소진되었습니다. 게임을 종료합니다.\n");
            break;
        }

        printf("배팅할 금액을 입력하세요 (0을 입력하면 종료): ");
        scanf("%d", &in_money);

        if (in_money == 0) {
            printf("게임을 종료합니다.\n");
            break;
        }

        if (in_money > *mon) {
            printf("잔액이 부족합니다. 다시 입력하세요.\n");
            continue;
        }

        *mon -= in_money;
        num = (rand() % 100) + 1;

        if (num <= 3) {
            (*p1)++;
            (*s_play)++;
            *mon += in_money * prize[0];
            printf("1등 당첨! 상금: %d원\n", in_money * prize[0]);
        }
        else if (num <= 9) {
            (*p2)++;
            (*s_play)++;
            *mon += in_money * prize[1];
            printf("2등 당첨! 상금: %d원\n", in_money * prize[1]);
        }
        else if (num <= 18) {
            (*p3)++;
            (*s_play)++;
            *mon += in_money * prize[2];
            printf("3등 당첨! 상금: %d원\n", in_money * prize[2]);
        }
        else if (num <= 32) {
            (*p4)++;
            (*s_play)++;
            *mon += in_money * prize[3];
            printf("4등 당첨! 상금: %d원\n", in_money * prize[3]);
        }
        else if (num <= 60) {
            (*p5)++;
            (*s_play)++;
            *mon += in_money * prize[4];
            printf("5등 당첨! 상금: %d원\n", in_money * prize[4]);
        }
        else {
            (*p6)++;
            (*s_play)++;
            printf("꽝! 상금을 받지 못했습니다.\n");
        }

        printf("현재 잔액: %d원\n", *mon);
    }
}
