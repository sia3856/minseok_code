#include<stdio.h>

int main(void)
{
    int x = 100;
    while(x++ < 103)
    {
        printf("%4d",x);
        printf("%4d",x);
    }

return 0;
}

/* 101 101 102 102 103 103 */