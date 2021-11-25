//LIBRARY
#include <NewPing.h>

//INISIALISASI
int r=PA6;
int y=PA7;
int g=PB0;
int triger=PA3;
int echo=PA2;
int batas=400;
int flame=PA0;
int PIR=PA1;
int kunci=0;
int kunci1=0;

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
  // put your main code here, to run repeatedly:
int bacaJarak=cm.ping_cm();
int bacaFlame=analogRead(flame);
int bacaPIR=digitalRead(PIR);

//PRINT TO SERIAL
Serial.print("Jarak :");
Serial.print(bacaJarak);
Serial.println();
Serial.print("Api :");
Serial.print(bacaFlame);
Serial.println();
Serial.print("PIR :");
Serial.print(bacaPIR);
Serial.println();
Serial.print("Kunci :");
Serial.print(kunci);
Serial.println();




//LOGIKA
if (bacaPIR==1 or bacaFlame<=500 and kunci==0 ){
  kunci=1;

  delay(10000);
}
else if(bacaPIR==1 or bacaFlame<=500 and kunci==1){
kunci=0;
  digitalWrite(r,LOW);
  digitalWrite(y,LOW);
  digitalWrite(g,LOW);

  delay(10000);
  kunci=0;
  bacaPIR=0;
  delay(200);
  
}
else if (bacaJarak>=201 and kunci ==1){
  flipflop();

}
else if (bacaJarak<=200 and bacaJarak>=20 and kunci==1){
  digitalWrite(r,HIGH);
  digitalWrite(y,HIGH);
  digitalWrite(g,HIGH);
  delay(500);
  digitalWrite(r,LOW);
  digitalWrite(y,LOW);
  digitalWrite(g,LOW);
  delay(500);

}
else if (bacaJarak<=19 and kunci==1){
    digitalWrite(r,HIGH);
  digitalWrite(y,HIGH);
  digitalWrite(g,HIGH);
  delay(100);
  digitalWrite(r,LOW);
  digitalWrite(y,LOW);
  digitalWrite(g,LOW);
  delay(100);

}
}

void flipflop(){
  digitalWrite(r,HIGH);
  delay(50);
  digitalWrite(r,LOW);
  digitalWrite(y,HIGH);
  delay(50);
  digitalWrite(y,LOW);
  digitalWrite(g,HIGH);
  delay(50);
  digitalWrite(g,HIGH);
  digitalWrite(y,LOW);
  delay(50);
  digitalWrite(g,LOW);
  digitalWrite(y,HIGH);
  delay(50);
  digitalWrite(y,LOW);
  digitalWrite(r,HIGH);
  delay(50);
  digitalWrite(y,LOW);
}
