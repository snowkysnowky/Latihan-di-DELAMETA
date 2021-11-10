//INISIALISASI
int pinLDR=A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int bacaLDR=analogRead(pinLDR);

//PRINT TO SERIAL
Serial.print("Nilai :");
Serial.print(bacaLDR);
Serial.println();
}
