#include<stdio.h>

int num1, num2;

int main(void)
{
    printf("숫자를 입력하시오.\n");
    scanf("%d", &num1);
    printf("다음 숫자를 입력하시오.\n");
    scanf("%d", &num2);

    if(num1 > num2)
        printf("작은 수 : %d\n" , num2);
    else
        printf("작은 수 : %d\n" , num1);

    return 0;

}