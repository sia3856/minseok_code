#include<stdio.h>

int num;

int main(void)
{
    printf("숫자를 입력하시오.\n");
    scanf("%d", &num);
    printf("정수 : %d\n", num);

    if(num%2 == 0)
        printf("짝수입니다.\n");
    else
        printf("홀수입니다.\n");

    return 0;
}