#include<stdio.h>

int a, b, c;

int main(void)
{
    printf("a의 값을 입력하시오.\n");
    scanf("%d", &a);
    printf("b의 값을 입력하시오.\n");
    scanf("%d", &b);
    printf("c의 값을 입력하시오.\n");
    scanf("%d", &c);

    if((a < b) && (a < c))
        printf("가장 작은수는 %d 이다.", a);

    else if((a > b) && (a < c))
        printf("가장 작운수는 %d 이다.", b);

    else if((a < b) && (a > c))
        printf("가장 작은수는 %d 이다.", c);

    else if((a > b) && (b < c))
        printf("가장 작은수는 %d 이다.", b);
        
    else 
        printf("가장 작은수는 %d 이다.", c);

    return 0;
}
        