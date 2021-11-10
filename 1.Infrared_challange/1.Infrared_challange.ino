//INISIALISASI
int tombol1=2,R=5,Y=6,G=7,kunci1=0,sensorIR=3;  //MENGUBAH ALIAS

void setup() {
 
  pinMode(tombol1,INPUT);
  pinMode(sensorIR,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  Serial.begin(9600);
  digitalWrite(R,HIGH);
  Serial.print("ON");
}

void loop() {
// Baca Data/Sensor

int bacaTombol1=digitalRead(tombol1);
int bacaIR=digitalRead(sensorIR);

//PRINT KE SERIAL
Serial.print("TOMBOL :");
Serial.print(bacaTombol1);
Serial.print(" | Sensor :");
Serial.print(bacaIR);
Serial.print(" | Flag :");
Serial.print(kunci1);
Serial.println();

//Logika Untuk Tombol
if (bacaTombol1==1 and kunci1==0){
  digitalWrite(R,LOW);
  digitalWrite(Y,HIGH);
  delay(500);
  digitalWrite(Y,LOW);
  digitalWrite(G,HIGH);
  Serial.println();
  Serial.print("SELAMAT DATANG,SLAHKAN AMBIL TIKET");
  Serial.println();
  Serial.print("PALANG DIBUKA");
  kunci1=1;
}

//Logika Untuk Infrared
if(bacaIR==0 and kunci1==1){
  digitalWrite(G,LOW);
  Serial.println();
  Serial.print("PALANG DITUTUP");
  kunci1=0;
  delay(200);
  digitalWrite(R,HIGH);
}
else{}
}
