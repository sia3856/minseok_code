#include<stdio.h>

int num;

int main(void)
{
    printf("숫자를 입력하시오.\n");
    scanf("%d", &num);
    printf("정수 : %d\n", num);

    if((num % 5 == 0) && (num % 3 == 0))
        printf("3과 5의 배수입니다.\n");
    else if(num % 5 == 0)
        printf("5의 배수입니다.\n");
    else if(num % 3 == 0)
        printf("3의 배수입니다.\n");
    else
        printf("3과 5의 배수 둘다 아닙니다.\n");

    return 0;
}
