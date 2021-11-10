#include<OneWire.h>
#include<DallasTemperature.h>

//INISIALISASI
int sensorSuhu=2;
int buzz=3;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

void setup() {
//
  Serial.begin(115200);
  sensors.begin();
  pinMode(buzz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sensors.requestTemperatures();
float bacaSuhu=sensors.getTempCByIndex(0);

//PRINT TO SERIAL
  Serial.print("Data suhu yang terbaca pada bus 1(index 0):");
  Serial.print(bacaSuhu);
  Serial.println(" C");

if(bacaSuhu>=30){
  digitalWrite(buzz,HIGH);
  delay(100);
  digitalWrite(buzz,LOW);
  delay(100);
}
else{
 
}
}
