#include<stdio.h>

int a[10] = {11, 18, 26, 27, 39, 57, 63 , 75, 76, 80};
int start = 0;
int end = 9;
int mid, key;

int main(void)
{
    printf("찾고 싶은 정수를 입력하시오.");
    scanf("%d",&key);
    while(start<=end)
    {       
        mid = ((start + end) / 2);    

        if(key == a[mid])
        {
            printf("%d에서 탐색 성공\n",mid+1);
            break;
        }
        else if(key < a[mid])
            end = mid - 1;
        else
            start = mid +1;
    }
    if (start > end)
        printf("탐색 실패");
    return 0;
}