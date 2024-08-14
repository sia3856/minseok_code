#include<stdio.h>

int num;

int main(void)
{
    printf("숫자를 입력하시오.\n");
    scanf("%d", &num);
    printf("정수 : %d\n", num);

    if(num%3 == 0)
        printf("%d는 3의배수 입니다.\n", num);
    else
        printf("%d는 3의배수가 아닙니다.\n", num);

    return 0;
}