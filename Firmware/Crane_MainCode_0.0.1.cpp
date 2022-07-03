#define X_STEP 54    //스텝모터 구동
#define X_DIR 55     //스텝모터 방향
#define X_ENABLE 38  //스텝모터 사용
#define X_MIN 3      //엔드스탑 최소위치
#define X_MAX 2      //엔드스탑 최대위치

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

#define JOY_X A3
#define JOY_Y A4

int joy_x, joy_y;
int x = 0, y = 0; //현재 위치 
int location[] = {0, 0}; //설정 위치, 최댓값 (4,3)

void HOME(); //초기위치설정 함수
void crane_move(int x_value, int y_value); //크레인 동작 함수
void Split(String sData, char cSeparator); //스플릿 함수
int step_dir(int now_value, int move_value); //스텝모터 방향 설정 함수
int flag = 0; //초기설정을 위한 플래그 함수

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
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
  HOME(); //초기위치로 이동
}

void loop() {
  //joy_x = analogRead(JOY_X);
  //joy_y = analogRead(JOY_Y);

  if (flag == 1) {
    if (Serial.available() > 0) { //들어오는 값이 있으면
      String order = Serial.readString(); //입력값을 저장하고
      Split(order, ','); //','을 기준으로 잘라주고
      crane_move(location[0], location[1]); //해당 위치로 이동한다
    }
  }
}

void HOME() {
  while (digitalRead(X_MIN)) {  //엔드스탑이 인식될때까지
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
  flag = 1;
}

void crane_move(int x_value, int y_value) {
  int x_temp = x_value, y_temp = y_value;

  if (x != x_value) { //설정위치와 현재위치가 같지 않으면 실행
    digitalWrite(X_DIR, step_dir(x, x_value)); //방향설정
    if ((x_value -= x) < 0) //설정좌표에서 현재좌표를 뺀 값이 음수이면
      x_value *= -1; //양수로 변경
    for (int i = 0; i < 6500 * (x_value); i++) {
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
    for (int i = 0; i < 4800 * (y_value); i++) {
      digitalWrite(Y_STEP, HIGH);
      delayMicroseconds(100);
      digitalWrite(Y_STEP, LOW);
      delayMicroseconds(100);
    }
  }
  x = x_temp; //설정좌표를 현재좌표에 저장
  y = y_temp;
}

void Split(String sData, char cSeparator) {
  int nCount = 0;
  int nGetIndex = 0 ;
  String sTemp = "";
  String sCopy = sData;

  while (true) {
    nGetIndex = sCopy.indexOf(cSeparator); //입력한 문자가 있는 곳의 위치를 반환

    if (nGetIndex != -1) {  //찾은 문자가 없으면 indexof는 -1을 반환
      sTemp = sCopy.substring(0, nGetIndex); //처음 문자부터 찾은 문자 전 까지 저장
      location[nCount] = sTemp.toInt();      //int형으로 저장
      sCopy = sCopy.substring(nGetIndex + 1);
    }
    else {
      location[nCount] = sCopy.toInt();  //찾은 문자가 없으므로 남은 문자열을 넣고 
      break;                             //반복문을 빠져나감
    }
    ++nCount;
  }
}

int step_dir(int now_value, int move_value) {

  if (now_value > move_value)       //현재 좌표보다 움직일 좌표가 클 경우
	  return 0;                       //+방향
  else if (now_value < move_value)  //현재 좌표보다 움직일 좌표가 작을 경우
    return 1;                       //-방향
}