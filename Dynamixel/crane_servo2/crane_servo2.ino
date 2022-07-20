//다이나믹셀, 서보모터(sg-90), 엔드스탑 작업완료 영상 올려야됨
/*eynamixel, Servo, Endstop*/
#include <Dynamixel2Arduino.h>
#include <Servo.h>
#define DXL_SERIAL   Serial3
#define DEBUG_SERIAL Serial
#define End 7

const int DXL_DIR_PIN = 84;

const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);
Servo servo;

//This namespace is required to use Control table item names
using namespace ControlTableItem;
/*eynamixel, Servo, Endstop*/

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);//서보모터 pin
  pinMode(End, INPUT);
  // Use Serial to debug.
  DEBUG_SERIAL.begin(57600);

  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(57600);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Get DYNAMIXEL information
  dxl.ping(DXL_ID);

  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_VELOCITY);
  dxl.torqueOn(DXL_ID);
}

void loop() {
  int value;
  if (DEBUG_SERIAL.available() > 0)
  value = DEBUG_SERIAL.read();
     
    if (value == '1') {//down
      while(1)
      {
      if (dxl.setGoalVelocity(DXL_ID, 30, UNIT_RPM)) {
        DEBUG_SERIAL.println(value);
        DEBUG_SERIAL.print("Dynamixel Position : ");
        DEBUG_SERIAL.println(dxl.getPresentVelocity(DXL_ID, UNIT_RPM));
        DEBUG_SERIAL.print("Servo Position : ");
        DEBUG_SERIAL.println(servo.read());
      }
      
      if(digitalRead(End) == LOW)
      {
        dxl.torqueOff(DXL_ID);
        servo.write(150);
        dxl.torqueOn(DXL_ID);
        break;
      }
    }
  }
    if (value == '2') {//up
    servo.write(60);
    if (dxl.setGoalVelocity(DXL_ID, -30, UNIT_RPM)) {
      DEBUG_SERIAL.print("Dynamixel Position : ");
      DEBUG_SERIAL.println(dxl.getPresentVelocity(DXL_ID, UNIT_RPM));
      DEBUG_SERIAL.print("Servo Position : ");
      DEBUG_SERIAL.println(servo.read());
    }
  }
}
