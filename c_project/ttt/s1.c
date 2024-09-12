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
void send_msg(char *msg, int len, int ucnt);
void error_handling(char *msg);

#define yellow	"\033[38;2;255;255;0m"
#define end	"\033[0m"

int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
pthread_mutex_t mutx;

typedef struct user
{
	int sta;
	char id[20];
	char password[20];
	char phone[20];
	char nick[20];
	int sok;
	int rsok;
} User;

User u_list[10] = {{0,"siasia","siasia","010-0000-0000","시아"},{0,"kim123","1234","010-1111-1111","kim"},{0,"k123","1234","010-1111-1111","cha"}};

int r_cnt = 3;

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
	char intro[] = "1.회원가입 2.로그인 3.아이디 찾기 4.비밀번호찾기 5.회원탈퇴\n";
	char inid[] = "아이디를 입력하시오.\n";
	char o_f[] = "파일을 열 수 없습니다.\n";
	char r_i[] = "회원가입 - ID 입력: \n";
	char r_p[] = "회원가입 - 비밀번호 입력: \n";
	char r_e[] = "회원가입 완료!\n";
	int login_success = 0;
	int id_st = 0;
	char result[20];
	int j= 0;
	int jcnt = 0;
	int ucnt = 0;
	char wel[200];

	while (1)
	{
		char i_id[20], i_pw[20], i_pn[20], i_nk[20];
		char cnt[BUF_SIZE] = "0";
		j = 0;
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
			memset(i_id,0,sizeof(i_id));
			memset(i_pw,0,sizeof(i_pw));
			memset(i_pn,0,sizeof(i_pn));
			memset(i_pn,0,sizeof(i_nk));
			write(clnt_sock, r_i, strlen(r_i));
			read(clnt_sock, i_id, sizeof(i_id));
			i_id[strlen(i_id) - 1] = '\0';
			printf("%s\n",i_id);
			strcpy(u_list[r_cnt].id, i_id);
			id_st = 0;
			//pthread_mutex_lock(&mutx);

			for(j = 0; j<r_cnt; j++)
			{
				if(strcmp(u_list[j].id, i_id) == 0)
				{
					write(clnt_sock, "아이디가 중복됩니다.\n", strlen("아이디가 중복됩니다.\n"));
					id_st = 1;
					break;
				}
			}
			//pthread_mutex_unlock(&mutx);

			if(id_st == 1)
			{
				continue;
			}

			write(clnt_sock, r_p, strlen(r_p));
			read(clnt_sock, i_pw, sizeof(i_pw));
			i_pw[strlen(i_pw) - 1] = '\0';
			printf("%s\n",i_pw);
			strcpy(u_list[r_cnt].password, i_pw);

			write(clnt_sock, "전화번호를 입력하시오. (-포함)\n", strlen("전화번호를 입력하시오. (-포함)\n"));
			read(clnt_sock, i_pn, sizeof(i_pn));
			i_pn[strlen(i_pn) - 1] = '\0';
			printf("%s\n",i_pn);
			strcpy(u_list[r_cnt].phone, i_pn);

			write(clnt_sock, "사용할 닉네임을 입력하시오.\n", strlen("사용할 닉네임을 입력하시오.\n"));
			read(clnt_sock, i_nk, sizeof(i_nk));
			i_pn[strlen(i_nk) - 1] = '\0';
			printf("%s\n",i_nk);
			strcpy(u_list[r_cnt].nick, i_pn);

			write(clnt_sock, r_e, strlen(r_e));
			
			u_list[r_cnt].sta = 0;
			r_cnt++;

		}
		else if (strcmp(cnt, "2") == 0)
		{
			char in_id[20];
			char in_pw[20];
			memset(in_id,0,sizeof(in_id));
			memset(in_pw,0,sizeof(in_pw));

			write(clnt_sock, "로그인 - ID 입력: \n", strlen("로그인 - ID 입력: \n"));
			read(clnt_sock, in_id, sizeof(in_id));
			printf("%s\n",in_id);
			in_id[strlen(in_id) - 1] = '\0';

			write(clnt_sock, "로그인 - 비밀번호 입력: \n", strlen("로그인 - 비밀번호 입력: \n"));
			read(clnt_sock, in_pw, sizeof(in_pw));
			printf("%s\n",in_pw);
			in_pw[strlen(in_pw) - 1] = '\0';

			//pthread_mutex_lock(&mutx);
			for (jcnt = 0; jcnt < r_cnt; jcnt++)
			{		
				if (strcmp(u_list[jcnt].id, in_id) == 0 && strcmp(u_list[jcnt].password, in_pw) == 0)// && u_list[j].sta != 2
				{
					send(clnt_sock, "로그인 성공\n", strlen("로그인 성공\n"),0);
					sprintf(wel,"%s님 오신걸 환영합니다.\n", u_list[jcnt].nick);
					write(clnt_sock,wel,strlen(wel));
					memset(wel,0,sizeof(wel));					
					login_success = 1; 					
					u_list[jcnt].sta = 2;	
					u_list[jcnt].sok = jcnt;
					u_list[jcnt].rsok = clnt_sock;				
                    break;
				}
				
			}
			//pthread_mutex_unlock(&mutx);
			if (!login_success)  // 로그인 실패 시 처리
            {
                write(clnt_sock, "로그인 실패 - 틀렸습니다.\n", strlen("로그인 실패 - 틀렸습니다.\n"));				
				continue;
            }
			
		}
		else if (strcmp(cnt, "3") == 0)
		{
			write(clnt_sock, "전화번호를 입력하시오.\n", strlen("전화번호를 입력하시오.\n"));
			read(clnt_sock, i_pn, sizeof(i_pn));
			i_pn[strlen(i_pn) - 1] = '\0';
			int p_st;
			for(j = 0; j<r_cnt; j++)
			{
				p_st = 0;
				if(strcmp(u_list[j].phone, i_pn) == 0)
				{
					write(clnt_sock, "아이디는 ", strlen("아이디는 "));
					strcpy(result, u_list[j].id);
					strcat(result, " 입니다.\n");
					write(clnt_sock, result,strlen(result));
					u_list[j].sta = 0;
					p_st = 1;
					memset(i_pn,0,sizeof(i_pn));
					break;
				}		
			}
			
			if (p_st == 1)
				{
					printf("%s\n",u_list[j].id);
					continue;
				}
			write(clnt_sock, "없는 전화번호입니다.\n", strlen("없는 전화번호입니다.\n"));
		}
		else if (strcmp(cnt, "4") == 0)
		{
			memset(i_id,0,sizeof(i_id));
			memset(i_pn,0,sizeof(i_pn));
			int f_st = 0;
			int f_id = 0;
			write(clnt_sock, "비밀번호를 찾을 '아이디'를 입력하시오.\n", strlen("비밀번호를 찾을 '아이디'를 입력하시오.\n"));
			read(clnt_sock, i_id, sizeof(i_id));
			i_id[strlen(i_id) - 1] = '\0';
			
			for(j = 0; j<r_cnt; j++)
			{
				if(strcmp(u_list[j].id, i_id) != 0)
				{
					write(clnt_sock, "존재하지 않는 아이디입니다.\n", strlen("존재하지 않는 아이디입니다.\n"));
					f_st = 1;
					break;
				}
				else if(strcmp(u_list[j].id, i_id) == 0)
				{
					f_id = j;
					break;
				}
			}
			if (f_st == 1)
			{
				continue;
			}
			write(clnt_sock, "전화번호를 입력하시오.\n", strlen("전화번호를 입력하시오.\n"));
			read(clnt_sock, i_pn, sizeof(i_pn));
			i_pn[strlen(i_pn) - 1] = '\0';

			if(strcmp(u_list[f_id].phone, i_pn)!=0)
			{
				write(clnt_sock, "전화번호가 일치하지 않습니다.\n", strlen("전화번호가 일치하지 않습니다.\n"));
				f_st = 1;
			}
			if (f_st == 1)
			{
				continue;
			}
			write(clnt_sock, "비밀번호는 ", strlen("비밀번호는 "));
			strcpy(result, u_list[f_id].password);
			strcat(result, " 입니다.\n");
			write(clnt_sock, result,strlen(result));
			u_list[f_id].sta = 0;
			continue;		
			
		}
		else
        {
            continue;
        }
	}
	
	int rlen;
	char rmsg[BUF_SIZE];
	char *nick;
	char *mynick;
	int sokkkk;
	char jrmsg[200];
	if(u_list[jcnt].sta == 2)
	{
		ucnt = u_list[jcnt].sok;
		while ((str_len = read(clnt_sock, msg, sizeof(msg))) != 0)
		{	
			if(strncmp(msg,"/w",2) == 0)  //귓속말
			{
				mynick = strtok(msg, " ");
				nick = strtok(NULL, " ");
				printf("%s\n",nick);
				char *jin_msg = strtok(NULL,"\n");
				printf("%s\n",jin_msg);
				//strcat(jin_msg,"\n");
				sprintf(jrmsg,"%s%s <%s> %s%s\n" ,yellow,"귓속말", u_list[jcnt].nick, jin_msg,end);
				for(i = 0; i< r_cnt; i++)
				{
					if(strcmp(u_list[i].nick,nick)==0 )
					{
						sokkkk = i;
						break;
					}
				}
				printf("%d\n",u_list[sokkkk].rsok);
				printf("%s\n",u_list[sokkkk].nick);
				write(u_list[sokkkk].rsok, jrmsg,sizeof(jrmsg));
				printf("\n");
				memset(jin_msg,0,sizeof(jin_msg));
				memset(jrmsg,0,sizeof(jrmsg));
			}
			else
			{	
				send_msg(msg, str_len, ucnt); // 전체 메시지 
			}
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


void send_msg(char *msg, int len, int ucnt) // send to all
{
	int i;
	char rmsg[1000];
	int rlen;
	pthread_mutex_lock(&mutx);
	memset(rmsg,0,sizeof(rmsg));
	rlen = 0;
	msg[strlen(msg) - 1] = '\0';
	sprintf(rmsg,"%s>%s\n",u_list[ucnt].nick,msg);
	printf("%s\n",rmsg);

	for (i = 0; i < clnt_cnt; i++)
	{
		if(u_list[i].sta == 2)
		{
			write(clnt_socks[i], rmsg, strlen(rmsg));			
			memset(msg,0,sizeof(msg));
			len = 0;
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