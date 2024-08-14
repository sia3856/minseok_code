#include<stdio.h>

int num1, num2;

int main(void)
{
    printf("숫자를 입력하시오.\n");
    scanf("%d", &num1);
    printf("다음 숫자를 입력하시오.\n");
    scanf("%d", &num2);

    printf("두수의 차 : %d\n", num1 - num2);

    return 0;
}