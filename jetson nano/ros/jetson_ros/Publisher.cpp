#include "ros/ros.h"
#include "std_msgs/String.h"

#include <iostream>
#include <string.h>

#define BUF_SIZE 100

int main(int argc, char **argv)
{
  ros::init(argc, argv, "jetsonRosPub");

  ros::NodeHandle n;


  ros::Publisher chatter_pub1 = n.advertise<std_msgs::String>("uno", 1000);
  ros::Publisher chatter_pub2 = n.advertise<std_msgs::String>("mega", 1000);

  ros::Rate loop_rate(10);

  int count = 0;

	std_msgs::String msg;
	
	char input[BUF_SIZE];

	while(1) 
	{
		fgets(input, BUF_SIZE, stdin);
		if(!strcmp(input,"q\n")||!strcmp(input,"Q\n")) break;
		std::stringstream ss;
		ss<<input;
		msg.data = ss.str();
		if(input[0]=='u') chatter_pub1.publish(msg);
		if(input[0]=='m') chatter_pub2.publish(msg);
		ros::spinOnce();
	}

  return 0;
}