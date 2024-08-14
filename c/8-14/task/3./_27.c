#include<stdio.h>

int num = 1;
int cnt = 1;

int main(void)
{
    printf("정수를 입력하시오. :");
    scanf("%d",&num);
    printf("%d의 계승값은 ", num);
    while(num > 0)
    {       
        cnt *= num;
        num-- ;
    }
printf("%d\n", cnt);

return 0;
}