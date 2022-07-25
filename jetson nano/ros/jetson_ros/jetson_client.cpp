#include "ros/ros.h"
#include "std_msgs/String.h"

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Empty.h"
#include <sstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;

#define BUF_SIZE 100
#define NAME_SIZE 20

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT "5555"

void* send_msg(void* arg);
void* recv_msg(void* arg);
void error_handling(const char* msg);

void mega_callback(const std_msgs::String &input);
void uno_callback(const std_msgs::String &input);
void user_callback(const std_msgs::String &input);
void Split(std_msgs::String sData, char cSeparator);

char name[NAME_SIZE] = "[1]";
char msg[BUF_SIZE];

class ros_server_topic{
public:
	ros_server_topic(){	mega_pub = n.advertise<std_msgs::String>("/mega_to", 100); }

	void mega_callback(const std_msgs::String &input) {
		mega_pub.publish(input);
	}

	ros::NodeHandle n;
	ros::Publisher mega_pub;
};

int main(int argc, char* argv[]) {

	int sock;
	struct sockaddr_in serv_addr;
	pthread_t snd_thread, rcv_thread;
	void* thread_return;
	char id[10] = "jetson", pw[10] = "jetson";

	ros::init(argc, argv, "topic");
	ros_server_topic ROSProject;

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1) error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(atoi(SERVER_PORT));

	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");
	
/*	fputs("input : id\ninput : ", stdout);
	cin >> id;
	fputs("input : id\ninput : ", stdout);
	cin >> pw;
*/
	sprintf(msg, "%s:%s", id, pw);
	write(sock, msg, strlen(msg));
	fputs(msg, stdout);

	pthread_create(&snd_thread, NULL, send_msg, (void*)&sock);
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&sock);
	ros::spin();
	pthread_detach(rcv_thread);
	pthread_join(snd_thread, &thread_return);
	
	
	close(sock);
	return 0;
}

void *send_msg(void *arg)
{
	int *sock = (int *)arg;
	int str_len;
	int ret;
	fd_set initset, newset;
	struct timeval tv;
	char name_msg[NAME_SIZE + BUF_SIZE+2];

	FD_ZERO(&initset);
	FD_SET(STDIN_FILENO, &initset);

	fputs("Input a message! [ID]msg (Default ID:ALLMSG)\n",stdout);
	while(1) {
		memset(msg,0,sizeof(msg));
		name_msg[0] = '\0';
		tv.tv_sec = 1;
		tv.tv_usec = 0;
		newset = initset;
		ret = select(STDIN_FILENO + 1, &newset, NULL, NULL, &tv);
		if(FD_ISSET(STDIN_FILENO, &newset))
		{
			fgets(msg, BUF_SIZE, stdin);
			if(!strncmp(msg,"quit\n", 5)) {
				*sock = -1;
				return NULL;
			}
			else if(msg[0] != '[')
			{
				strcat(name_msg,"[ALLMSG]");
				strcat(name_msg,msg);
			}
			else
				strcpy(name_msg,msg);
			if(write(*sock, name_msg, strlen(name_msg))<=0)
			{
				*sock = -1;
				return NULL;
			}
		}
		if(ret == 0) 
		{
			if(*sock == -1) 
				return NULL;
		}
	}
}



void* recv_msg(void* arg) {
	int *sock = (int *)arg;
	char recv_data[NAME_SIZE+BUF_SIZE];
	int str_len;

	std_msgs::String send_message;
	string comp = "move";
	ros_server_topic ROSProject;
	string tempSt;
	int result = 0;
	size_t pos;
	string temp;

	//recv data
	while(1) {
		memset(recv_data, 0, sizeof(recv_data));
		str_len = read(*sock, recv_data, NAME_SIZE + BUF_SIZE);
		if(str_len > 0){
			recv_data[str_len] = 0;
			fputs(recv_data, stdout);
			tempSt = recv_data;

			pos = tempSt.find(']');
			temp = tempSt.substr(pos+2, 4);
			temp[4] = 0;
			result = temp.compare(comp);

			cout << "temp : " << temp << endl;
			cout << "result : " << result << endl;
		
			if(result == 0) {
				temp = tempSt.substr(pos + 2);
				cout << "send_data : " << temp << endl;
				send_message.data = temp;
				ROSProject.mega_callback(send_message);
				cout << "send topic \n";
			}
			cout << temp << endl;
		}
	}
	return NULL;
}

void error_handling(const char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}