//#if (ARDUINO >= 100)
//#include <Arduino.h>
//#else
//#include <WProgram.h>
//#endif
#include <Dynamixel2Arduino.h>
#include <Servo.h>

#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#define DXL_SERIAL   Serial3
#define DEBUG_SERIAL Serial

#define End 7

#define zeroFloor 0
#define firstFloor 9000
#define secondFloor 7500

uint8_t now_value;
const int DXL_DIR_PIN = 84;
const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;

ros::NodeHandle  nh;
std_msgs::Empty str_msg;
ros::Publisher chat1("complete", &str_msg);
ros::Publisher chat2("next_step", &str_msg);

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);
Servo servo1;
Servo servo2;

//This namespace is required to use Control table item names
using namespace ControlTableItem;

int result[3] = { zeroFloor, firstFloor, secondFloor };

void hold(int value);
void putDown(int value);

void move_hold(const std_msgs::UInt16 &cmd_msg);
void move_putDown(const std_msgs::UInt16 &cmd_msg);

void move_hold(const std_msgs::UInt16 &cmd_msg)
{
    int value = result[(cmd_msg.data)];

    hold(value);
    chat2.publish(&str_msg);
}

void move_putDown(const std_msgs::UInt16 &cmd_msg)
{
    int value = result[(cmd_msg.data)];

    putDown(value);
    chat1.publish(&str_msg);
}

//ros를 사용하기 위한 명령어
ros::Subscriber<std_msgs::UInt16> sub1("/grep_hold", move_hold);
ros::Subscriber<std_msgs::UInt16> sub2("/grep_putDown", move_putDown);

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  pinMode(End, INPUT);

  DEBUG_SERIAL.begin(57600);

  dxl.begin(57600);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  dxl.ping(DXL_ID);

  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID);

  nh.initNode();
  nh.subscribe(sub1);
  nh.subscribe(sub2);
  
  nh.advertise(chat1);
  nh.advertise(chat2);
  
}

void loop() { //루프문은 거드리지 말것 나머지는 함수로 구현
  nh.spinOnce();
  delay(1);
}

void hold(int value)//집게를 내려서 컨테이너를 잡고 올라옴
{
  servo1.write(150);//집게를 벌리고 내려감
  servo2.write(150);//집게를 벌리고 내려감

  dxl.setGoalPosition(DXL_ID, value);//value값만큼 다이나믹셀을 내림

  if (digitalRead(End) == LOW)//엔드스탑이 찍히면 찍힌곳에서 위치값을 저장하고 컨테이너를 잡고 저장한 위치 값만큼 반대로 움직임
  {
    now_value = dxl.getPresentPosition(DXL_ID);//엔드스탑이 찍히면 현재 포지션값 저장
    dxl.torqueOff(DXL_ID);//토크를 꺼서 현재포지션을 0으로 만듦
    //    dxl.setOperatingMode(DXL_ID, OP_EXTENDED_POSITION);
    dxl.torqueOn(DXL_ID);//다시 토크 키고
    delay(1500);

    servo1.write(50);//집게를 다물어서 컨테이너를 잡음
    servo2.write(50);//집게를 다물어서 컨테이너를 잡음
    delay(1000);

    dxl.setGoalPosition(DXL_ID, -now_value);//저장된 포지션값의 음수값 만큼 다이나믹셀을 돌려서 들어올림
    dxl.torqueOff(DXL_ID);//다시 토크를 꺼서 들어올린자리를 0으로 초기화
    dxl.torqueOn(DXL_ID);//다시 코트 켜고

    return;//끝!
  }
  delay(1500);//찍히지 않으면 원래의 함수대로
  servo1.write(50);
  servo2.write(50);
  delay(1000);
  dxl.setGoalPosition(DXL_ID, zeroFloor);
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
  dxl.setGoalPosition(DXL_ID, zeroFloor);
}