#include <stdio.h>

int main() {
    int i, a[10], temp;
    
    for (i = 0; i < 10; i++) {
        a[i] = i + 1;
    }

    temp = a[0];
    for (i = 0; i < 9; i++) {
        a[i] = a[i + 1];
    }

    a[9] = temp;
    
    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}
