#include <stdio.h>
int sum = 0;
int i,j,n;

int main() {
    for (i = 1; i <= 10; i++) {
        n = i + 1;
        for (j = 1; j < n; j++) {
            sum += j;
        }
    }

    printf("%d\n", sum);

    return 0;
}
