#include<stdio.h>
int i;
int num = 0;

int main(void)
{
    for(i=1;i<=100;i++)
        {
            if(i%2 == 0)
            {
                num += i;
            }
        }
    printf("%d ", num);
    return 0;
}