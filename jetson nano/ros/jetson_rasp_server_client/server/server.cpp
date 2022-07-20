#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>

#define BUF_SIZE 100
#define MAX_CLNT 2
#define ID_SIZE 10
#define ARR_CNT 5	//struct member count

typedef struct {
	int fd;			//soket info(file discruption)
	char ip[20];		//ip
	char id[ID_SIZE];	//id
	char pw[ID_SIZE];	//pw
}CLIENT_INFO;

typedef struct {
	int fd;
	char *from;
	char *to;
	char *msg;
	int len;
}MSG_INFO;

CLIENT_INFO  *first_client_info;

void *handle_clnt(void *arg);
void send_msg(MSG_INFO *msg_info);
void error_handling(const char *msg);

int clnt_cnt = 0;
pthread_mutex_t mutx;

int main(int argc, char *argv[])
{
	/*setting*/
	int serv_sock, clnt_sock;		//socket
	struct sockaddr_in serv_adr, clnt_adr;	//socket info
	socklen_t clnt_adr_sz;			//client ipadress
	pthread_t t_id[MAX_CLNT];		//client number
	int optvalue = 1;			//
	int str_len = 0;			//input string size
	char idpasswd[(ID_SIZE*2)+2];		//input id, password
	char *pToken;				//temp pasing data space
	char *pArray[ARR_CNT]={0};		//parsing data space(client info)
	char msg[BUF_SIZE];			//message size
	int i = 0;	//for

	CLIENT_INFO client_info[MAX_CLNT] =
		{{-1,"","jetson","jetson"}, {-1,"","rasp","rasp"}};

	first_client_info = &client_info[0];

	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	if(pthread_mutex_init(&mutx, NULL))
		error_handling("mutex init error");

	serv_sock=socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET; 
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &optvalue, sizeof(optvalue));


	if(bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr)) == -1)
		error_handling("bind() error");
	if(listen(serv_sock, 5) == -1)
		error_handling("listen() error");
	fputs("server start\n", stdout);
	
	while(1)
	{
		clnt_adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);
		if(clnt_cnt >= MAX_CLNT){
			fputs("socket full\n", stdout);
			sprintf(msg, "[%s] Socket full!\n", pArray[0]);
			write(clnt_sock, msg,strlen(msg));
			shutdown(clnt_sock,SHUT_WR);
			continue;
		}
		else if(clnt_sock < 0){
			perror("accept()");
			continue;
		}
		else{
			sprintf(msg, "[%s] Tring login...\n", pArray[0]);
			write(clnt_sock, msg, strlen(msg));
		}

		/*longin*/
		str_len = read(clnt_sock, idpasswd, sizeof(idpasswd));
		idpasswd[str_len] = 0;
		fputs(idpasswd, stdout);

		if(str_len > 0){
			i = 0;
			pToken = strtok(idpasswd, ":");

			while(pToken != NULL){
				pArray[i] = pToken;
				if(i++ >= ARR_CNT) break;
				pToken = strtok(NULL, ":");
			}

			sprintf(msg, "[%s] compare id...\n", pArray[0]);
			write(clnt_sock, msg,strlen(msg));
			fputs(msg, stdout);

			for(i = 0; i < MAX_CLNT; i++){
				if(!strcmp(client_info[i].id,pArray[0])){	//compare id
					if(client_info[i].fd != -1){		//compare connection id
						sprintf(msg, "[%s] Already logged!\n", pArray[0]);
						write(clnt_sock, msg, strlen(msg));
						shutdown(clnt_sock, SHUT_WR);
						break;
					}

					sprintf(msg, "[%s] compare pw...\n", pArray[0]);
					write(clnt_sock, msg,strlen(msg));
					fputs(msg, stdout);

					if(!strcmp(client_info[i].pw, pArray[1])){	//compare password
						strcpy(client_info[i].ip, inet_ntoa(clnt_adr.sin_addr));
						pthread_mutex_lock(&mutx);	//connection edit
						client_info[i].fd = clnt_sock;
						clnt_cnt++;
						pthread_mutex_unlock(&mutx);

						sprintf(msg, "[%s] New connected! (ip:%s,fd:%d,sockcnt:%d)\n", 
								pArray[0], inet_ntoa(clnt_adr.sin_addr), clnt_sock, clnt_cnt);
						write(clnt_sock, msg, strlen(msg));
						fputs(msg, stdout);
						pthread_create(t_id + i, NULL, handle_clnt, (void *)(client_info + i));
						pthread_detach(*(t_id+i));
						break;
					}
				}
			}
		}
		else{
//			sprintf(msg,"Login fail!\n");
//			write(clnt_sock, msg, strlen(msg));
			shutdown(clnt_sock, SHUT_WR);
		}
	}
	shutdown(clnt_sock, SHUT_WR);

	return 0;
}

