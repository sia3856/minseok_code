#include<stdio.h>

void tree1(void);
void tree2(void);

int main(void)
{
    tree1();
    tree2();

    return 0;
}



void tree1(void)
{
    printf("   ★   \n");
    printf("   ■   \n");
    printf("  ■■■  \n");
    printf(" ■■■■■ \n");
    printf("■■■■■■■\n"); 
}

void tree2(void)
{
    printf("   ☆   \n");
    printf("   ■   \n");
    printf("  ■■■  \n");
    printf(" ■■■■■ \n");
    printf("■■■■■■■\n");
}