#include <SPI.h>
#include <MFRC522.h>
String uidString;
int buzz=2;
int Infrared=3;
int kunci1=0;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); //Create MFRC522 instance.

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzz,OUTPUT);
pinMode(Infrared,INPUT);
SPI.begin(); //Initiate SPI bus
mfrc522.PCD_Init();

}

void loop() {
  // put your main code here, to run repeatedly:
  int bacaInfrared=digitalRead(Infrared);
if(mfrc522.PICC_IsNewCardPresent() && kunci1==0){
  readRFID();
  Serial.print("Tag UID: ");
  Serial.println(uidString);
  if(uidString=="138D37A90W26"){
  buzzOke();
  Serial.println("Selamat Datang");
  Serial.println("Palang Terbuka");
  kunci1=1;
}

else if(uidString!="138D37A90W26"){
  buzzSalah();
  Serial.println("Kartu belum terdaftar");
}
}
if(bacaInfrared==0 && kunci1==1)
{
  Serial.println("BYE BYE");
  Serial.println("Palang Tertutup");
  kunci1=0;
}

}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //Sound the buzzer when a card is read
 
  //Pembatas bisa dirubah sesuai keiginan,disini yang digunakan "-"
  uidString = String(mfrc522.uid.uidByte[0]) + "D" +
  String(mfrc522.uid.uidByte[1],HEX) + "A" +
  String(mfrc522.uid.uidByte[2],BIN) + "W" +
  String(mfrc522.uid.uidByte[3],OCT);
  uidString.toUpperCase();
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
  digitalWrite(buzz,LOW);
}
