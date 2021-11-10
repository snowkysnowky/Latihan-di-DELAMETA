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
int lampu1=digitalRead(R);
int lampu2=digitalRead(Y);
int lampu3=digitalRead(G);

if (bacaTombol1==1 and lampu1==0)
{
  digitalWrite(R,HIGH);
  delay(200);
}
if (bacaTombol1==1 and lampu1==1)
{
  digitalWrite(R,LOW);
  delay(200);
}
if (bacaTombol2==1 and lampu2==0)
{
  digitalWrite(Y,HIGH);
  delay(200);
}
if (bacaTombol2==1 and lampu2==1)
{
  digitalWrite(Y,LOW);
  delay(200);
}
if (bacaTombol3==1 and lampu3==0)
{
  digitalWrite(G,HIGH);
  delay(200);
}
if (bacaTombol3==1 and lampu3==1)
{
  digitalWrite(G,LOW);
  delay(200);
}
else{}
}
