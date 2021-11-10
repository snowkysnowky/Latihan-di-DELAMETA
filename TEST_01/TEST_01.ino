//IINISIALISASI
int Daffa_tombol1=PA7;
int Daffa_tombol2=PA6;
int Daffa_tombol3=PA5;
int Daffa_lampu1=PC13;
int Daffa_lampu2=PC14;
int Daffa_lampu3=PC15;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Daffa_tombol1,INPUT);
pinMode(Daffa_tombol2,INPUT);
pinMode(Daffa_tombol3,INPUT);
pinMode(Daffa_lampu1,OUTPUT);
pinMode(Daffa_lampu2,OUTPUT);
pinMode(Daffa_lampu3,OUTPUT);
}

void loop() {
  //BACA DATA
int Daffa_bacaTombol1=digitalRead(Daffa_tombol1);
int Daffa_bacaTombol2=digitalRead(Daffa_tombol2);
int Daffa_bacaTombol3=digitalRead(Daffa_tombol3);

//PRINT TO SERIAL
Serial.print("T1 :");Serial.print(Daffa_bacaTombol1);
Serial.print(" - T2 :");Serial.print(Daffa_bacaTombol2);
Serial.print(" - T3 :");Serial.print(Daffa_bacaTombol3);
Serial.println();

//LOGIKA PROGRAM
if (Daffa_bacaTombol1==1){
  digitalWrite(Daffa_lampu1,HIGH);
}
else {
  digitalWrite(Daffa_lampu1,LOW);
}
if (Daffa_bacaTombol2==1){
  digitalWrite(Daffa_lampu2,HIGH);
}
else {
  digitalWrite(Daffa_lampu2,LOW);
}
if (Daffa_bacaTombol3==1){
  digitalWrite(Daffa_lampu3,HIGH);
}
else {
  digitalWrite(Daffa_lampu3,LOW);
}

}
