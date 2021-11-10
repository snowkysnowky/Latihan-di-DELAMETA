int tombol1=2,tombol2=3,R=5,Y=6;
void setup() {
  // put your setup code here, to run once:
pinMode(tombol1,INPUT);
pinMode(tombol2,INPUT);
pinMode(R,OUTPUT);
pinMode(Y,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int bacaTombol1=digitalRead(tombol1);
int bacaTombol2=digitalRead(tombol2);
if (bacaTombol1==1 and bacaTombol2==1){
  digitalWrite(R,HIGH);

}
else {
  digitalWrite(R,LOW);

}
}
