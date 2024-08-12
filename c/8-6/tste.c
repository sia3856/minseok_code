#include <stdio.h>
int main(void)
{
    int n = 4;
    int m = 5;
    float f = 7.0f;
    float g = 8.0f;
    
    printf("%d\n", n, m);    /* 전달인자가 너무 많다   */
    printf("%d %d %d\n", n); /* 전달인자가 너무 적다    */
    printf("%d %d\n", f, g); /* 데이터형이 일치 하지 않는다 */
    
    return 0;
}