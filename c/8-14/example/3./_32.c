#include<stdio.h>

int num, cnt;
int main(void)
{   
    for(num = 1; num <= 10; num++)
    {
        printf("%d의 약수 : ",num);
        for(cnt = 1; cnt<=10; cnt++)
        {   
            if(num % cnt == 0)
            {
                printf("%d ",cnt);
            }
        }
        printf("\n");
    }
    return 0;
}