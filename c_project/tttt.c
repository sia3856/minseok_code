#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <ctype.h>


int main(void)
{
    char name [27][10] = 
    {
    {"김승수"},{"권철민"},{"안광민"},{"강진영"},{"유시온"},
    {"김영곤"},{"박선후"},{"김건"},{"이준호"},{"이철"},
    {"이동준"},{"황은비"},{"조세빈"},{"김성근"},{"이은승"},
    {"박희정"},{"박장미"},{"김민아"},{"조대정"},{"김재신"},
    {"박민건"},{"임석현"},{"황운하"},{"노주영"},{"김혜빈"},
    {"서훈"},{"오은지"}
    };

    system("clear");
    printf("용사 복이는 찐막보스 \"류홍걸\"을 무찔렀다.\n\n");
    sleep(2);
    printf("단순히 바포메트만 처리하면 될 줄 알았지만\n");
    sleep(2);
    printf("던전의 5층에는 다른 보스인 \"이동녁\" \"류홍걸\" 이  있었고\n");
    sleep(2);
    printf("그들이 C언어를 전파해 몬스터들이 날뛰고 있었던 것이었다.\n\n");
    sleep(2);
    printf("용사 복이는 무사히 마을에 평화를 가져다 줄 수 있었다.\n");
    sleep(3);
    printf("\n\nLinEz continue ...\n\n");
    sleep(4);
    system("clear");

    for (int i = 0; i < 26; i++)
    {
            
            printf("%s, ", name[i]);

    }
    printf("%s\n", name[26]);

    printf("\n\n 나도 살려줘...\t\t                                                 나도 갇혔어...\n"
           "\n                              \t\t 나도 살려줘...                \t\t\t         나도 데려가...\n"
           "\n       살려주세요...       \t\t                    나도 구해줘...\n");
    sleep(5);
    system("clear");
}