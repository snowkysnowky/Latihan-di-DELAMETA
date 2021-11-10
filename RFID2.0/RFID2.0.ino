#include <SPI.h>
#include <MFRC522.h>
String uidString;
int buzz=3;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); //Create MFRC522 instance.

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzz,OUTPUT);
SPI.begin(); //Initiate SPI bus
mfrc522.PCD_Init();

}

void loop() {
  // put your main code here, to run repeatedly:
if(mfrc522.PICC_IsNewCardPresent()){
  readRFID();
  Serial.print("Tag UID: ");
  Serial.println(uidString);
}
}
void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //Sound the buzzer when a card is read
  buzzOke();
  //Pembatas bisa dirubah sesuai keiginan,disini yang digunakan "-"
  uidString = String(mfrc522.uid.uidByte[0]) + "-" +
  String(mfrc522.uid.uidByte[1]) + "-" +
  String(mfrc522.uid.uidByte[2]) + "-" +
  String(mfrc522.uid.uidByte[3]);
}

void buzzOke(){
  digitalWrite(buzz,HIGH);
  delay(50);
  digitalWrite(buzz,LOW);
  delay(50);
  digitalWrite(buzz,HIGH);
  delay(50);
  digitalWrite(buzz,LOW);
  delay(50);
}
void buzzSalah(){
  digitalWrite(buzz,HIGH);
  delay(500);
}
