#include<stdio.h>

int res, num1, num2;

void intro(void);
void func(void);

int main(void)
{
    intro();
    func();
    printf("정수 : %d\n정수 : %d\n", num1, num2);
    printf("작은 수: %d\n", res);
    
    return 0;
}

void intro(void)
{
    printf("숫자를 입력하시오.\n");
    scanf("%d", &num1);
    printf("다음 숫자를 입력하시오.\n");
    scanf("%d", &num2);
}

void func(void)
{
    if(num1 > num2)
        res = num2;
    else
        res = num1;

}