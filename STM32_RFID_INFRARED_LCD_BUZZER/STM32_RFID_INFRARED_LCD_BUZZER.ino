#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int outServo=PA4;
Servo myservo;
String uidString;
int buzz=PA0;
int Infrared=PA1;
int kunci1=0;
#define SS_PIN PB1
#define RST_PIN PB0
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
lcd.clear();
lcd.setCursor(0,0);lcd.print("TEMPELKAN KARTU");
myservo.write(90);
buzzOke();
}


void loop() {
  // put your main code here, to run repeatedly:
  int bacaInfrared=digitalRead(Infrared);
if(mfrc522.PICC_IsNewCardPresent() && kunci1==0){
  readRFID();
  Serial.print("Tag UID: ");
  Serial.println(uidString);
  if(uidString=="138D37A1011010W32" or uidString=="234DBDA11001111W200"){
  buzzOke();
  Serial.println("Selamat Datang");
  lcd.clear();
  lcd.setCursor(0,0);lcd.print("SELAMAT DATANG");
  Serial.println("Palang Terbuka");
  myservo.write(180);
  kunci1=1;
}

else if(uidString!="138D37A1011010W32"or uidString=="234DBDA11001111W200"){
  buzzSalah();
  Serial.println("Kartu belum terdaftar");
  lcd.clear();
  lcd.setCursor(0,0);lcd.print("KARTU BELUM");
  lcd.setCursor(0,1);lcd.print("TERDAFTAR");
  delay(500);
    lcd.clear();
  lcd.setCursor(0,0);lcd.print("TEMPELKAN KARTU");
}
}
if(bacaInfrared==0 && kunci1==1)
{
  Serial.println("BYE BYE");
  lcd.clear();
  lcd.setCursor(0,0);lcd.print("BYE BYE");
  myservo.write(90);
  Serial.println("Palang Tertutup");
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);lcd.print("TEMPELKAN KARTU");
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
