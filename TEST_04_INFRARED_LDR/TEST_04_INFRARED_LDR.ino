//INISIALISASI
int SensorInfrared=PA0; //INFRARED
int SensorLDR=PA1;      //LDR
int Red=PA6;            //LAMPU MERAH
int Yellow=PA7;         //LAMPU KUNING
int Green=PB0;          //LAMPU HIJAU
int kunci=0;            //FLAG


void setup() {

Serial.begin(9600);
pinMode(SensorInfrared,INPUT);
pinMode(SensorLDR,INPUT);
pinMode(Red,OUTPUT);
pinMode(Yellow,OUTPUT);
pinMode(Green,OUTPUT);


}

void loop() {
//BACA DATA ATAU SENSOR
 int bacaInfrared=digitalRead(SensorInfrared);
 int bacaLDR=analogRead(SensorLDR);
bacaLDR=map(bacaLDR,100,4095,0,255);

//PRINT TO SERIAL
 Serial.print("LDR :");
 Serial.print(bacaLDR);
 Serial.println();
 Serial.print("Infrared :");
 Serial.print(bacaInfrared);
 Serial.println();

//LOGIKA PROGRAM

//INFRARED
if (bacaInfrared==0 && kunci==0){
 kunci=1;
  delay(200);
}
else if (bacaInfrared==0 && kunci==1){
     digitalWrite(Red,LOW);
    digitalWrite(Yellow,LOW);
    digitalWrite(Green,LOW);
    kunci=0;
    delay(200);

//LDR
}
 else if(bacaLDR>201 && kunci==1){
    digitalWrite(Red,HIGH);
    digitalWrite(Yellow,LOW);
    digitalWrite(Green,LOW);
    Serial.println("GELAP");
  }
 else  if(bacaLDR<=200 && bacaLDR>=51 && kunci==1){
    digitalWrite(Red,LOW);
    digitalWrite(Yellow,HIGH);
    digitalWrite(Green,LOW);
    Serial.println("REDUP");
    
  }
 else  if(bacaLDR<50 && kunci==1){
    digitalWrite(Red,LOW);
    digitalWrite(Yellow,LOW);
    digitalWrite(Green,HIGH);
    Serial.println("TERANG");
  }
}
