#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#define X_STEP 54
#define X_DIR 55
#define X_ENABLE 38
#define X_MIN 3
#define X_MAX 2

#define Y_STEP 60
#define Y_DIR 61
#define Y_ENABLE 56
#define Y_MIN 14
#define Y_MAX 15

#define Z_STEP 46
#define Z_DIR 48
#define Z_ENABLE 62
#define Z_MIN 18
#define Z_MAX 19

#define RESET 100
#define READY 101
#define WORKING 102

ros::NodeHandle  nh;

void* recv_msg(void* arg);

std_msgs::UInt16 int_msg;
ros::Publisher opencr_hold("/grep_hold", &int_msg);
ros::Publisher opencr_putDown("/grep_putDown", &int_msg);

int x = 0, y = 0;
int location[] = {0, 0, 0, 0, 0, 0}; //최댓값 2,1

String alarm_str[2] = { "Safe", "Danger" };

// 필요한 함수들
void HOME(); //초기상태로 돌아오는 함수
void crane_move(int x_value, int y_value); //스텝모터를 좌표값으로 보내는 함수
void Split(String sData, char cSeparator); //파싱함수
int step_dir(int value, int dir); //모터 방향제어
int flag = RESET;
bool input_value = false;
bool emergency_status = false;

void step_move(const std_msgs::String &cmd_msg) { //좌표값을 파싱으로 x축, y축 값에따라 크레인 이동(컨테이너 올릴 좌표)
  if (flag == READY) {
    Split(cmd_msg.data, ',');
    crane_move(location[0], location[1]);
    int_msg.data = location[2];
    while (1) {
      if (emergency_status == false) {
        opencr_hold.publish(&int_msg);
        break;
      }
    }
  }
}
void next_move(const std_msgs::Empty & cmd_msg) { //좌표값을 파싱으로 x축, y축 값에따라 크레인 이동(컨테이너 올릴 좌표)
  if (flag == READY) {
    crane_move(location[3], location[4]);
    int_msg.data = location[5];
    opencr_putDown.publish(&int_msg);
  }
}

void home_cb(const std_msgs::Empty & msg) { //초기상태로 돌아오는 함수
  if (flag == READY) {
    flag = RESET;
    HOME();
    flag = READY;
  }
}

void emergency(const std_msgs::String & msg) { //초기상태로 돌아오는 함수
  String str_tmp = msg.data;
  if (str_tmp == alarm_str[0])
    emergency_status = false;
  else if (str_tmp == alarm_str[1])
    emergency_status = true;
}

//ros를 사용하기 위한 명령어
ros::Subscriber<std_msgs::String> sub_step_move("/step_move", step_move);
ros::Subscriber<std_msgs::Empty> sub_next_move("/next_move", next_move);
ros::Subscriber<std_msgs::Empty> sub_home("/home", home_cb);
ros::Subscriber<std_msgs::String> alram("/alarm", emergency);

void setup() {
  pinMode(X_STEP, OUTPUT);
  pinMode(X_DIR, OUTPUT);
  pinMode(X_ENABLE, OUTPUT);
  pinMode(X_MIN, INPUT);

  pinMode(Y_STEP, OUTPUT);
  pinMode(Y_DIR, OUTPUT);
  pinMode(Y_ENABLE, OUTPUT);
  pinMode(Y_MIN, INPUT);

  pinMode(Z_STEP, OUTPUT);
  pinMode(Z_DIR, OUTPUT);
  pinMode(Z_ENABLE, OUTPUT);
  pinMode(Z_MIN, INPUT);

  digitalWrite(X_ENABLE, LOW);
  digitalWrite(Y_ENABLE, LOW);

  digitalWrite(X_DIR, LOW);
  digitalWrite(Y_DIR, LOW);

  nh.initNode();
  nh.subscribe(sub_step_move);
  nh.subscribe(sub_next_move);
  nh.subscribe(sub_home);

  nh.advertise(opencr_hold);
  nh.advertise(opencr_putDown);

  HOME();
}

void loop() {
  nh.spinOnce();
  delay(1);
}

void HOME() {
  digitalWrite(X_DIR, LOW);
  while (digitalRead(X_MIN)) { //엔드스탑이 인식될때까지
    digitalWrite(X_STEP, HIGH);
    delayMicroseconds(100);
    digitalWrite(X_STEP, LOW);
    delayMicroseconds(100);
  }
  delay(50);
  digitalWrite(X_DIR, HIGH);
  while (!digitalRead(X_MIN)) { //방향을 바꿔서 엔드스탑에서 떨어질때까지
    digitalWrite(X_STEP, HIGH);
    delayMicroseconds(100);
    digitalWrite(X_STEP, LOW);
    delayMicroseconds(100);
  }
  delay(500);
  digitalWrite(Y_DIR, LOW);
  while (digitalRead(Y_MIN)) {
    digitalWrite(Y_STEP, HIGH);
    delayMicroseconds(100);
    digitalWrite(Y_STEP, LOW);
    delayMicroseconds(100);
  }
  delay(50);
  digitalWrite(Y_DIR, HIGH);
  while (!digitalRead(Y_MIN)) {
    digitalWrite(Y_STEP, HIGH);
    delayMicroseconds(100);
    digitalWrite(Y_STEP, LOW);
    delayMicroseconds(100);
  }
  flag = READY;
}

void crane_move(int x_value, int y_value) {
  flag = WORKING;
  int x_temp = x_value, y_temp = y_value;

  if (x != x_value) { //설정위치와 현재 위치가 같지 않으면 실행
    digitalWrite(X_DIR, step_dir(x, x_value)); //방향설정
    if ((x_value -= x) < 0)// 설정좌표에서 현재좌표를 뺀 값이 음수이면
      x_value *= -1;//양수로 변경
    for (int i = 0; i < 12200 * (x_value); i++) {

      digitalWrite(X_STEP, HIGH);
      delayMicroseconds(100);
      digitalWrite(X_STEP, LOW);
      delayMicroseconds(100);
    }
  }
  delay(500);

  if (y != y_value) {
    digitalWrite(Y_DIR, step_dir(y, y_value));
    if ((y_value -= y) < 0)
      y_value *= -1;
    for (int i = 0; i < 13200 * (y_value); i++) {
      digitalWrite(Y_STEP, HIGH);
      delayMicroseconds(100);
      digitalWrite(Y_STEP, LOW);
      delayMicroseconds(100);
    }
  }
  x = x_temp; //설정좌표를 현재좌표에 저장
  y = y_temp;
  flag = READY;
}

void Split(String sData, char cSeparator) {
  int nCount = 0;
  int nGetIndex = 0 ;
  String sTemp = "";
  String sCopy = sData;

  while (true) {
    nGetIndex = sCopy.indexOf(cSeparator); //입력한 문자가 있는 곳의 위치를 반환

    if (nGetIndex != -1) { //찾은 문자가 없으면 indexof는 -1을 반환
      sTemp = sCopy.substring(0, nGetIndex); //처음 문자부터 찾은 문자 전까지 저장
      location[nCount] = sTemp.toInt(); //int형으로 저장
      sCopy = sCopy.substring(nGetIndex + 1);
    }
    else {
      location[nCount] = sCopy.toInt(); //찾은문자가 없으므로 남은 문자열을 넣고
      break; // 반복문을 빠져나감
    }
    ++nCount;
  }
}

int step_dir(int value, int dir) {

  if (value > dir)      //현재 좌표보다 움직일 좌표가 작을 경우
    return 0;           //-방향
  else if (value < dir) //현재 좌표보다 움직일 좌표가 클 경우
    return 1;           //+방향
}
