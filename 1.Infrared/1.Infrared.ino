int tombol1=2,R=5,Y=6,G=7,kunci1=0,kunci2=0,sensorIR=3;

void setup() {
  // put your setup code here, to run once:
  pinMode(tombol1,INPUT);
  pinMode(sensorIR,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int bacaTombol1=digitalRead(tombol1);
int bacaIR=digitalRead(sensorIR);


Serial.print("Tombol :");
Serial.print(bacaTombol1);
Serial.print(" | Sensor IR :");
Serial.print(bacaIR);
Serial.println();


}
