#include <NewPing.h>
#include <AFMotor.h>
#define md 100
int trig=A5;
int echo=A4;
int left=A0;
int right=A1;
NewPing sonar(trig,echo,md);
 int distance;
 int speed_1=255;
 int speed_2=255;


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  pinMode(left,INPUT);
  pinMode(right,INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  distance= sonar.ping_cm();
  int left_val=analogRead(left);
  int right_val=analogRead(right);


  if(distance>7 && distance<40 && left_val>1000 && right_val>1000){
    motor1.setSpeed(speed_1);
    motor1.run(FORWARD);
    motor2.setSpeed(speed_1);
    motor2.run(FORWARD);
    motor3.setSpeed(speed_1);
    motor3.run(FORWARD);
    motor4.setSpeed(speed_1);
    motor4.run(FORWARD);
  }
  else if(left_val<100 && right_val>1000){
    motor1.setSpeed(speed_2);
    motor1.run(BACKWARD);
    motor2.setSpeed(speed_2);
    motor2.run(FORWARD);
    motor3.setSpeed(speed_2);
    motor3.run(FORWARD);
    motor4.setSpeed(speed_2);
    motor4.run(BACKWARD);
  }
  else if(left_val>1000 && right_val<100){
    motor1.setSpeed(speed_2);
    motor1.run(FORWARD);
    motor2.setSpeed(speed_2);
    motor2.run(BACKWARD);
    motor3.setSpeed(speed_2);
    motor3.run(BACKWARD);
    motor4.setSpeed(speed_2);
    motor4.run(FORWARD);
  }
  else if(distance<5 && distance>0){
    motor1.setSpeed(speed_1);
    motor1.run(BACKWARD);
    motor2.setSpeed(speed_1);
    motor2.run(BACKWARD);
    motor3.setSpeed(speed_1);
    motor3.run(BACKWARD);
    motor4.setSpeed(speed_1);
    motor4.run(BACKWARD);
  }
  // //&& left_val>1000 && right_val>1000
  // else if(distance<5 && distance>0 && left_val<100 && right_val>1000){
  //   motor1.setSpeed(255);
  //   motor1.run(BACKWARD);
  //   motor2.setSpeed(255);
  //   motor2.run(FORWARD);
  //   motor3.setSpeed(255);
  //   motor3.run(FORWARD);
  //   motor4.setSpeed(255);
  //   motor4.run(BACKWARD);
  // }
  // else if(distance<5 && distance>0 && left_val>1000 && right_val<100){
  //   motor1.setSpeed(255);
  //   motor1.run(FORWARD);
  //   motor2.setSpeed(255);
  //   motor2.run(BACKWARD);
  //   motor3.setSpeed(255);
  //   motor3.run(BACKWARD);
  //   motor4.setSpeed(255);
  //   motor4.run(FORWARD);
 // }
  else if(distance=0){
    motor1.setSpeed(0);
    motor1.run(RELEASE);
    motor2.setSpeed(0);
    motor2.run(RELEASE);
    motor3.setSpeed(0);
    motor3.run(RELEASE);
    motor4.setSpeed(0);
    motor4.run(RELEASE); 
  }
  else{
    motor1.setSpeed(0);
    motor1.run(RELEASE);
    motor2.setSpeed(0);
    motor2.run(RELEASE);
    motor3.setSpeed(0);
    motor3.run(RELEASE);
    motor4.setSpeed(0);
    motor4.run(RELEASE); 
  }
  


}
