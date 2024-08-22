#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
 // sleep 함수를 사용하기 위해 필요
int ui();
int ui1();

int main() {
    srand(time(NULL));
    int num ;
    int i;
    
    for (i = 0; i < 20; i++) {
        num = rand()%6 +1;
        ui();
        printf("두구두구두구: %d등 \n", num);
        ui1();
        usleep(100000); 
        system("clear"); // 1초 동안 대기
    }
    
    return 0;
}


int ui()
{
    printf("══════════════□■══════\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
}

int ui1()
{
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("══════════⬛️ ⬜️══════════\n");
    printf("══════════⬛️ ⬜️══════════\n");
    printf("══════════⬛️ ⬜️══════════\n");
    printf("══════════⬛️ ⬜️══════════\n");
    printf("══════════⬛️ ⬜️══════════\n");
}