void *handle_clnt(void *arg)
{
	CLIENT_INFO *client_info = (CLIENT_INFO *)arg;
	int str_len = 0;
	char msg[BUF_SIZE];
	char to_msg[MAX_CLNT*ID_SIZE+1];
	int i;
	char *pToken;
	char *pArray[ARR_CNT]={0};
	char strBuff[100]={0};

	MSG_INFO msg_info;

	while(1){
		memset(msg, 0, sizeof(msg));
		str_len = read(client_info->fd, msg, sizeof(msg) - 1); 
		if(str_len <= 0) break;

		msg[str_len] = 0;
		pToken = strtok(msg,"[:]");
		i = 0; 

		while(pToken != NULL){
			pArray[i] = pToken;
			if(i++ >= ARR_CNT) break;	
			pToken = strtok(NULL, "[:]");
		}

		msg_info.fd = client_info->fd;
		msg_info.from = client_info->id;
		msg_info.to = pArray[0];
		sprintf(to_msg,"[%s] %s", msg_info.from,pArray[1]);
		msg_info.msg = to_msg;
		msg_info.len = strlen(to_msg);

		sprintf(strBuff, "msg : [%s->%s] %s", msg_info.from, msg_info.to, pArray[1]);
		send_msg(&msg_info);
		fputs(strBuff, stdout);
	}

	close(client_info->fd);

	sprintf(strBuff, "Disconnect ID:%s (ip:%s,fd:%d,sockcnt:%d)\n", client_info->id,client_info->ip, client_info->fd, clnt_cnt-1);
	fputs(strBuff, stdout);

	pthread_mutex_lock(&mutx);
	clnt_cnt--;
	client_info->fd = -1;
	pthread_mutex_unlock(&mutx);

	return 0;
}

void send_msg(MSG_INFO *msg_info)
{
	int i = 0;

	if(!strcmp(msg_info->to, "ALLMSG")){	
		char strBuff[20];
		for(i=0; i<MAX_CLNT; i++){
			if(msg_info->fd == (first_client_info+i)->fd) continue;
			if((first_client_info+i)->fd != -1)	
				write((first_client_info+i)->fd, msg_info->msg, msg_info->len);
		}
	}
	else if(!strcmp(msg_info->to, "IDLIST")){
		char* idlist = (char *)malloc(ID_SIZE * MAX_CLNT);
		msg_info->msg[strlen(msg_info->msg) - 1] = '\0';
		strcpy(idlist, msg_info->msg);

		for(i=0; i<MAX_CLNT; i++){
			if((first_client_info+i)->fd != -1)	
			{
				strcat(idlist,(first_client_info + i)->id);
				strcat(idlist," ");
			}
		}
		strcat(idlist,"\n");
		write(msg_info->fd, idlist, strlen(idlist));
		free(idlist);
	}
	else
		for(i=0; i<MAX_CLNT; i++)
			if((first_client_info+i)->fd != -1)	
				if(!strcmp(msg_info->to,(first_client_info+i)->id))
					write((first_client_info+i)->fd, msg_info->msg, msg_info->len);
}

void error_handling(const char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}