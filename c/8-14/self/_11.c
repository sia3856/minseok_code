#include<stdio.h>

int num;

int main(void)
{
    printf("숫자를 입력하시오.\n");
    scanf("%d", &num);
    printf("정수 : %d\n", num);

    if(num % 2 == 1)
        printf("홀수입니다.\n");
    else 
        printf("짝수입니다.\n");
    
    return 0;
}

// 1. 홀수  2. 짝수