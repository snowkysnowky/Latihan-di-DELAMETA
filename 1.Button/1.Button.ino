int tombol1=2,R=5,tombol2=3,tombol3=4,Y=6,G=7;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int bacaTombol1=digitalRead(tombol1);
int bacaTombol2=digitalRead(tombol2);
int bacaTombol3=digitalRead(tombol3);



if(bacaTombol1==1){
 // Serial.println("Kondisi tombol1 :"+String(bacaTombol1));
digitalWrite(R,HIGH);

}
else if(bacaTombol2==1){
  //Serial.println("Kondisi tombol2 :"+String(bacaTombol2));
digitalWrite(Y,HIGH);
}
else if(bacaTombol3==1){
  //Serial.println("Kondisi tombol3 :"+String(bacaTombol3));
digitalWrite(G,HIGH);
}

else{
digitalWrite(R,LOW);
digitalWrite(Y,LOW);
digitalWrite(G,LOW);
}
  Serial.println("Kondisi tombol1 :"+String(bacaTombol1));

  Serial.println("Kondisi tombol2 :"+String(bacaTombol2));

  Serial.println("Kondisi tombol3 :"+String(bacaTombol3));
    Serial.println();
    delay(200);
}
