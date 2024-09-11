#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <fcntl.h>
int r_cnt = 0;

#define BUF_SIZE 100
#define MAX_CLNT 256

void *handle_clnt(void *arg);
void send_msg(char *msg, int len, int r_cnt,void *arg);
void error_handling(char *msg);
//void *login(void *arg);


typedef struct
{
	int sta;
	char id[20];
	char password[20];
} User;

User u_list[10] = { };


int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];


pthread_mutex_t mutx;

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	int clnt_adr_sz;	
	pthread_t t_id ,l_id;
    
	if (argc != 2)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	pthread_mutex_init(&mutx, NULL);
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	if (bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
		error_handling("bind() error");
	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	while (1)
	{
		clnt_adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);
        //pthread_create(&l_id, NULL, login, (void *)&clnt_sock);
        //pthread_join(l_id, NULL);
		//pthread_detach(l_id);

		pthread_mutex_lock(&mutx);
		clnt_socks[clnt_cnt++] = clnt_sock;
		pthread_mutex_unlock(&mutx);

		pthread_create(&t_id, NULL, handle_clnt, (void *)&clnt_sock);
		pthread_detach(t_id);
		printf("Connected client IP: %s \n", inet_ntoa(clnt_adr.sin_addr));
		char *wel = "채팅방에 오신걸 환영합니다.\n";
		write(clnt_sock, wel, strlen(wel));
		read(clnt_sock, 0, 0);
	}
	close(serv_sock);
	return 0;
}

void *handle_clnt(void *arg)
{
	int clnt_sock = *((int *)arg);
	int str_len = 0, i;
	char msg[BUF_SIZE];
	char intro[] = "1.회원가입 2.로그인\n입력 : \n";
	char inid[] = "아이디를 입력하시오.\n";
	char o_f[] = "파일을 열 수 없습니다.\n";
	char r_i[] = "회원가입 - ID 입력: \n";
	char r_p[] = "회원가입 - 비밀번호 입력: \n";
	char r_e[] = "회원가입 완료!\n";
    int login_success = 0;

	while (login_success == 0)
	{
        char cnt[BUF_SIZE] = "0";
        if(login_success == 1)
        {
            break;
        }
		write(clnt_sock, intro, strlen(intro));
		read(clnt_sock, cnt, sizeof(cnt));
		cnt[strlen(cnt) - 1] = '\0';
        printf("%s",cnt);
		r_cnt = 0;
		if (strcmp(cnt, "1") == 0)
		{
			
			FILE *fp = fopen("user.txt", "a"); // test파일을 열고 없으면 생성
			if (fp == NULL)
			{
				write(clnt_sock, o_f, strlen(o_f));				
				continue;
			}		 
			User newUser;

			write(clnt_sock, r_i, strlen(r_i));
			read(clnt_sock, newUser.id, sizeof(newUser.id));
			newUser.id[strlen(newUser.id)-1] = '\0';

			write(clnt_sock, r_p, strlen(r_p));
			read(clnt_sock, newUser.password, sizeof(newUser.password));
			newUser.password[strlen(newUser.password)-1] = '\0';

			fwrite(&newUser, sizeof(User), 1, fp); //  위에 입력받은걸 입력ㄹ
			fclose(fp);							   // 파일닫기
			send(clnt_sock, r_e, strlen(r_e),MSG_DONTWAIT);  // 요기랑 
			//read(clnt_sock, cnt, sizeof(cnt));
			continue;
			
		}
		else if (strcmp(cnt, "2") == 0)
		{
			FILE *fp = fopen("user.txt", "r");   //  test 파일을 읽기모드로 실행
            if (fp == NULL)
            {
                write(clnt_sock, o_f, strlen(o_f));
                continue;
                ;
            }

            char in_id[20];
            char in_pw[20];

			write(clnt_sock,"로그인 - ID 입력: \n",strlen("로그인 - ID 입력: \n"));
			read(clnt_sock, in_id, sizeof(in_id));
			in_id[strlen(in_id)-1] = '\0';
			printf("%s\n",in_id);

			write(clnt_sock,"로그인 - 비밀번호 입력: \n",strlen("로그인 - 비밀번호 입력: \n"));
			read(clnt_sock, in_pw, sizeof(in_pw));
			in_pw[strlen(in_pw)-1] = '\0';
			printf("%s\n",in_pw);

			User user;
            
            while (fread(&user, sizeof(User), 1, fp))   //  파일을 읽는동안~~~
            {
                pthread_mutex_lock(&mutx);
				r_cnt ++;
				pthread_mutex_unlock(&mutx);
				if (strcmp(user.id, in_id) == 0 && strcmp(user.password, in_pw) == 0)    //  구조체 아이디 비버ㄴ 비교
                {
                    fclose(fp);
                    send(clnt_sock, "로그인 성공\n", strlen("로그인 성공\n"),0);  
					read(clnt_sock, cnt, sizeof(cnt));
					printf("%d\n",r_cnt);
					u_list[r_cnt].num = 2;

                    login_success = 1;             
                    break;                    
                }               
            }
            if (!login_success)  // 로그인 실패 시 처리
            {
                fclose(fp);
                write(clnt_sock, "로그인 실패 - 틀렸습니다.\n", strlen("로그인 실패 - 틀렸습니다.\n"));
                read(clnt_sock, cnt, sizeof(cnt));
            }
        }
        else
        {
            continue;
        }
    }	
	
	if(login_success == 1){
	while ((str_len = read(clnt_sock, msg, sizeof(msg))) != 0)
	{
		send_msg(msg, str_len, r_cnt, arg);
	}
	}

	pthread_mutex_lock(&mutx);
	for (i = 0; i < clnt_cnt; i++) // remove disconnected client
	{
		if (clnt_sock == clnt_socks[i])
		{
			while (i++ < clnt_cnt - 1)
				clnt_socks[i] = clnt_socks[i + 1];
			break;
		}
	}
	clnt_cnt--;
	pthread_mutex_unlock(&mutx);
	close(clnt_sock);
	return NULL;
}

