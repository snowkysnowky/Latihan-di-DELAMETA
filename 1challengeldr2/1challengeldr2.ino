//INISIALISASI
int pinLDR=A0;
int pinR=5;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pinR,OUTPUT);
}

void loop() {
  //BACA DATA 
int bacaLDR=analogRead(pinLDR);
bacaLDR=map(bacaLDR,17,1023,0,255);

//PRINT TO SERIAL
Serial.print("Nilai :");
Serial.print(bacaLDR);
Serial.println();

//
analogWrite(pinR,bacaLDR);
}
