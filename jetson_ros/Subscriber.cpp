#include "ros/ros.h"
#include "std_msgs/String.h"

#include <boost/thread.hpp>

ros::Duration d(0.01);

class Listener
{
public:
  void chatter1(const std_msgs::String::ConstPtr& msg)
  {
    ROS_INFO_STREAM("uno: [" << msg->data << "]");
    d.sleep();
  }
  void chatter2(const std_msgs::String::ConstPtr& msg)
  {
    ROS_INFO_STREAM("mega: [" << msg->data << "]");
    d.sleep();
  }
  void chatter3(const std_msgs::String::ConstPtr& msg)
  {
    ROS_INFO_STREAM("asd: [" << msg->data << "]");
    d.sleep();
  }
};
int main(int argc, char **argv)
{
  ros::init(argc, argv, "jetsonRosRecv");
  ros::NodeHandle n;

  Listener l;
  ros::Subscriber sub1 = n.subscribe("uno", 10, &Listener::chatter1, &l);
  ros::Subscriber sub2 = n.subscribe("mega", 10, &Listener::chatter2, &l);
  ros::Subscriber sub3 = n.subscribe("asd", 10, &Listener::chatter3, &l);
  ros::MultiThreadedSpinner s(3);
  ros::spin(s);

  return 0;
}

