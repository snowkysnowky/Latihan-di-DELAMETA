#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include<Servo.h>
int outServo=5;
Servo myservo;
//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);
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
lcd.begin();
myservo.attach(outServo);
pinMode(buzz,OUTPUT);
pinMode(Infrared,INPUT);
SPI.begin(); //Initiate SPI bus
mfrc522.PCD_Init();
lcd.setCursor(0,0); lcd.print("SYTEM ON");
myservo.write(90);//0-180
delay(1000);
delay(500);
lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
}

void loop() {
  // put your main code here, to run repeatedly:
  int bacaInfrared=digitalRead(Infrared);
if(mfrc522.PICC_IsNewCardPresent() && kunci1==0){
  readRFID();
  Serial.print("Tag UID: ");
  Serial.println(uidString);
  if(uidString=="138D176A193W21"){
  buzzOke();
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(0,0); lcd.print("SELAMAT DATANG");
  lcd.setCursor(0,1); lcd.print("PALANG TERBUKA");
  myservo.write(0);//0-180
  delay(1000);
  kunci1=1;
}

else if(uidString!="138D176A193W21"){
  buzzSalah();
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(0,0); lcd.print("   KARTU TIDAK");
  lcd.setCursor(4,1); lcd.print("TERDAFTAR");
  delay(500);
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
}
}
if(bacaInfrared==0 && kunci1==1)
{
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(0,0); lcd.print("SELAMAT JALAN");
  lcd.setCursor(0,1); lcd.print("PALANG TERTUTUP");
  myservo.write(90);//0-180
  delay(1000);
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
  kunci1=0;
}

}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //Sound the buzzer when a card is read
 
  //Pembatas bisa dirubah sesuai keiginan,disini yang digunakan "-"
  uidString = String(mfrc522.uid.uidByte[0]) + "D" +
  String(mfrc522.uid.uidByte[1]) + "A" +
  String(mfrc522.uid.uidByte[2]) + "W" +
  String(mfrc522.uid.uidByte[3]);
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
