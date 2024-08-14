#include <stdio.h>

int n = 1;
int sum = 0;
int cnt;

int main() 
{    
    for (cnt = 1; cnt <= 5; cnt++)
    {
        printf("%2d!",cnt);
        n = n * cnt;
        sum = sum + n;
    }
    printf("의 합은 %d\n", sum);

    return 0;
}