//LIBRARY
#include<NewPing.h>

//INISIALISASI
int r=PA6;
int y=PA7;
int g=PB0;
int flame=PA0;
int PIR=PA1;
int triger=PA3;
int echo=PA2;
int batas=400;

NewPing cm(triger,echo,batas);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(r,OUTPUT);
pinMode(y,OUTPUT);
pinMode(g,OUTPUT);
pinMode(flame,INPUT);
pinMode(PIR,INPUT);

}

void loop() {
  //BACA DATA ATAU SENSOR
int bacaJarak=cm.ping_cm();
int bacaFlame=analogRead(flame);
bacaFlame=map(bacaFlame,130,4095,0,100);
int bacaPIR=digitalRead(PIR);

//PRINT TO SERIAL
Serial.print("Jarak :");
Serial.print(bacaJarak);
Serial.print(" cm");
Serial.println();
Serial.print("Api :");
Serial.print(bacaFlame);
Serial.println();
Serial.print("PIR :");
Serial.print(bacaPIR);
Serial.println();

//LOGIKA PROGRAM

//PIR
if (bacaPIR==1){
  digitalWrite(r,HIGH);
}
else{
  digitalWrite(r,LOW);
}

//FLAME
if (bacaFlame<=20){
  digitalWrite(y,HIGH);
}
else{digitalWrite(y,LOW);
}

//ULTRASONIC
if (bacaJarak<=50){
  digitalWrite(g,HIGH);
}
else{
  digitalWrite(g,LOW);
}
}
