#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define yellow	"\033[38;2;255;255;0m"
#define end	"\033[0m"



int main()
{
    int sta = 3;
    char sss[100];
    printf("\033[38;2;255;255;0m");
    printf("안녕하세요\n");
    printf("\033[0m"); 
    sprintf(sss,"%s상태이빈다.\n", (sta== 0) ? "로그아웃":(sta == 2) ? "전체 채팅방" : (sta == 3) ? "1:1채팅방": "오류");
    printf("%s",sss);
    printf("%s안녕하세요\n%s",yellow,end);
    printf("\033[38;2;255;255;0m안녕하세요\n\033[0m");







}

