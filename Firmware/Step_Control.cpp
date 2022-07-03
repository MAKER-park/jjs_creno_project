#include <Stepper.h>

#define X_STEP A0
#define X_DIR A1

#define Y_STEP A2
#define Y_DIR A3
void setup() {
// put your setup code here, to run once:
pinMode(X_STEP, OUTPUT);//스텝모터 x축
pinMode(X_DIR, OUTPUT);//스텝모터 x축 방향
pinMode(Y_STEP, OUTPUT);//스텝모터 y축
pinMode(Y_DIR, OUTPUT);//스텝모터 y축 방향
}

//스텝모터 방향별로 2바퀴반씩 돌리기
void loop() {
// put your main code here, to run repeatedly:
digitalWrite(X_DIR, HIGH); //회전 방향 설정
digitalWrite(Y_DIR, LOW);

for(int x = 0; x < 500; x++) //100마다 한바퀴씩 회전
{
digitalWrite(X_STEP, HIGH);
digitalWrite(Y_STEP, HIGH);
delay(2);
digitalWrite(X_STEP, LOW);
digitalWrite(Y_STEP, LOW);
delay(2);
}
delay(1000);

digitalWrite(X_DIR, LOW);
digitalWrite(Y_DIR, HIGH);

for(int x = 0; x < 500; x++)
{
digitalWrite(X_STEP, HIGH);
digitalWrite(Y_STEP, HIGH);
delay(2);
digitalWrite(X_STEP, LOW);
digitalWrite(Y_STEP, LOW);
delay(2);
}
delay(1000);
}