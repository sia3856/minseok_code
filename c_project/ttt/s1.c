#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUF_SIZE 100
#define MAX_CLNT 256

void *handle_clnt(void *arg);
void send_msg(char *msg, int len);
void error_handling(char *msg);

int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
pthread_mutex_t mutx;

typedef struct user
{
	int sta;
	char id[20];
	char password[20];
} User;

User u_list[10] = {{0,"siasia","siasia"},{0,"kim123","1234"}};

int r_cnt = 2;

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	int clnt_adr_sz;
	pthread_t t_id;
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

		pthread_mutex_lock(&mutx);
		clnt_socks[clnt_cnt++] = clnt_sock;
		pthread_mutex_unlock(&mutx);

		pthread_create(&t_id, NULL, handle_clnt, (void *)&clnt_sock);
		pthread_detach(t_id);
		printf("Connected client IP: %s \n", inet_ntoa(clnt_adr.sin_addr));
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
	int id_st = 0;

	while (login_success == 0)
	{
		char i_id[20], i_pw[20];
		char cnt[BUF_SIZE] = "0";
		int j = 0;
		if (login_success == 1)
		{
			break;
		}
		write(clnt_sock, intro, strlen(intro));
		read(clnt_sock, cnt, sizeof(cnt));
		cnt[strlen(cnt) - 1] = '\0';
		printf("%s", cnt);
		if (strcmp(cnt, "1") == 0)
		{
			write(clnt_sock, r_i, strlen(r_i));
			read(clnt_sock, i_id, sizeof(i_id));
			i_id[strlen(i_id) - 1] = '\0';
			strcpy(u_list[r_cnt].id, i_id);
			id_st = 0;
			pthread_mutex_lock(&mutx);
			for(j = 0; j<r_cnt; j++)
			{
				if(strcmp(u_list[j].id, i_id) == 0)
				{
					write(clnt_sock, "아이디가 중복됩니다.\n", strlen("아이디가 중복됩니다.\n"));
					fsync(clnt_sock);
					id_st = 1;
					break;
				}
			}
			pthread_mutex_unlock(&mutx);

			if(id_st == 1)
			{
				continue;
			}

			write(clnt_sock, r_p, strlen(r_p));
			read(clnt_sock, i_pw, sizeof(i_pw));
			i_pw[strlen(i_pw) - 1] = '\0';
			strcpy(u_list[r_cnt].password, i_pw);
			write(clnt_sock, r_e, strlen(r_e));
			fsync(clnt_sock);
			u_list[r_cnt].sta = 0;
			pthread_mutex_lock(&mutx);
			r_cnt++;
			pthread_mutex_unlock(&mutx);
		}
		else if (strcmp(cnt, "2") == 0)
		{
			char in_id[20];
			char in_pw[20];
			write(clnt_sock, "로그인 - ID 입력: \n", strlen("로그인 - ID 입력: \n"));
			read(clnt_sock, in_id, sizeof(in_id));
			in_id[strlen(in_id) - 1] = '\0';

			write(clnt_sock, "로그인 - 비밀번호 입력: \n", strlen("로그인 - 비밀번호 입력: \n"));
			read(clnt_sock, in_pw, sizeof(in_pw));
			in_pw[strlen(in_pw) - 1] = '\0';
			//pthread_mutex_lock(&mutx);
			for (j = 0; j < r_cnt; j++)
			{		
				if (strcmp(u_list[j].id, in_id) == 0 && strcmp(u_list[j].password, in_pw) == 0)
				{
					send(clnt_sock, "로그인 성공\n", strlen("로그인 성공\n"),0);
					fsync(clnt_sock);
					login_success = 1; 					
					u_list[j].sta = 2;
                    break;
				}
				
			}
			//pthread_mutex_unlock(&mutx);
			if (!login_success)  // 로그인 실패 시 처리
            {

                write(clnt_sock, "로그인 실패 - 틀렸습니다.\n", strlen("로그인 실패 - 틀렸습니다.\n"));
                fsync(clnt_sock);
				continue;
            }
			
		}
		else
        {
            continue;
        }
	}

	while ((str_len = read(clnt_sock, msg, sizeof(msg))) != 0)
		send_msg(msg, str_len);

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


void send_msg(char *msg, int len) // send to all
{
	int i;
	pthread_mutex_lock(&mutx);
	for (i = 0; i < clnt_cnt; i++)
	{
		if(u_list[i].sta == 2)
		{
			write(clnt_socks[i], msg, len);
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