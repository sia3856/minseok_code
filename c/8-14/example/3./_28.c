#include <stdio.h>

int num, cnt;
int sta = 1; 

int main()
{
    printf("정수를 입력하세요: ");
    scanf("%d", &num);

    for (cnt = 2; cnt <= num / 2; cnt++) 
    {
        if (num % cnt == 0) {
            sta = 0; 
            break;
        }
    }
    if (sta == 1)
        printf("%d는 소수입니다.\n", num);
    else
        printf("%d는 소수가 아닙니다.\n", num);

    return 0;
}