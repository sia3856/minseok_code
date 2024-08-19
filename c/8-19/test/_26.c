#include <stdio.h>
int sum = 0;
int sum2 = 0;
int i;
int main() 
{    
    for (i = 1; i <= 100; i++)
    {
        if (i % 3 != 0) 
        {
            sum += i;
        }
        if (i % 3 == 0) 
        {
            sum2 += i;
        }
    }

    printf("%d\n", sum - sum2);

    return 0;
}
