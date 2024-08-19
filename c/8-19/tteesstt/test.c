#include <stdio.h>

int main() {
    int i, j;
    
    // 상단 부분 출력
    for (i = 1; i <= 7; i++) {
        for (j = 1; j <= 7 - i; j++)
            printf(" ");
        for (j = 1; j <= 2 * i - 1; j++)
            printf("*");
        for (j = 1; j <= 2 * (7 - i); j++)
            printf(" ");
        for (j = 1; j <= 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }
    
    // 중간 부분 출력
    for (i = 1; i <= 13; i++) {
        for (j = 1; j <= 2 * i - 1; j++)
            printf(" ");
        for (j = 1; j <= 27 - 2 * i; j++)
            printf("*");
        printf("\n");
    }
    
    // 하단 줄기 부분 출력
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= 12; j++)
            printf(" ");
        printf("*\n");
    }

    return 0;
}
