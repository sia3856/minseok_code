#include<stdio.h>
#include<unistd.h>

int num, i, sta;

int tree(void);
int star(void);
int estar(void);

int main(void)
{
    printf("숫자를 입력하시오. : ");
    scanf("%d", &num);

    while(sta = 1)
    {
        sleep(1);
        system("clear");
        star();
        tree();

        sleep(1);
        system("clear");
        estar();
        tree();
    }
    

    return 0;
}

int tree(void)
{
    for(i = 0; i < num; i++)
    {
        int j;
        for(j = num-1; j > i; j--)
        {
            printf(" ");
        }

        for(j = 0; j < 2 * i + 1; j++)
        {
            printf("█");
        }
        printf("\n");
    }
    return 0;
}

int star(void)
{
    int j;
    for(j = 0; j < num-1; j++)
    {
        printf(" ");
    }
    printf("★\n");
    return 0;
}

int estar(void)
{
    int j;
    for(j = 0; j < num-1; j++)
    {
        printf(" ");
    }
    printf("☆\n");
    return 0;
}