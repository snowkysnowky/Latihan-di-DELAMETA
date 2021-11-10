//IINISIALISASI
int Daffa_tombol1=PA1;
int Daffa_tombol2=PA2;
int Daffa_tombol3=PA3;
int Daffa_lampu1=PC13;
int Daffa_lampu2=PC14;
int Daffa_lampu3=PC15;
int Daffa_kunci1=0;
int Daffa_kunci2=0;
int Daffa_kunci3=0;

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
if (Daffa_bacaTombol1==1 && Daffa_kunci1==0){
  digitalWrite(Daffa_lampu1,HIGH);
  Serial.println("LAMPU1 ON"); 
  Daffa_kunci1=1;
  delay(200);
}
else if(Daffa_bacaTombol1==1 && Daffa_kunci1==1){
  digitalWrite(Daffa_lampu1,LOW);
  Serial.println("LAMPU1 OFF"); 
  Daffa_kunci1=0;
  delay(200);
}
else if (Daffa_bacaTombol2==1 && Daffa_kunci2==0){
  digitalWrite(Daffa_lampu2,HIGH);
  Serial.println("LAMPU2 ON"); 
  Daffa_kunci2=1;
  delay(200);
}
else if (Daffa_bacaTombol2==1 && Daffa_kunci2==1){
  digitalWrite(Daffa_lampu2,LOW);
  Serial.println("LAMPU2 ON"); 
  Daffa_kunci2=0;
  delay(200);
}
else if (Daffa_bacaTombol3==1 && Daffa_kunci3==0){
  digitalWrite(Daffa_lampu3,HIGH);
  Serial.println("LAMPU2 OFF"); 
  Daffa_kunci3=1;
  delay(200);
}
else if(Daffa_bacaTombol3==1 && Daffa_kunci3==1){
  digitalWrite(Daffa_lampu3,LOW);
  Serial.println("LAMPU1 ON"); 
  Daffa_kunci3=0;
  delay(200);
}

}
