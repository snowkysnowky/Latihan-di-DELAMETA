//INISIALISASI
int pinFlame=A1;
int buzz=5;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int bacaFlame=analogRead(pinFlame);
bacaFlame=map(bacaFlame,0,1012,100,0);

//PRINT TO SERIAL
Serial.print("Nilai :");
Serial.print(bacaFlame);
Serial.println();
delay(100);

//
if(bacaFlame<30){
  Serial.println("AMAN SANS");
}
else if(bacaFlame>30 && bacaFlame<80){
  Serial.println("Ada Api");
  digitalWrite(buzz,HIGH);
  delay(500);
  digitalWrite(buzz,LOW);
  delay(500);
}
else if (bacaFlame>=80){
  Serial.println("API GEDE");
  digitalWrite(buzz,HIGH);
  delay(100);
  digitalWrite(buzz,LOW);
  delay(100);

  
}
}
