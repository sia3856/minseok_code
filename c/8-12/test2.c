#include <stdio.h>

void swap1(int a, int b);
void swap2(int *a, int *b);

int main(void)
{
    int a = 10, b = 20;
    int temp;

    printf("0. a:%d, b:%d\n", a, b);

    temp = a; // temp = 10, a = 10, b = 20
    a = b;      // temp = 10, a = 20, b = 20
    b = temp; // temp = 10, a = 20, c = 10

    swap1(a, b);
    printf("1. a:%d, b:%d\n", a, b);

    swap2(&a, &b);
    printf("2. a:%d, b:%d\n", a, b);

    return 0;
}

void swap1(int a, int b)
{
    int temp;
    temp = a; // temp = 10, a = 10, b = 20
    a = b;      // temp = 10, a = 20, b = 20
    b = temp; // temp = 10, a = 20, c = 10
}

void swap2(int *a, int *b)
{
    int temp;
    temp = *a; // temp = 10, a = 10, b = 20
    *a = *b;   // temp = 10, a = 20, b = 20
    *b = temp; // temp = 10, a = 20, c = 10
}