#include<stdio.h>

int main(void)
{
    int x = (2 + 3) * 6;
    //int x = (12 + 6)/2*3;
    //int y = x = (2+3)/4;
    int y = 3+2*(x = 7/2);

    printf("x : %d\n",x);
    printf("y : %d\n",y);

    return 0;

}