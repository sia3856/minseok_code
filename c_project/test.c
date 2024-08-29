#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <ctype.h>


int outro() {
    char *credits[] = {
        "",
        "\t\t\tThank you for playing",
        "",
        "\t\t\t팀 : 광산구 서구 ",
        "",
        "\t\t\t팀장 : 김민석   팀원:  신명호",
        "",
        "\t\t\t제작기간 : 8-20 ~ 8-29",
        "",
        "\t\t\t전투 : 신명호 ",
        "",
        "\t\t\t맵이동 : 신명호",
        "",
        "\t\t\t몬스터 : 신명호",
        "",
        "\t\t\t몬스터이동 로직 : 신명호",
        "",
        "\t\t\t아이템 드랍 : 신명호",
        "",
        "\t\t\tNPC : 김민석",
        "",
        "\t\t\t인터페이스 : 김민석",
        "",
        "\t\t\t소비아이템 : 김민석",
        "",
        "\t\t\t장비아이템 : 김민석",
        "",
        "\t\t\t사용된 구조체 : 14개",
        "",
        "\t\t\t만든 함수 : 44개 ",
        "",
        "\t\t\t사용된 변수 : 측정불가",
        "",
        "\t\t\t총 n 줄",
        "",
        "\t\t\t글자수 : ???",
        "",
        "\t\t\tSpecial Thanks to 최상문 교수님",
        "",
        NULL
    };

    int total_lines = 0;
    while (credits[total_lines] != NULL) {
        total_lines++;
    }
    

    for (int i = 0; i < total_lines + 30; i++) {
        //printf("\033[H\033[J"); 
        system("clear");
        for (int j = 0; j < 30; j++) {
            int line = i + j - 30;
            if (line >= 0 && line < total_lines) {
                printf("%s\n", credits[line]);
            } else {
                printf("\n");
            }
        }
        usleep(150000);
    }
}

int main(void)
{
    outro();
}