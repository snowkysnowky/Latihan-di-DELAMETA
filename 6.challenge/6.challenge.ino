//
#include<NewPing.h>

//INISIALISASI
int triger=5;
int echo=4;
int batas=400;
int buzz=3,R=6,Y=7,G=8;

NewPing cm(triger,echo,batas);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzz,OUTPUT);
pinMode(R,OUTPUT);
pinMode(Y,OUTPUT);
pinMode(G,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int bacaJarak=cm.ping_cm();

//PRINT TO SERIAL
Serial.print("Data jarak: ");
Serial.print(bacaJarak);
Serial.print(" cm");
Serial.println();
delay(100);
if (bacaJarak<=20 and bacaJarak!=0){
  digitalWrite(R,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  digitalWrite(buzz,HIGH);
  Serial.println("BERHENTI");
  delay(100);
  digitalWrite(buzz,LOW);
  delay(100);
}
else if(bacaJarak>=21 and bacaJarak<=70){
  digitalWrite(Y,HIGH);
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  Serial.println("BAHAYA");
  digitalWrite(buzz,HIGH);
  delay(300);
  digitalWrite(buzz,LOW);
  delay(300);
}
else{
   digitalWrite(Y,LOW);
  digitalWrite(R,LOW);
  digitalWrite(G,HIGH);
  digitalWrite(buzz,LOW);
  Serial.println("AMAN");
}
}
