#include<stdio.h>

int cnt, min;
int num[10] = {18, 68, 51 ,21 ,68 ,45 ,30 ,73 ,50 ,53};

int main(void)
{
    min = num[0];
    for(cnt = 1; cnt <=9; cnt++)
    {
        if(min > num[cnt])
            min = num[cnt];
    }
    printf("최솟값은 %d\n", min);
    return 0;
}