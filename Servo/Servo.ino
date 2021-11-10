#include<Servo.h>
int outServo=5;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(outServo);
}

void loop() {
  // put your main code here, to run repeatedly:
myservo.write(0);//0-180
delay(800);
myservo.write(90);//0-180
delay(800);
myservo.write(180);
delay(800);
}
