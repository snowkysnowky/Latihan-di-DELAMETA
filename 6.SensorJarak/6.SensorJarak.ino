//
#include<NewPing.h>

//INISIALISASI
int triger=5;
int echo=4;
int batas=200;

NewPing cm(triger,echo,batas);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int bacaJarak=cm.ping_cm();

//PRINT TO SERIAL
Serial.print("Data jarak: ");
Serial.print(bacaJarak);
Serial.print(" cm");
Serial.println();
delay(500);
}
