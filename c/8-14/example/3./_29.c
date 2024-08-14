#include<stdio.h>

int a = 1;
int b = 0;
int c, cnt;

int main(void)
{
    for (cnt = 1; cnt <= 20; cnt++) 
    {
        c = a+b;
        a = b;
        b = c;
        printf("%d ",c);
    }
    return 0;
}