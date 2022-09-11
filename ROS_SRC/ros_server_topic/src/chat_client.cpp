//ROS 클라이언트 코드

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <sstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

#define BUF_SIZE 100
#define NAME_SIZE 20

#define SERVER_IP "112.145.215.121"
#define SERVER_PORT "5040"

void* send_msg(void* arg);
void* recv_msg(void* arg);
void error_handling(const char* msg);
void mega_callback(const std_msgs::String &input);
void mega_status(const std_msgs::Empty &status_info);
void from_QR_Data(const std_msgs::String &input);

char name[NAME_SIZE] = "[2]";
char msg[BUF_SIZE];
string QR_Data = "";

char* temp[10];

bool complete_status = false;
bool running_status = false;
bool QR_status = false;

string input_old = "";
int sock;
struct sockaddr_in serv_addr;
pthread_t snd_thread, rcv_thread;
void* thread_return;

class ros_server_topic
{
	public:
		ros_server_topic()
		{
			mega_pub = _n.advertise<std_msgs::String>("/step_move", 100);
			mega_sub = _n.subscribe("/complete", 100, &ros_server_topic::mega_status, this);
			QR_sub = _n.subscribe("/QR_Code", 100, &ros_server_topic::from_QR_Data, this);
		}

		void mega_callback(const std_msgs::String &input) {		
			mega_pub.publish(input);
			cout << "mega_callback" << endl;
		}

		void mega_status(const std_msgs::Empty &status_info) {		
			complete_status = true;
			cout << "complete!!!!!!" << endl;
			send_msg((void*)&sock);
		}

		void from_QR_Data(const std_msgs::String &input) {
			cout << QR_status << endl;
			if(QR_status == false){
				if(input.data != input_old){
					cout <<"fuck!!!!!!!"<<endl;
					input_old=input.data;
					QR_Data = input.data;
					QR_status = true;
					//send_msg(1);
					send_msg((void*)&sock);
				}
			}
			/*if(QR_status == false) {
			  QR_Data = input.data;
			  QR_status = true;
			  }*/
		}

		ros::NodeHandle _n;
		ros::Publisher mega_pub;
		ros::Subscriber mega_sub;
		ros::Subscriber QR_sub;
};

int main(int argc, char* argv[]) {
	/* 
	   int sock;
	   struct sockaddr_in serv_addr;
	   pthread_t snd_thread, rcv_thread;
	   void* thread_return;
	 */
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

	//pthread_create(&snd_thread, NULL, send_msg, (void*)&sock);
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&sock);
	ros::spin();
	//pthread_join(snd_thread, &thread_return);
	pthread_join(rcv_thread, &thread_return);

	close(sock);
	return 0;
}

void* send_msg(void* arg) {
	int sock = *((int*)arg);
	char name_msg[NAME_SIZE+BUF_SIZE];
	//while(1) {
	cout << "send fuck!!" << endl;
	cout << "QR : " << QR_status << " comple_status : " << complete_status << endl;
	//fgets(msg, BUF_SIZE, stdin);
	if(!strcmp(msg, "q\n") || !strcmp(msg, "Q\n")) {
		close(sock);
		exit(0);
	}
	/*
	   if(complete_status == false) {
	//cout <<"fuck_!!!_"<<endl;
	sprintf(name_msg, "%s %s", name, msg);
	write(sock, name_msg, strlen(name_msg));
	}*/
	if(complete_status == true) {
		strcpy(msg, "complete");
		sprintf(name_msg, "%s %s", name, msg);
		write(sock, name_msg, strlen(name_msg));
		complete_status = false;
	}
	if(running_status == true) {
		strcpy(msg, "running");
		sprintf(name_msg, "%s %s", name, msg);
		write(sock, name_msg, strlen(name_msg));
		running_status = false;
	}
	if(QR_status == true) {
		int index = 0;
		cout << "fuck!!!" << endl;
		while(index <= 100) {
			msg[index] = QR_Data[index];
			index++;
		}
		sprintf(name_msg, "%s <QR> %s \n", name, msg);
		write(sock, name_msg, strlen(name_msg));
		QR_status = false;
	}
	//}
	return NULL;
}

void* recv_msg(void* arg) {
	int sock = *((int*)arg);
	char name_msg[NAME_SIZE+BUF_SIZE];
	int str_len;

	std_msgs::String send_message;
	string search = "move";
	ros_server_topic ROSProject;
	string recv_data;
	string send_data;
	int result = 0;
	size_t pos;	

	while(1) {
		str_len = read(sock, name_msg, NAME_SIZE+BUF_SIZE-1);
		if(str_len == -1)
			return (void*)-1;
		name_msg[str_len] = 0;

		recv_data = name_msg;
		pos = recv_data.find(']');
		recv_data = recv_data.substr(pos + 2, 4);
		cout << "recv_data : " << recv_data << endl;

		result = recv_data.compare(search);

		cout << "result : " << result << endl;

		if(result == 0) {
			send_data = name_msg;
			pos = send_data.find(']');
			send_data = send_data.substr(pos + 7);
			cout << "send_data : " << send_data << endl;
			send_message.data = send_data;
			ROSProject.mega_callback(send_message);
			cout << "send topic \n" << endl;
			running_status = true;
			send_msg((void*)&sock);
		}
		fputs(name_msg, stdout);
	}
	return NULL;
}

void error_handling(const char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
