#include<stdio.h>

int age;
int price = 5000;

int main(void)
{
    printf("나이를 입력하시오.\n");
    scanf("%d", &age);
    printf("나이 : %d\n", age);

    if(age < 8)
        printf("무료입니다.\n");
    else if((age >= 8) && (age < 60))
        printf("%d원 입니다", price/2);
    else
        printf("%d원 입니다", price);
    
    return 0;
}