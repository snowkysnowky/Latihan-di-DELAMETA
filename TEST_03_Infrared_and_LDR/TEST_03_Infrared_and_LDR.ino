//INISIALISASI
int SensorLDR=PA0;
int SensorInfrared=PA1;
int Red=PA6;
int Yellow=PA7;
int Green=PB0;
int kunci=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Red,OUTPUT);
pinMode(Yellow,OUTPUT);
pinMode(Green,OUTPUT);
pinMode(SensorInfrared,INPUT);
pinMode(SensorLDR,INPUT);
}

void loop() {
  //BACA DATA/SENSOR

int bacaLDR=analogRead(SensorLDR);
int bacaInfrared=digitalRead(SensorInfrared);
bacaLDR=map(bacaLDR,110,4095,0,255);

//PRINT TO SERIAL
Serial.print(bacaLDR);
Serial.println();


//LOGIKA PROGRAM
analogWrite(Red,bacaLDR);

if (bacaInfrared==0 && kunci==0){
  digitalWrite(Yellow,HIGH);
  delay(300);
  kunci=1;
}
else if(bacaInfrared==0 && kunci==1){
  digitalWrite(Yellow,LOW);
  delay(300);
  kunci=0;
  }
}
