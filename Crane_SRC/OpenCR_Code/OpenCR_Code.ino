#include <Dynamixel2Arduino.h>
#include <Servo.h>

#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#define DXL_SERIAL   Serial3
#define DEBUG_SERIAL Serial

#define End 7

#define defaultFloor 0
#define firstFloor -9500
#define secondFloor -6800

using namespace ControlTableItem;

uint8_t now_value;
const int DXL_DIR_PIN = 84;
const uint8_t DXL_ID1 = 1;
const uint8_t DXL_ID2 = 2;
const float DXL_PROTOCOL_VERSION = 2.0;

ros::NodeHandle  nh;
std_msgs::Empty str_msg;
ros::Publisher next_pub("next_move", &str_msg);
ros::Publisher complete_pub("complete", &str_msg);

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);
Servo servo1;
Servo servo2;

int result[3] = { defaultFloor, firstFloor, secondFloor };

void hold(int value);
void putDown(int value);

void move_hold(const std_msgs::UInt16 &cmd_msg);
void move_putDown(const std_msgs::UInt16 &cmd_msg);

void move_hold(const std_msgs::UInt16 &cmd_msg)
{
  int value = result[cmd_msg.data];

  hold(value);
  next_pub.publish(&str_msg);
}

void move_putDown(const std_msgs::UInt16 &cmd_msg)
{
  int value = result[cmd_msg.data];

  putDown(value);
  complete_pub.publish(&str_msg);
}

ros::Subscriber<std_msgs::UInt16> hold_sub("/grep_hold", move_hold);
ros::Subscriber<std_msgs::UInt16> putDown_sub("/grep_putDown", move_putDown);

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  pinMode(End, INPUT);

  DEBUG_SERIAL.begin(57600);

  dxl.begin(57600);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  dxl.ping(DXL_ID1);
  dxl.ping(DXL_ID2);

  dxl.torqueOff(DXL_ID1);
  dxl.setOperatingMode(DXL_ID1, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID1);

  dxl.torqueOff(DXL_ID2);
  dxl.setOperatingMode(DXL_ID2, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID2);

  nh.initNode();
  nh.subscribe(hold_sub);
  nh.subscribe(putDown_sub);

  nh.advertise(next_pub);
  nh.advertise(complete_pub);

}

void loop() {
  nh.spinOnce();
  delay(10);
}

void hold(int value) {

  servo1.writeMicroseconds(2400);
  delay(1);
  servo2.writeMicroseconds(2400);
  delay(2500);

  dxl.setGoalPosition(DXL_ID1, value);
  dxl.setGoalPosition(DXL_ID2, value);
  delay(2500);

  servo1.writeMicroseconds(2100);
  delay(1);
  servo2.writeMicroseconds(2100);
  delay(2500);

  dxl.setGoalPosition(DXL_ID1, defaultFloor);
  dxl.setGoalPosition(DXL_ID2, defaultFloor);
  delay(2500);
}

void putDown(int value) {

  servo1.writeMicroseconds(2100);
  delay(1);
  servo2.writeMicroseconds(2100);
  delay(2500);

  dxl.setGoalPosition(DXL_ID1, value);
  dxl.setGoalPosition(DXL_ID2, value);
  delay(2500);

  servo1.writeMicroseconds(2400);
  delay(1);
  servo2.writeMicroseconds(2400);
  delay(2500);

  dxl.setGoalPosition(DXL_ID1, defaultFloor);
  dxl.setGoalPosition(DXL_ID2, defaultFloor);
  delay(2500);
}
