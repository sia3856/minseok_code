#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[20];
    char password[20];
} User;

int main()
{
    int cnt;

    while (1)
    {
        printf("1. 회원가입\n");
        printf("2. 로그인\n");
        printf("3. 종료\n");
        printf("선택: ");
        scanf("%d", &cnt);

        if (cnt == 1)
        {
            FILE *fp = fopen("test.txt", "a");  // test파일을 열고 없으면 생성 
            if (fp == NULL)
            {
                printf("파일을 열 수 없습니다.\n");
                continue;
            }

            User newUser; // 유저구조체를  잉ㅛㅇ아하는 뉴유저 변수 생성
            printf("회원가입 - ID 입력: ");
            scanf("%s", newUser.id);
            printf("회원가입 - 비밀번호 입력: ");
            scanf("%s", newUser.password);

            fwrite(&newUser, sizeof(User), 1, fp);       //  위에 입력받은걸 입력ㄹ
            fclose(fp);  // 파일닫기
            printf("회원가입 완료!\n");
        }
        else if (cnt == 2)
        {
            FILE *fp = fopen("test.txt", "r");   //  test 파일을 읽기모드로 실행
            if (fp == NULL)
            {
                printf("파일을 열 수 없습니다.\n");
                continue;
                ;
            }

            char inputId[20];
            char inputPw[20];

            printf("로그인 - ID 입력: ");
            scanf("%s", inputId);
            printf("로그인 - 비밀번호 입력: ");
            scanf("%s", inputPw);

            User user;
            while (fread(&user, sizeof(User), 1, fp))   //  파일을 읽는동안~~~
            {
                if (strcmp(user.id, inputId) == 0 && strcmp(user.password, inputPw) == 0)    //  구조체 아이디 비버ㄴ 비교
                {
                    fclose(fp);
                    printf("로그인 성공\n");
                    break;
                }               
            }

            fclose(fp);
            printf("로그인 실패 - 틀렸습니다.\n");
            continue;
        }
        else if (cnt == 3)
        {
            printf("프로그램 종료\n");
            break;
        }
        else
        {
            printf("잘못된 선택입니다.\n");
        }
    }
    printf("끄트트트ㅡ");
    return 0;
}