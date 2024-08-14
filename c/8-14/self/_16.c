#include<stdio.h>

int age;

int main(void)
{
    printf("나이를 입력하시오.\n");
    scanf("%d", &age);
    printf("나이 : %d\n", age);

    if((age >= 8) && (age < 60))
        printf("5000원 입니다\n");
    else
        printf("무료입니다.\n");
    
    return 0;
}