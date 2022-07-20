#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <Dynamixel2Arduino.h>
#include <Servo.h>

#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#define DXL_SERIAL   Serial3
#define DEBUG_SERIAL Serial

#define home 0
#define firstFloor 9000
#define secondFloor 7500

const int DXL_DIR_PIN = 84;
const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;

ros::NodeHandle  nh;
std_msgs::String str_msg;
ros::Publisher chat("complete", &str_msg);

char comp[9] = "complete";

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);
Servo servo1;
Servo servo2;

//This namespace is required to use Control table item names
using namespace ControlTableItem;

void hold(int value);
void putDown(int value);

void move_dn(const std_msgs::String &cmd_msg)
{
  String temp = cmd_msg.data;
  int result[2] = { -1, -1 };
  String search[2] = {"hold", "putDown"};
  for (int i = 0; i < 2; i++) {
    result[i] = temp.compareTo(search[i]);
  }
  if (result[0] == 0)
    hold(firstFloor);
  else if (result[1] == 0)
  {
    putDown(firstFloor);
    str_msg.data = comp;
    chat.publish(&str_msg);
  }
}

//ros를 사용하기 위한 명령어
ros::Subscriber<std_msgs::String> sub1("grep_move", move_dn);

void setup() {
  // put your setup code here, to run once:
  servo1.attach(9);
  servo2.attach(10);
  // Use Serial to debug.
  DEBUG_SERIAL.begin(57600);
  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(57600);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Get DYNAMIXEL information
  dxl.ping(DXL_ID);

  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID);

  nh.initNode();
}

void loop() { //루프문은 거드리지 말것 나머지는 함수로 구현
  // put your main code here, to run repeatedly
  nh.spinOnce();
  delay(1);
}

void hold(int value)//집게를 내려서 컨테이너를 잡고 올라옴
{
  servo1.write(150);
  servo2.write(150);
  dxl.setGoalPosition(DXL_ID, value);
  delay(1500);
  servo1.write(50);
  servo2.write(50);
  delay(1000);
  dxl.setGoalPosition(DXL_ID, home);
}

void putDown(int value)//집게를 내려서 컨테이너를 내리고 올라옴
{
  servo1.write(50);
  servo2.write(50);
  dxl.setGoalPosition(DXL_ID, value);
  delay(1500);
  servo1.write(150);
  servo2.write(150);
  delay(1000);
  dxl.setGoalPosition(DXL_ID, home);
}
