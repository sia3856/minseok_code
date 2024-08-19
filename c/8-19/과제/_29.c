#include <stdio.h>

int num1;
int num2;
int num3;
int i;

int main()
{
    printf("숫자를 입력하시오. : ");
    scanf("%d",&num1);
    printf("숫자를 입력하시오. : ");
    scanf("%d",&num2);
    printf("숫자를 입력하시오. : ");
    scanf("%d",&num3);

    for (i = 1; i <= num2; i++) 
    {
        if (num1 % i == 0 && num2 % i == 0 && num3 % i == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}
