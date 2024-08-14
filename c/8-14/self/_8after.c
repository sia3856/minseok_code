#include<stdio.h>
int main()
{
    int a;
    printf("정수: ");
    scanf("%d", &a);
    if(a<0){
        printf("음수다\n");
    }
    else if(a>0){
        printf("양수다\n");
    }
    else{
        printf("0이다\n");
    }

    return 0;
}