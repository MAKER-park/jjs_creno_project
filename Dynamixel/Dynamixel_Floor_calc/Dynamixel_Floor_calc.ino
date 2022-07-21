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

const int DXL_DIR_PIN = 84;
const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;

ros::NodeHandle  nh;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

void setup() {
  // put your setup code here, to run once:
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
}

void loop() {
  // put your main code here, to run repeatedly:
  dxl.setGoalPosition(DXL_ID, 9000);//1층
  delay(5000);
  dxl.setGoalPosition(DXL_ID, 5000);//2층
  delay(5000);
  dxl.setGoalPosition(DXL_ID, 0);//맨위
  delay(5000);

}
