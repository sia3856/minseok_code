#include<stdio.h>
int i, num;

int main(void)
{
    for(i=0;i<=100;i++)
    {
        if(i%2 == 0)
            num += i;
    }
    printf("%d", num);

    return 0; 
}