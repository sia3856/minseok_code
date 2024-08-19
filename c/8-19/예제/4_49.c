#include <stdio.h>

int main() {
    int a[4] = {1, 3, 5, 7}, b[4] = {3, 4, 6, 10}, c[8];
    int i = 0, j = 0, k = 0;

    while (i < 4 && j < 4) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            i = i + 1;
        } else {
            c[k] = b[j];
            j = j + 1;
        }
        k = k + 1;
    }

    if (i == 4) {
        while (j < 4) {
            c[k] = b[j];
            j = j + 1;
            k = k + 1;
        }
    } else {
        while (i < 4) {
            c[k] = a[i];
            i = i + 1;
            k = k + 1;
        }
    }

    for (k = 0; k < 8; k++) {
        printf("%d ", c[k]);
    }

    return 0;
}
