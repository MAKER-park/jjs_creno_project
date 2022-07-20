#include <Dynamixel2Arduino.h>
#include <Servo.h>
#define DXL_SERIAL   Serial3
#define DEBUG_SERIAL Serial

#define home 0
#define firstFloor 3000
#define secondFloor 2500

const int DXL_DIR_PIN = 84;
const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);
Servo servo;

//This namespace is required to use Control table item names
using namespace ControlTableItem;
/*eynamixel, Servo*/

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
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

  //다이나믹셀을 내려서 높이를 구함(서보모터는 벌린 상태)
  servo.write(150);
  if (dxl.setGoalPosition(DXL_ID, firstFloor)) {
    delay(1500);
    DEBUG_SERIAL.print("Present Extended Position1 : ");
    DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID)); DEBUG_SERIAL.println();
  }
  delay(1000);
  if (dxl.setGoalPosition(DXL_ID, home)) {
    delay(1500);
    DEBUG_SERIAL.print("Present Extended Position2 : ");
    DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID)); DEBUG_SERIAL.println();
  }
  delay(2000);
  //높이구하기 완료

  //컨테이너 잡아서 올리기(서보모터 벌려서 이동 후 잡고 올림)
  if (dxl.setGoalPosition(DXL_ID, secondFloor)) {
    delay(1500);
    DEBUG_SERIAL.print("Present Extended Position3 : ");
    DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID)); DEBUG_SERIAL.println();
  }
  delay(1000);
  servo.write(20);
  delay(500);
  if (dxl.setGoalPosition(DXL_ID, home)) {
    delay(1500);
    DEBUG_SERIAL.print("Present Extended Position4 : ");
    DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID)); DEBUG_SERIAL.println();
  }
  delay(2000);
  //컨테이너 잡고 들어올리기 완료

  //내려놓을 자리로 이동했다 치고 다이나믹셀을 내려서 컨테이너 내려놓고 다시 올라오기
  if (dxl.setGoalPosition(DXL_ID, firstFloor)) {
    delay(1500);
    DEBUG_SERIAL.print("Present Extended Position5 : ");
    DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID)); DEBUG_SERIAL.println();
  }
  delay(1000);
  servo.write(150);
  if (dxl.setGoalPosition(DXL_ID, home)) {
    delay(1500);
    DEBUG_SERIAL.print("Present Extended Position6 : ");
    DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID)); DEBUG_SERIAL.println();
  }
  delay(2000);
  //내려놓고 원위치
}
