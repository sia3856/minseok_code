#include<stdio.h>
#define alp 'g'

int main(void)
{
    char n = '`';
    while(n++ < alp)
    {
        printf("%5c",n);
    }
    printf("\n");

    return 0;

}

/*    a    b    c    d    e    f    g */