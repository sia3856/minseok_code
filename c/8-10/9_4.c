#include<stdio.h>
int imax();

int main(void)
{
    printf("(%d,%d)에서 큰 것은 %d\n", 3, 5, imax(3));
    printf("(%d,%d)에서 큰 것은 %d\n", 3, 5, imax(3.0, 5.0));

    return 0;
}

int imax(n,m)
int n, m;
{
    return(n>m ? n:m);
}