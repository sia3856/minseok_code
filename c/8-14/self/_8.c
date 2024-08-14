#include<stdio.h>
int main()
{
    int a;
    printf("정수: ");
    scanf("%d", &a);
    if(a<0){
        printf("음수다\n");
    }
    if(a>0){
        printf("양수다\n");
    }
    printf("0이다\n");

    return 0;
}

// if문이 작동을하고 printf("0이다\n"); 이것도 자동으로 실행이 되기 때문에 else와  elseif 를 사용하여 다시 만들어준다.