void send_msg(char *msg, int len, int r_cnt, void *arg) // send to all
{
	int i;
	pthread_mutex_lock(&mutx);
	int clnt_sock = *((int *)arg);
	for (i = 0; i < clnt_cnt; i++)
	{
		if(u_list[r_cnt].num == 2)
		{
			write(clnt_socks[i], msg, len);
			printf("%d\n",u_list[r_cnt].num);
			printf("%d\n",r_cnt);
			printf("%d\n", clnt_sock);
			printf("%d\n",clnt_cnt);
		}
	}


		
	pthread_mutex_unlock(&mutx);
}

void error_handling(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

//void *login(void *arg)
//{
//
//	int clnt_sock = *((int *)arg);
//    int flags = fcntl(clnt_sock, F_GETFL, 0);
//	char intro[] = "1.회원가입 2.로그인\n입력 : \n";
//	char inid[] = "아이디를 입력하시오.\n";
//	char o_f[] = "파일을 열 수 없습니다.\n";
//	char r_i[] = "회원가입 - ID 입력: \n";
//	char r_p[] = "회원가입 - 비밀번호 입력: \n";
//	char r_e[] = "회원가입 완료!\n";
//    int login_success = 0;
//
//	while (1)
//	{
//        char cnt[BUF_SIZE] = "0";
//        if(login_success == 1)
//        {
//            break;
//        }
//		write(clnt_sock, intro, strlen(intro));
//		read(clnt_sock, cnt, sizeof(cnt));
//		cnt[strlen(cnt) - 1] = '\0';
//        printf("%s",cnt);
//		if (strcmp(cnt, "1") == 0)
//		{
//			
//			FILE *fp = fopen("user.txt", "a"); // test파일을 열고 없으면 생성
//			if (fp == NULL)
//			{
//				write(clnt_sock, o_f, strlen(o_f));				
//				continue;
//			}		 
//			User newUser;
//
//			write(clnt_sock, r_i, strlen(r_i));
//			read(clnt_sock, newUser.id, sizeof(newUser.id));
//			newUser.id[strlen(newUser.id)-1] = '\0';
//
//			write(clnt_sock, r_p, strlen(r_p));
//			read(clnt_sock, newUser.password, sizeof(newUser.password));
//			newUser.password[strlen(newUser.password)-1] = '\0';
//
//			fwrite(&newUser, sizeof(User), 1, fp); //  위에 입력받은걸 입력ㄹ
//			fclose(fp);							   // 파일닫기
//			send(clnt_sock, r_e, strlen(r_e),MSG_DONTWAIT);  // 요기랑 
//			//read(clnt_sock, cnt, sizeof(cnt));
//			continue;
//			
//		}
//		else if (strcmp(cnt, "2") == 0)
//		{
//			FILE *fp = fopen("user.txt", "r");   //  test 파일을 읽기모드로 실행
//            if (fp == NULL)
//            {
//                write(clnt_sock, o_f, strlen(o_f));
//                continue;
//                ;
//            }
//
//            char in_id[20];
//            char in_pw[20];
//
//			write(clnt_sock,"로그인 - ID 입력: \n",strlen("로그인 - ID 입력: \n"));
//			read(clnt_sock, in_id, sizeof(in_id));
//			in_id[strlen(in_id)-1] = '\0';
//			printf("%s\n",in_id);
//
//			write(clnt_sock,"로그인 - 비밀번호 입력: \n",strlen("로그인 - 비밀번호 입력: \n"));
//			read(clnt_sock, in_pw, sizeof(in_pw));
//			in_pw[strlen(in_pw)-1] = '\0';
//			printf("%s",in_pw);
//
//			User user;
//            
//            while (fread(&user, sizeof(User), 1, fp))   //  파일을 읽는동안~~~
//            {
//                if (strcmp(user.id, in_id) == 0 && strcmp(user.password, in_pw) == 0)    //  구조체 아이디 비버ㄴ 비교
//                {
//                    fclose(fp);
//                    send(clnt_sock, "로그인 성공\n", strlen("로그인 성공\n"),0);   // 요기 
//					read(clnt_sock, cnt, sizeof(cnt));
//                    login_success = 1;             
//                    break;                    
//                }               
//            }
//            if (!login_success)  // 로그인 실패 시 처리
//            {
//                fclose(fp);
//                write(clnt_sock, "로그인 실패 - 틀렸습니다.\n", strlen("로그인 실패 - 틀렸습니다.\n"));
//                read(clnt_sock, cnt, sizeof(cnt));
//            }
//        }
//        else
//        {
//            continue;
//        }
//    }
//}//