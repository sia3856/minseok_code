#include<stdio.h>

int min, num1, num2;

int main(void)
{
    printf("첫번째 값을 입력하시오.\n");
    scanf("%d", &min);
    printf("두번째 값을 입력하시오.\n");
    scanf("%d", &num1);
    printf("세번째 값을 입력하시오.\n");
    scanf("%d", &num2);

    if(min < num1)
        if(min < num2)
            printf("가장 작은수는 %d 이다.", min);
        else
            printf("가장 작은수는 %d 이다.", num2);

    else if(min > num1)
    {
        min = num1;
        if(min < num2)
            printf("가장 작은수는 %d 이다.", min);
        else
            printf("가장 작은수는 %d 이다.", num2);
    }

    return 0;   
}