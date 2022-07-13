#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Empty.h"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;

#define BUF_SIZE 100
#define NAME_SIZE 20

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT "5040"

void* send_msg(void* arg);
void* recv_msg(void* arg);
void error_handling(const char* msg);

char name[NAME_SIZE] = "[1]";
char msg[BUF_SIZE];

void mega_callback(const std_msgs::String &input);
void uno_callback(const std_msgs::String &input);
void user_callback(const std_msgs::String &input);

class ros_server_topic
{
public:
	ros_server_topic()
	{
		mega_pub = mega_n.advertise<std_msgs::String>("/mega_to", 100);	
		mega_sub = mega_n.subscribe("/mega_from", 100, &ros_server_topic::mega_callback, this);

		uno_pub = uno_n.advertise<std_msgs::String>("/uno_to", 100);	
		uno_sub = uno_n.subscribe("/uno_from", 100, &ros_server_topic::uno_callback, this);

		user_pub = user_n.advertise<std_msgs::String>("/user_to", 100);	
		user_sub = user_n.subscribe("/user_from", 100, &ros_server_topic::user_callback, this);
	}

	void mega_callback(const std_msgs::String &input)
	{		
		mega_pub.publish(input);
	}

	void uno_callback(const std_msgs::String &input)
	{		
		uno_pub.publish(input);
	}

	void user_callback(const std_msgs::String &input)
	{		
		user_pub.publish(input);
	}

	ros::NodeHandle mega_n;
	ros::Publisher mega_pub;
	ros::Subscriber mega_sub;

	ros::NodeHandle uno_n;
	ros::Publisher uno_pub;
	ros::Subscriber uno_sub;

	ros::NodeHandle user_n;
	ros::Publisher user_pub;
	ros::Subscriber user_sub;

};




int main(int argc, char* argv[]) {

	int sock;
	struct sockaddr_in serv_addr;
	pthread_t snd_thread, rcv_thread;
	void* thread_return;
	
	//char* ros_ip = SERVER_IP;
    	//char* ros_port = SERVER_PORT;	

	ros::init(argc, argv, "topic");
	ros_server_topic ROSProject;
	

	//sprintf(name, "[%s]", ros_name);
	sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(atoi(SERVER_PORT));

	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");
	
	pthread_create(&snd_thread, NULL, send_msg, (void*)&sock);
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&sock);
	ros::spin();
	pthread_join(snd_thread, &thread_return);
	pthread_join(rcv_thread, &thread_return);
	
	close(sock);
	return 0;
}

void* send_msg(void* arg) {
	int sock = *((int*)arg);
	char name_msg[NAME_SIZE+BUF_SIZE];

	while(1) {
		fgets(msg, BUF_SIZE, stdin);
		if(!strcmp(msg, "q\n") || !strcmp(msg, "Q\n")) {
			close(sock);
			exit(0);
		}
		sprintf(name_msg, "%s %s", name, msg);
		write(sock, name_msg, strlen(name_msg));
	}
	return NULL;
}



void* recv_msg(void* arg) {
	int sock = *((int*)arg);
	char name_msg[NAME_SIZE+BUF_SIZE];
	int str_len;
	std_msgs::String send_message;
	char* search = "move";
	char* result = NULL;
	ros_server_topic ROSProject;
	while(1) {
		str_len = read(sock, name_msg, NAME_SIZE+BUF_SIZE-1);
		if(str_len == -1)
			return (void*)-1;
		name_msg[str_len] = 0;
		//if(1) {
		//	result = strstr(msg, search);
		//	printf("%s\n", result);
		//}		
		//if(result != NULL) {
			send_message.data = name_msg;
			ROSProject.mega_callback(send_message);
			printf("send topic \n");
		//}
		fputs(name_msg, stdout);
	}
	return NULL;
}

void error_handling(const char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
