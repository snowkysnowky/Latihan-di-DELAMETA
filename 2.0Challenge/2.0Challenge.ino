//INISIALISASI
int pinLDR=A0;
int pinFlame=A1;
int pinPIR=2;
int pinR=3;
int pinY=4;
int pinG=5;
int buzz=6;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pinPIR,INPUT);
pinMode(pinR,OUTPUT);
pinMode(pinY,OUTPUT);
pinMode(pinG,OUTPUT);
pinMode(buzz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int bacaLDR=analogRead(pinLDR);
int bacaFlame=analogRead(pinFlame);
int bacaPIR=digitalRead(pinPIR);

//PRINT TO SERIAL
Serial.print("LDR   :");
Serial.print(bacaLDR);
Serial.println();
Serial.print("Flame :");
Serial.print(bacaFlame);
Serial.println();
Serial.print("PIR   :");
Serial.print(bacaPIR);
Serial.println();
delay(200);

//MAPPING
bacaLDR=map(bacaLDR,28,880,0,255);
bacaFlame=map(bacaFlame,0,1018,100,0);

//LOGIKA
analogWrite(pinR,bacaLDR);
if(bacaFlame<30){
  Serial.println("AMAN BANGET");
  digitalWrite(pinG,HIGH);
  digitalWrite(pinY,LOW);

}
else if(bacaFlame>30 && bacaFlame<80){
  Serial.println("WARNING SILAHKAN PERIKSA");
  digitalWrite(pinY,HIGH);
 
  digitalWrite(pinG,LOW);
  digitalWrite(buzz,HIGH);
  delay(500);
  digitalWrite(buzz,LOW);
  delay(500);
}
else if (bacaFlame>=80){
  Serial.println("WASPADA HARAP MENGUNGSI");

  digitalWrite(pinY,HIGH);
  digitalWrite(pinG,HIGH);
  digitalWrite(buzz,HIGH);
  delay(100);
  digitalWrite(buzz,LOW);
  delay(100);

}
}
