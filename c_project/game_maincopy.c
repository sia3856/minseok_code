#include <stdio.h>
#include <stdlib.h>

void printArray(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 3, cols = 4;
    int **arr;

    // 동적 메모리 할당
    arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    // 배열 초기화
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value++;
        }
    }

    printArray(arr, rows, cols);  // 배열을 함수에 포인터로 전달

    // 동적 메모리 해제
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
