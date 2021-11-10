//INISIALISASI
int pinLDR=A0;
int pinR=5;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pinR,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int bacaLDR=analogRead(pinLDR);

//PRINT TO SERIAL
Serial.print("Nilai :");
Serial.print(bacaLDR);
Serial.println();
delay(100);

//
if (bacaLDR>700){
  digitalWrite(pinR,HIGH);
}
else{
  digitalWrite(pinR,LOW);
}
}
