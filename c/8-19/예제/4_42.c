#include <stdio.h>

int main() {
    int a[101] = {0}, i, j;

    for (i = 2; i <= 100; i++) {
        if (a[i] == 0) {
            for (j = i * 2; j <= 100; j = j + i) {
                a[j] = 1;
            }
        }
    }

    for (i = 2; i <= 100; i++) {
        if (a[i] == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}
