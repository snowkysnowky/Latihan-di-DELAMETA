int tombol1=2,R=5,Y=6;
void setup() {
  // put your setup code here, to run once:
pinMode(tombol1,INPUT);
pinMode(R,OUTPUT);
pinMode(Y,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int bacaTombol1=digitalRead(tombol1);
if (bacaTombol1==1){
  digitalWrite(R,HIGH);
  digitalWrite(Y,HIGH);
}
else {
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
}
}
