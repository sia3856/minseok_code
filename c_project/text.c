#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <ctype.h>

                //\033[38;2;R;G:Bm 
                

#define red	"\033[38;2;255;0;0m"
#define end	"\033[0m"
#define gray "\033[38;2;153;153;153m"
#define bro "\033[38;2;102;051;051m"

int getch()
{
    int c;
    struct termios oldattr, newattr;

    tcgetattr(STDIN_FILENO, &oldattr); // 현재 터미널 설정 읽음
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);        // CANONICAL과 ECHO 끔
    newattr.c_cc[VMIN] = 1;                     // 최소 입력 문자 수를 1로 설정
    newattr.c_cc[VTIME] = 0;                    // 최소 읽기 대기 시간을 0으로 설정
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr); // 터미널에 설정 입력
    c = getchar();                              // 키보드 입력 읽음
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); // 원래의 설정으로 복구
    return c;
}
int intro();
void enter(int num)
{
    for(int i = 0; i < num; i++)
        printf("\n");
}
int main()
{

    
    
    intro();


}




int intro()
{
    system("clear");
    printf("═════════════════════════════════════════════════════════════════════════════════════════\n");
    printf("%s\n",gray);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢽⢩⣫⣓⣲⠲⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡖⣒⣝⣭⣵⢥⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡇⣿⣿⣿⣿⣦⡙⠦%s⠴⠒⣊⣫⣹⣑⡲⠲⠤%s⡴⢋⣾⣿⣿⣿⣿⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",bro,gray);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⡹⣿⣿⣿⣿⣿⣆⠳%s⡿⠿⢛⢛⠻⠿⡿⢓%s⣴⣿⣿⣿⣿⡿⣫⠎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",bro,gray);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⡛⢿⣿⣿⣿⣷⣄%s⢻⣿⣿⣿⠗%s⣰⣾⣿⣿⣿⡟⣫⠞⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",bro,gray);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀%s⣟⢠%s⣝⢻⣿⣿⣿⣶%s⡙⠟%s⢅⣾⣿⣿⣿⠟%s⣡⡎⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",bro,gray,bro,gray,bro);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣯⢸⣿⡂⣌%s⠻⣿⡿⢋⣼⣿⣿⣿⠟%s⣥⠸⣿⣝⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",gray,bro);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡷⢸⣿⡂⣿⣷%s⠎⣴⣿⣿⡿⢛%s⠰⣿⣿⠸⣿⢧⡃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",gray,bro);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢟%s⠘⣩⣄%s⠛%s⣥⣾⣿⡿⠋⢴⣿⣷⣌%s⢛%s⣨⡙⢱%s⠅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",gray,bro,gray,bro,gray,bro);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣇%s⠄⡛⣷⣌⠻%s⣩⣾⣿⣦%s⣝⢛⣡⡾⢋⢂%s⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",gray,bro,gray,bro);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀%s⢀⡴⣣⣾⣷⠆⠻⢷⡈%s⢿⣿⠟%s⠡⡾⢋⢲⣿⣶⡹⢤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",gray,bro,gray);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢺⡰⢿⢟⡵%s⢢⣝⠄⣾⣶⣦⣾⡧⢸⣨%s⠦⣜⠿⡿⣪⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",bro,gray);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠒⠉⠀⠀%s⠈⠓⠲⠬⠭⠕⠚⠉⠀%s⠀⠈⠓⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",bro,gray);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀%s⠀\n",end);
    printf("⠀⠀⠀⠀%s⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",red);
    printf("⠀⠀⠀⠀⠘⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⢐⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠁⠉⠈⠉⠉⠉⠉⠙⢻⣿⣿⣷⠀⠀⠐⠶⣶⣶⣶⣶⠶⠖⠀⠶⢶⣶⣶⣶⣦⡄⠀⠀⠀⠀⠶⢶⣶⣶⣶⠶⠖⠀⠀⠀⢸⣿⣿⡇⠉⠈⠁⠉⠈⠁⠉⠉⠛⢿⣅⠀⠀⣾⡟⠋⠉⠉⠉⠈⠁⠉⣨⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⢐⣿⣿⣿⠂⠀⠀⠀⢘⣿⣿⣏⠀⠀⠀⠀⠈⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⣿⣿⣏⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⣴⠀⠀⠈⠳⠀⠘⠋⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣠⣀⣄⣠⣀⣄⣄⣤⣾⣿⣿⡟⠀⠀⠀⠀⢨⣿⣿⡧⠀⠀⠀⠀⠀⣿⣿⡇⠙⣿⣿⣷⡄⠀⠀⠀⣿⣿⣇⠀⠀⠀⠀⠀⢸⣿⣿⣧⣤⣤⣤⣤⣴⣴⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⢿⠿⡿⣿⣿⣿⣿⠿⠟⠛⠁⠀⠀⠀⠀⠀⠰⣿⣿⡗⠀⠀⠀⠀⠀⣿⣿⣇⠀⠈⠻⣿⣿⣦⡀⠀⣿⣿⣇⠀⠀⠀⠀⠀⢸⣿⣿⡿⠻⠻⠻⠻⠻⢿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠹⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⢘⣿⣿⣏⠀⠀⠀⠀⠀⣿⣿⡇⠀⠀⠀⠙⢿⣿⣷⣄⣿⣿⡇⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠻⠀⠀⠀⢀⣄⠀⠀⠀⢠⣼⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⣠⡀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠈⢻⣿⣿⣧⡀⠀⠀⠀⠀⠀⢨⣿⣿⡧⠀⠀⠀⠀⠀⣿⣿⡏⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⡗⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⢀⢤⣿⠃⠀⠀⣴⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⣀⣴⡿⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⢀⣀⣰⣿⣿⣿⣆⣀⡀⠀⠀⠀⣀⣹⣿⣿⣿⣦⣀⣀⠀⣀⣰⣿⣿⣯⣀⢀⠀⣀⣰⣿⣿⣯⣀⠀⠀⠀⠀⠀⡘⣿⣿⣿⣷⣀⠀⠀⣀⣀⣾⣿⣿⣿⣶⣶⣶⣶⣶⣶⣾⣾⣿⣿⠏⠀⣠⣾⣿⣿⣿⣷⣶⣶⣶⣶⣶⣾⣾⣿⡿⠁⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠈⠙⠉⠋⠙⠙⠙⠙⠁⠀⠀⠀⠋⠋⠋⠋⠙⠙⠙⠉⠈⠋⠋⠋⠋⠋⠋⠃⠀⠋⠉⠋⠙⠙⠙⠉⠀⠀⠀⠀⠋⠋⠉⠋⠙⠙⠉⠀⠙⠙⠙⠙⠙⠙⠙⠙⠙⠙⠙⠙⠙⠙⠙⠟⠀⠀⠉⠋⠙⠉⠉⠋⠙⠙⠙⠙⠙⠙⠙⠻⠃⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀%s⠀⠀⠀⠀\n",end);
    printf("╔═══════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                       ║\n");
    printf("║                                                                                       ║\n");
    printf("║                 ╔════════════════════════════════════════════════╗                    ║\n");
    printf("║                 ║             press enter to start               ║                    ║\n");
    printf("║                 ╚════════════════════════════════════════════════╝                    ║\n");
    printf("║                                                                                       ║\n");
    printf("║                                                                                       ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════════════╝\n");
    getch();
    system("clear");
    printf("═════════════════════════════════════════════════════════════════════════════════════════\n");
    enter(4);
    char *script = "\t우리의 주인공, 전설의 용사 복이는 바포메트를 \n\n\t처치해 달라는 의뢰를 받고 말하는섬에 도착한다.\n\n\t말하는섬에는 마을이 있었다.\n\n\t마을에는 판도라가 운영하는 \"💰잡화상\"이 있고\n\n\t체력회복을 시켜주는 \"⛲성소\"가 있으며\n\n\t무기 방어구 인첸트를 시켜주는 \"🔨제련소\"가 있다.\n\n\t말하는섬 마을에는 \"🐐바포메트\"가 있다는 말하는섬던전 입구가 있다.\n\n\t던전 각층에는 몬스터와 \"바포메트\"를 토벌하기위해\n\n\t경쟁적으로 참전하는 다른용사들도 많이있다.\n\n\t던전  최상층에는 \"🐻 이동녀크\"와\"👿 최상달\"이 존재한다.\n\n\t최상달로부터 말하는섬을 해방 시켜주자.";
    int length = strlen(script);
    for(int i=0; i<length; i++) 
    {
        printf("%c", script[i]);
        fflush(stdout); 
        usleep(17000); 
    }   
    enter(3);
    printf("╔═══════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                                                                       ║\n");
    printf("║                                                                                       ║\n");
    printf("║                 ╔════════════════════════════════════════════════╗                    ║\n");
    printf("║                 ║             press enter to start               ║                    ║\n");
    printf("║                 ╚════════════════════════════════════════════════╝                    ║\n");
    printf("║                                                                                       ║\n");
    printf("║                                                                                       ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════════════╝\n");
    getch();
}

