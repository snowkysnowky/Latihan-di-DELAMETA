//INISIALISASI
int Red=PC13;
int Green=PC15;
int Yellow=PC14;
int Button1=PA1;
int Button2=PA2;
int Button3=PA3;

void setup() {

Serial.begin(9600);
pinMode(Red,OUTPUT);
pinMode(Green,OUTPUT);
pinMode(Yellow,OUTPUT);
pinMode(Button1,INPUT);
pinMode(Button2,INPUT);
pinMode(Button3,INPUT);
}

void loop() {
//BACA DATA
  int bacaButton1=digitalRead(Button1);
  int bacaButton2=digitalRead(Button2);
  int bacaButton3=digitalRead(Button3);

//PRINT TO SERIAL
Serial.print("Button1 :");Serial.print(bacaButton1);
Serial.print(" - Button2 :");Serial.print(bacaButton2);
Serial.print(" - Button3 :");Serial.print(bacaButton3);
Serial.println();

//LOGIKA PROGRAM
  if (bacaButton1==1){
    digitalWrite(Red,HIGH);
  }
  else{
    digitalWrite(Red,LOW);
  }
  if (bacaButton2==1){
    digitalWrite(Yellow,HIGH);
  }
  else{
    digitalWrite(Yellow,LOW);
  }
    if (bacaButton3==1){
    digitalWrite(Green,HIGH);
  }
  else{
    digitalWrite(Green,LOW);
  }

}
