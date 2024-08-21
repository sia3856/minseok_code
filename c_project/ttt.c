#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int epoch = 10000000;
int num = 0;
double prize1,prize2,prize3,prize4,prize5,prize6;                // 1등 10배 2등 5 배 3등 3배  4등 2배 5등 1배 6등 꽝(돈날림) 
int main(void)                                                   //    3퍼    6퍼      9퍼       14퍼    28퍼    40퍼                                     
{
    srand(time(NULL));
    for(int i = 0; i<=epoch;i++)
    {
        num = (rand() % 100)+1;
        if(num<=3)
            prize1++;
        else if (num>3 && num<=9)
            prize2++;
        else if (num>9 && num<=18)
            prize3++;
        else if (num>18 && num<=32)
            prize4++;
        else if (num>32 && num<=60)
            prize5++;
        else
            prize6++;       
        
    }
    printf("총 횟수 : %d\n",epoch);
    printf("1등:%6.2f%% 2등:%6.2f%% 3등:%6.2f%% 4등:%6.2f%% 5등:%6.2f%% 6등:%6.2f%% \n",prize1/epoch*100.0,prize2/epoch*100.0,prize3/epoch*100.0,prize4/epoch*100.0,prize5/epoch*100.0,prize6/epoch*100.0);
    return 0;
}


