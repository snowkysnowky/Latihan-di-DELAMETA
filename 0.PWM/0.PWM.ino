
void setup() {
  Serial.begin(9600);
  for(float i=5; i<=7; i++){
pinMode(i,OUTPUT);
  }
}

void loop() {
  for(float i=0; i<=255; i++)
  {
analogWrite(5,i);
//float hasil=map(i,0,255,0,5);
float hasil=(5.0/255.0)*i;
Serial.print("DATA :"+String(hasil)+" Volt");
Serial.println();
delay(100);

  }
  {
  for(float i=255; i>=0; i--)
  {
analogWrite(5,i);
//float hasil=map(i,0,255,0,5);
float hasil=(5.0/255.0)*i;
Serial.print("DATA :"+String(hasil)+" Volt");
Serial.println();
delay(100);
  }}  }
