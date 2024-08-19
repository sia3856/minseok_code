#include <stdio.h>

int sum = 0;
int i;

int main()
{
    for (i = 3; i <= 100; i += 3) {
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}
