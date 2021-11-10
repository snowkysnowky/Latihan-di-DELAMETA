//INISIALISASI
int pinFlame=A1;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int bacaFlame=analogRead(pinFlame);

//PRINT TO SERIAL
Serial.print("Nilai :");
Serial.print(bacaFlame);
Serial.println();
delay(100);

}
