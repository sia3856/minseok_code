#include<stdio.h>

int main(void)
{
    int i = 1;
    float n;
    printf("조심해! 한 무더기의 소수점을 가진 수들이 쏟아진다!\n");

    while(i<30)
    {
        n = 1/i;
        printf(" %f ", n);
        i = i+1;
    }
    printf("이제 끝이다!\n");

    return 0;
}