#include<stdio.h>

int res, num1, num2, max;

void intro(void);
void func(void);

int main(void)
{
    intro();
    func();
    
    printf("가장 큰수 : %d\n", res);
    return 0;
}

void func(void)
{
    if(max > num1)
    {
        if(max > num2)
            res = max;
        else
            res = num2;
    }
    else 
    {
        max = num1;
        if(max > num2)
            res = max;
        else
            res = num2;
    }
}
void intro(void)
{
    printf("숫자를 입력하시오.\n");
    scanf("%d", &max);
    printf("다음 숫자를 입력하시오.\n");
    scanf("%d", &num1);
    printf("다음 숫자를 입력하시오.\n");
    scanf("%d", &num2);
}